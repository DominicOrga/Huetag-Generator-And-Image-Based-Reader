#include "huetagwriterwindow.h"

#include "qfiledialog.h"

#include "global.h"
#include "huetagwriter.h"

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"

huetagwriterwindow::huetagwriterwindow(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	warningLabel->hide();
	saveImageButton->hide();

	markerIdLabel->clear();
	mainBitsLabel->clear();
	parityBitsLabel->clear();

	connect(closeButton, SIGNAL(pressed()), this, SLOT(close()));
	connect(idLineEdit, SIGNAL(returnPressed()), this, SLOT(generateMarker()));
	connect(generateMarkerButton, SIGNAL(pressed()), this, SLOT(generateMarker()));
	connect(saveImageButton, SIGNAL(pressed()), this, SLOT(saveMarkerImage()));

	markerImage_.fill(qRgb(0, 0, 0));
}

bool huetagwriterwindow::isInputValid() {
	QString input = idLineEdit->text();

	QRegExp regex("\\d*");
	
	if (!regex.exactMatch(input)) {
		warningLabel->show();
		warningLabel->setText("Only unsigned integer values allowed.");
		return false;
	}

	int inputToInt = input.toInt();

	if (inputToInt < 1 || inputToInt > 16777215) {
		warningLabel->show();
		warningLabel->setText("Value must be within given ID range.");
		return false;
	}

	warningLabel->hide();
	return true;
}

void huetagwriterwindow::drawMarker(std::vector<char>& Tx) {
	int index = 0;

	int row = 2;
	int col = 2;

	paintMarkerDataCell(row, col, orga::identifyDataCellColorViaBitData(Tx, index));
	index++;

	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= i; j++) {
			col += (i % 2 == 0) ? 1 : -1;

			if (col < 0) goto terminate;

			paintMarkerDataCell(row, col, orga::identifyDataCellColorViaBitData(Tx, index));
			index++;
		}

		for (int j = 0; j <= i; j++) {
			row += (i % 2 == 0) ? 1 : -1;

			if (row < 0) goto terminate;
			
			paintMarkerDataCell(row, col, orga::identifyDataCellColorViaBitData(Tx, index));
			index++;
		}

		continue;

	terminate:
		break;
	}

	markerImageLabel->setPixmap(QPixmap::fromImage(markerImage_));
}

void huetagwriterwindow::paintMarkerDataCell(int row, int col, QRgb color) {
	int x1 = 40 + 80 * col;
	int y1 = 40 + 80 * row;
	int x2 = x1 + 80;
	int y2 = y1 + 80;

	for (int x = x1; x < x2; x++) {
		for (int y = y1; y < y2; y++) {
			markerImage_.setPixel(x, y, color);
		}
	}
}



//===========================SLOTS===============================//

void huetagwriterwindow::close() {
	this->hide();
}

void huetagwriterwindow::generateMarker() {

	if (!isInputValid()) {
		return;
	}

	saveImageButton->show();

	int id = idLineEdit->text().toInt();

	std::vector<char> mainBits;
	std::vector<char> Tx;

	orga::generateMarkerData(id, OUT mainBits, OUT Tx);

	markerIdLabel->setText(QString::number(id));
		
	// Display main bits.
	mainBitsLabel->clear();
	for (int i = 0; i < mainBits.size() - 1; i += 2) {
		QString str;

		str.append(QString::number(mainBits.at(i)));
		str.append(QString::number(mainBits.at(i + 1)));

		mainBitsLabel->setText(mainBitsLabel->text() + str + " ");
	}

	// Display parity bits.
	parityBitsLabel->clear();
	for (int i = 32; i < Tx.size() - 1; i += 2) {
		QString str;

		str.append(QString::number(Tx.at(i)));
		str.append(QString::number(Tx.at(i + 1)));

		parityBitsLabel->setText(parityBitsLabel->text() + str + " ");
	}

	drawMarker(Tx);
}

void huetagwriterwindow::saveMarkerImage() {

	QString imagePath = QFileDialog::getSaveFileName(
		this,
		tr("Save File"),
		"huetag-marker-" + markerIdLabel->text(),
		tr("PNG (*.png);;JPEG (*.jpg *.jpeg)")
	);

	markerImage_.save(imagePath);
}