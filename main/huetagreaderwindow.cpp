#include <windows.h>
#include <string.h>

#include "huetagreaderwindow.h"
#include "huetagwriterwindow.h"
#include "qfiledialog.h"
#include "qdebug.h"

#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"

#include "huetagreader.h"
#include "line.h"

#include "global.h"

huetagreaderwindow::huetagreaderwindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.ImagePreview->hide();

	QObject::connect(ui.BrowseButton, SIGNAL(released()), this, SLOT(browseImage()));
	QObject::connect(ui.BinaryThreshSlider, SIGNAL(valueChanged(int)), this, SLOT(updateBinaryThreshold(int)));
	QObject::connect(ui.ContourAreaThresholdSlider, SIGNAL(valueChanged(int)), this, SLOT(updateContourAreaMinThreshold(int)));
	QObject::connect(ui.ContourAreaMaxThreshSlider, SIGNAL(valueChanged(int)), this, SLOT(updateContourAreaMaxThreshold(int)));
	QObject::connect(ui.GaussianKernelSlider, SIGNAL(valueChanged(int)), this, SLOT(updateGaussianKernelSize(int)));

	QObject::connect(ui.BlurImagePreview, SIGNAL(pressed()), this, SLOT(onBlurImagePressed()));
	QObject::connect(ui.BlurImagePreview, SIGNAL(released()), this, SLOT(hideImagePreview()));
	QObject::connect(ui.BinaryThreshImagePreview, SIGNAL(pressed()), this, SLOT(onBinaryThreshImagePressed()));
	QObject::connect(ui.BinaryThreshImagePreview, SIGNAL(released()), this, SLOT(hideImagePreview()));
	QObject::connect(ui.ContoursImagePreview, SIGNAL(pressed()), this, SLOT(onContourImagePressed()));
	QObject::connect(ui.ContoursImagePreview, SIGNAL(released()), this, SLOT(hideImagePreview()));
	QObject::connect(ui.DataCellCoordImagePreview, SIGNAL(pressed()), this, SLOT(onDataCellCoordImagePressed()));
	QObject::connect(ui.DataCellCoordImagePreview, SIGNAL(released()), this, SLOT(hideImagePreview()));

	QObject::connect(ui.ManageMarkerButton, SIGNAL(pressed()), this, SLOT(openMarkerManager()));
	QObject::connect(ui.UpdateButton, SIGNAL(pressed()), this, SLOT(updateDecodedMarkerImage()));
	QObject::connect(ui.LogButton, SIGNAL(pressed()), this, SLOT(openLogFile()));

	ui.UpdateButton->hide();

	qDebug() << "Quad: " << orga::getQuadrant(new cv::Point(20,20), new cv::Point(5, 5));
}

void huetagreaderwindow::updateBinaryImage()
{
	cv::Mat binaryImage;
	cv::threshold(*_cvImageGrayscale, binaryImage, _binaryThreshold, 255, cv::THRESH_BINARY);
	//cv::Canny(*_cvImageGrayscale, cannyImage, _cannyMinThreshold, _cannyMaxThreshold, _cannyApertureSize);

	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));

	cv::erode(binaryImage, binaryImage, kernel);
	cv::erode(binaryImage, binaryImage, kernel);

	cv::dilate(binaryImage, binaryImage, kernel);
	cv::dilate(binaryImage, binaryImage, kernel);

	// release _cvImageCanny memory first before assigning a new image.
	if (_cvImageBinary)
		delete _cvImageBinary;

	_cvImageBinary = new cv::Mat(binaryImage);
	

	QImage qImage = QImage(
		binaryImage.data,
		binaryImage.cols,
		binaryImage.rows,
		static_cast<int>(binaryImage.step),
		QImage::Format_Grayscale8
	);

	ui.BinaryThreshImageView->setPixmap(QPixmap::fromImage(qImage));
}

void huetagreaderwindow::updateContourImage()
{
	// Release memory held by _squareContours.
	_squareContours.clear();
	std::vector<std::vector<cv::Point*>*>().swap(_squareContours);

	std::vector<std::vector<cv::Point>> contours;
	
	cv::findContours(*_cvImageBinary, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);

	cv::Mat contourImage = cv::Mat::zeros(_cvImageBinary->size(), CV_8UC1);
	
	int max = contours.size();
	// incrementor is set to 2, since findContours always return two contour of the same shape, the inner and outer.
	for (int i = 0; i < max; i++)
	{
		std::vector<cv::Point> approxSquare;
		cv::approxPolyDP(contours.at(i), OUT approxSquare, cv::arcLength(cv::Mat(contours.at(i)), true) * 0.01f, true);

		float area = cv::contourArea(approxSquare);

		if (approxSquare.size() == 4 && area > powf(10, _contourAreaMinThreshold) && area < powf(10, _contourAreaMaxThreshold))
		{
			cv::Point P1 = approxSquare.at(0);
			cv::Point P2 = approxSquare.at(1);
			cv::Point P3 = approxSquare.at(2);
			cv::Point P4 = approxSquare.at(3);

			cv::line(contourImage, P1, P2, cv::Scalar(255, 255, 255));
			cv::line(contourImage, P2, P3, cv::Scalar(255, 255, 255));
			cv::line(contourImage, P3, P4, cv::Scalar(255, 255, 255));
			cv::line(contourImage, P4, P1, cv::Scalar(255, 255, 255));

			// Transfer all square contours to the heap memory.
			std::vector<cv::Point*>* squareContour = new std::vector<cv::Point*>();

			squareContour->push_back(new cv::Point(approxSquare.at(0)));
			squareContour->push_back(new cv::Point(approxSquare.at(1)));
			squareContour->push_back(new cv::Point(approxSquare.at(2)));
			squareContour->push_back(new cv::Point(approxSquare.at(3)));

			_squareContours.push_back(squareContour);
		}
	}

	cv::Mat convertedImage;
	cv::cvtColor(contourImage, OUT convertedImage, CV_GRAY2RGB);

	QImage qImage = QImage(
		convertedImage.data,
		convertedImage.cols,
		convertedImage.rows,
		static_cast<int>(convertedImage.step),
		QImage::Format_RGB888
	);

	ui.ContoursImageView->setPixmap(QPixmap::fromImage(qImage));
}

void huetagreaderwindow::updateBlurImage() {
	cv::Mat blurImage;
	cv::blur(*_cvImageOriginal, blurImage, cv::Size(_gaussianKernelSize, _gaussianKernelSize));

	// release _cvImageCanny memory first before assigning a new image.
	if (_cvImageBlur)
		delete _cvImageBlur;

	_cvImageBlur = new cv::Mat(blurImage);

	QImage qImage = QImage(
		blurImage.data,
		blurImage.cols,
		blurImage.rows,
		static_cast<int>(blurImage.step),
		QImage::Format_RGB888
	);

	ui.BlurImageView->setPixmap(QPixmap::fromImage(qImage));
}

void huetagreaderwindow::updateDataCellCoordImage()
{
	_dataCellCoordinates.clear();
	std::vector<std::vector<cv::Point*>*>().swap(_dataCellCoordinates);

	cv::Mat image_temp;
	_cvImageOriginal->copyTo(image_temp);

	int max = _squareContours.size();
	for (int i = 0; i < max; i++)
	{
		std::vector<cv::Point*>* squareContour = _squareContours.at(i);

		std::vector<cv::Point> dataCellPoints;

		orga::extractDataCellPoints(squareContour, OUT dataCellPoints, 6);

		std::vector<cv::Point*>* copy = new std::vector<cv::Point*>();
		for (int j = 0; j < dataCellPoints.size(); j++)
		{
			copy->push_back(new cv::Point(dataCellPoints.at(j)));

			cv::circle(image_temp, dataCellPoints.at(j), 2, cv::Scalar(255, 255, 255), 2);
		}

		_dataCellCoordinates.push_back(copy);
	}

	QImage qImage = QImage(
		image_temp.data,
		image_temp.cols,
		image_temp.rows,
		static_cast<int>(image_temp.step),
		QImage::Format_RGB888
	);

	ui.DataCellCoordImageView->setPixmap(QPixmap::fromImage(qImage));
}

void huetagreaderwindow::setLabel(cv::Mat& image, const std::string label, const cv::Point & location, double scale) {
	int fontface = cv::FONT_HERSHEY_SIMPLEX;
	int thickness = 1;
	int baseline = 0;

	cv::Size text = cv::getTextSize(label, fontface, scale, thickness, &baseline);
	cv::rectangle(image, location + cv::Point(0, baseline), location + cv::Point(text.width, -text.height), CV_RGB(0, 0, 0), CV_FILLED);
	cv::putText(image, label, location, fontface, scale, CV_RGB(255, 255, 255), thickness, 8);
}

//------------------------------ Slots --------------------------------------//
void huetagreaderwindow::browseImage()
{
	QFileDialog dialog;
	dialog.setNameFilter("Image (*.jpg)");

	if (dialog.exec())
	{
		QStringList files = dialog.selectedFiles();
		imagePath = files.at(0);
		
		ui.ImagePathText->setText(imagePath);

		cv::Mat image = cv::imread(imagePath.toLocal8Bit().constData());

		if (image.empty()) return;

		// resize image to 640x480, the same size of the webcam capture.
		// The larger the image, the more computational intensive the image processing will be.
		cv::Mat resizedImage;
		cv::resize(image, resizedImage, cv::Size(640, 480));

		cv::Mat rgbImage;
		cv::cvtColor(resizedImage, rgbImage, CV_BGR2RGB);

		// release _cvImageOriginal memory first before assigning a new image.
		if (_cvImageOriginal)
			delete _cvImageOriginal;

		_cvImageOriginal = new cv::Mat(rgbImage);

		cv::Mat grayscaleImage;
		cv::cvtColor(rgbImage, grayscaleImage, CV_RGB2GRAY);

		// release _cvImageGrayscale memory first before assigning a new image.
		if (_cvImageGrayscale)
			delete _cvImageGrayscale;

		_cvImageGrayscale = new cv::Mat(grayscaleImage);

		updateBlurImage();
		updateBinaryImage();
		updateContourImage();
		updateDataCellCoordImage();

		ui.MainImageView->clear();
		ui.UpdateButton->show();
	}
}

void huetagreaderwindow::updateDecodedMarkerImage()
{
	cv::Mat image_temp;
	_cvImageOriginal->copyTo(image_temp);

	orga::_logger.open();
	
	int iMax = _dataCellCoordinates.size();
	for (int i = 0; i < iMax; i++)
	{
		orga::_logger.writeln("=======================================================================");
		orga::_logger.writeln("Marker Candidate " + QString::number(i + 1));

		std::vector<cv::Point*>* dataCellCoords = _dataCellCoordinates.at(i);
		std::vector<cv::Point*>* squareContour = _squareContours.at(i);

		int id = orga::identifyMarkerID(_cvImageBlur, dataCellCoords);

		cv::Point* p1 = squareContour->at(0);
		cv::Point* p2 = squareContour->at(1);
		cv::Point* p3 = squareContour->at(2);
		cv::Point* p4 = squareContour->at(3);

		cv::Point intersect = orga::getIntersection(orga::Line(p1, p3), orga::Line(p2, p4));

		if (id != -1) 
		{
			setLabel(image_temp, cv::String(std::to_string(id)), intersect);
		}
	}

	orga::_logger.close();

	QImage qImage = QImage(
		image_temp.data,
		image_temp.cols,
		image_temp.rows,
		static_cast<int>(image_temp.step),
		QImage::Format_RGB888
	);

	ui.MainImageView->setPixmap(QPixmap::fromImage(qImage));
	ui.UpdateButton->hide();
}

void huetagreaderwindow::updateBinaryThreshold(int value)
{
	_binaryThreshold = value;

	if (_cvImageOriginal)
	{
		updateBinaryImage();
		updateContourImage();
		updateDataCellCoordImage();
		ui.UpdateButton->show();
	}
}

void huetagreaderwindow::updateContourAreaMinThreshold(int value)
{
	_contourAreaMinThreshold = value / 20.f;

	ui.ContourAreaThresholdText->setText(QString::number(_contourAreaMinThreshold));

	if (_cvImageOriginal)
	{
		updateContourImage();
		updateDataCellCoordImage();
		ui.UpdateButton->show();
	}
}

void huetagreaderwindow::updateContourAreaMaxThreshold(int value)
{
	_contourAreaMaxThreshold = value / 20.f;

	ui.ContourAreaMaxThreshText->setText(QString::number(_contourAreaMaxThreshold));

	if (_cvImageOriginal)
	{
		updateContourImage();
		updateDataCellCoordImage();
		ui.UpdateButton->show();
	}
}

void huetagreaderwindow::updateGaussianKernelSize(int value) {
	_gaussianKernelSize = value + value - 1;

	ui.GaussianKernelText->setText(QString::number(_gaussianKernelSize));

	if (_cvImageOriginal) {
		updateBlurImage();
		ui.UpdateButton->show();
	}
}

void huetagreaderwindow::openMarkerManager()
{
	huetagwriterwindow dialog;
	dialog.setModal(true);	// Disables the main window until the dialog is closed.
	dialog.exec();
}

void huetagreaderwindow::openLogFile() {
	orga::_logger.openLogFile();
}

void huetagreaderwindow::onBlurImagePressed()
{
	const QPixmap* pixmap = ui.BlurImageView->pixmap();

	if (pixmap)
	{
		ui.ImagePreview->setPixmap(QPixmap::fromImage(pixmap->toImage()));
		ui.ImagePreview->show();
	}
}

void huetagreaderwindow::onBinaryThreshImagePressed()
{
	const QPixmap* pixmap = ui.BinaryThreshImageView->pixmap();

	if (pixmap)
	{
		ui.ImagePreview->setPixmap(QPixmap::fromImage(pixmap->toImage()));
		ui.ImagePreview->show();
	}
}

void huetagreaderwindow::onContourImagePressed()
{
	const QPixmap* pixmap = ui.ContoursImageView->pixmap();

	if (pixmap)
	{
		ui.ImagePreview->setPixmap(QPixmap::fromImage(pixmap->toImage()));
		ui.ImagePreview->show();
	}
}

void huetagreaderwindow::onDataCellCoordImagePressed()
{
	const QPixmap* pixmap = ui.DataCellCoordImageView->pixmap();

	if (pixmap)
	{
		ui.ImagePreview->setPixmap(QPixmap::fromImage(pixmap->toImage()));
		ui.ImagePreview->show();
	}
}

void huetagreaderwindow::hideImagePreview()
{
	ui.ImagePreview->hide();
}


