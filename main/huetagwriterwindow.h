#pragma once

#ifndef OUT
#define OUT
#endif

#include <QDialog>
#include "ui_huetagwriterwindow.h"

class huetagwriterwindow : public QDialog, public Ui::huetagwriterwindow
{
	Q_OBJECT

public:
	huetagwriterwindow(QWidget *parent = Q_NULLPTR);

private:
	/// <summary> 
	/// Checks if the marker ID entered is an unsigned integer between 1 and 67108864. 
	/// </summary>
	bool isInputValid();

	/// <summary>
	/// Draw the marker data.
	/// </summary>
	/// <param name='Tx'> The 72-bit marker data. </param>
	void drawMarker(std::vector<char>& Tx);

	/// <summary>
	/// Paints the marker data-cell position given by row and col.
	/// </summary>
	/// <param name='row'> The row position of the desired data-cell. </param>
	/// <param name='col'> The column position of the desired data-cell. </param>
	/// <param name='color'> The desired color for the data-cell in RGB. </param>
	void paintMarkerDataCell(int row, int col, QRgb color);


private slots:
	void close();
	void generateMarker();
	void saveMarkerImage();

private:
	QImage markerImage_ = QImage(560, 560, QImage::Format_RGB32);
};
