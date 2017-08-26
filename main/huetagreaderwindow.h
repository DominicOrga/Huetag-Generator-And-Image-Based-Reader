#ifndef huetagreaderwindow_H
#define huetagreaderwindow_H

#include <QtWidgets/QMainWindow>
#include "ui_huetagreaderwindow.h"
#include "opencv2/core.hpp"

namespace cv
{
	class Mat;
}

class QImage;

class huetagreaderwindow : public QMainWindow
{
	Q_OBJECT

public:
	huetagreaderwindow(QWidget *parent = 0);

private:
	Ui::huetagreaderwindowClass ui;

	/// <summary>
	/// Updates the canny image view [2].
	/// </summary>
	void updateBinaryImage();
	
	/// <summary>
	/// Updates the contour image view [3].
	/// </summary>
	void updateContourImage();

	void updateBlurImage();

	/// <summary>
	/// Updates the data cell coordinate image view [4].
	/// </summary>
	void updateDataCellCoordImage();

	void setLabel(cv::Mat& image, const std::string label, const cv::Point & location, double size = 0.75);

private slots:
	void browseImage();
	void updateBinaryThreshold(int value);
	void updateContourAreaMinThreshold(int value);
	void updateContourAreaMaxThreshold(int value);
	void updateGaussianKernelSize(int value);
	void updateDecodedMarkerImage();
	void openMarkerManager();
	void openLogFile();

	void onBlurImagePressed();
	void onBinaryThreshImagePressed();
	void onContourImagePressed();
	void onDataCellCoordImagePressed();	

	void hideImagePreview();

private:
	cv::Mat* _cvImageOriginal = nullptr;
	cv::Mat* _cvImageGrayscale = nullptr;
	cv::Mat* _cvImageBinary = nullptr;
	cv::Mat* _cvImageBlur = nullptr;
	
	int _binaryThreshold = 50;
	float _contourAreaMinThreshold = 2.5f;		// In logarithmic form.
	float _contourAreaMaxThreshold = 5.f;		// In logarithmic form.
	int _gaussianKernelSize = 3;

	std::vector<std::vector<cv::Point*>*> _squareContours;
	std::vector<std::vector<cv::Point*>*> _dataCellCoordinates;

	QString imagePath;
};

#endif // huetagreaderwindow_H
