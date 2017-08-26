#include <Windows.h>

#include "huetagreader.h"
#include "color.h"
#include "line.h"
#include "crc.h"

#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"

#include "qstring.h"
#include "qdebug.h"

#include "global.h"

namespace orga
{
	namespace detail {
		void extractMarkerData(std::vector<orga::Lab>& dataCellLabArray, OUT std::vector<char>& outData) {
		// TODO : The code from delete2 sprital extraction algorithm
		int row;
		int col;

		int rotation = identifyMarkerRotation(dataCellLabArray);

		orga::_logger.writeln("\n**MARKER ROTATION**\n");
		orga::_logger.writeln("Rotation = " + QString::number(rotation));

		orga::Lab redLabRef;
		orga::Lab greenLabRef;
		orga::Lab yellowLabRef;
		orga::Lab blueLabRef;

		switch (rotation) {
		case 0:
			redLabRef = dataCellLabArray.at(20);
			greenLabRef = dataCellLabArray.at(21);
			yellowLabRef = dataCellLabArray.at(15);
			blueLabRef = dataCellLabArray.at(14);
			row = 2;
			col = 2;
			break;
		case 90:
			redLabRef = dataCellLabArray.at(14);
			greenLabRef = dataCellLabArray.at(20);
			yellowLabRef = dataCellLabArray.at(21);
			blueLabRef = dataCellLabArray.at(15);
			row = 2;
			col = 3;
			break;
		case 180:
			redLabRef = dataCellLabArray.at(15);
			greenLabRef = dataCellLabArray.at(14);
			yellowLabRef = dataCellLabArray.at(20);
			blueLabRef = dataCellLabArray.at(21);
			row = 3;
			col = 3;
			break;
		case 270:
			redLabRef = dataCellLabArray.at(21);
			greenLabRef = dataCellLabArray.at(15);
			yellowLabRef = dataCellLabArray.at(14);
			blueLabRef = dataCellLabArray.at(20);
			row = 3;
			col = 2;
			break;
		default:
			return;
		}

		orga::_logger.writeln("\n**MARKER BINARY DATA EXTRACTION**\n");

		orga::_logger.writeln("Red Lab Reference: " + QString::number(redLabRef.L) + " " + QString::number(redLabRef.a) + " " + QString::number(redLabRef.b));
		orga::_logger.writeln("Green Lab Reference: " + QString::number(greenLabRef.L) + " " + QString::number(greenLabRef.a) + " " + QString::number(greenLabRef.b));
		orga::_logger.writeln("Yellow Lab Reference: " + QString::number(yellowLabRef.L) + " " + QString::number(yellowLabRef.a) + " " + QString::number(yellowLabRef.b));
		orga::_logger.writeln("Blue Lab Reference: " + QString::number(blueLabRef.L) + " " + QString::number(blueLabRef.a) + " " + QString::number(blueLabRef.b));

		orga::_logger.writeln("\nNote: SeR = Sample Lab Euclidean Distance from Red Lab Reference.");

		orga::_logger.writeln("\nData-Cell Lab " + QString::number(row * 6 + col) + ": ");
		int c = identifyColor(dataCellLabArray.at(row * 6 + col), redLabRef, greenLabRef, yellowLabRef, blueLabRef);
		switch (c) {
		case 0:
			outData.push_back(0);
			outData.push_back(0);
			break;
		case 1:
			outData.push_back(0);
			outData.push_back(1);
			break;
		case 2:
			outData.push_back(1);
			outData.push_back(0);
			break;
		case 3:
			outData.push_back(1);
			outData.push_back(1);
			break;
		}

		for (int i = 0; i <= 5; i++) {
			for (int j = 0; j <= i; j++) {
				if (i % 2 == 0) {
					switch (rotation) {
					case 0: col++; break;
					case 90: row++; break;
					case 180: col--; break;
					case 270: row--;
					}
				}
				else {
					switch (rotation) {
					case 0: col--; break;
					case 90: row--; break;
					case 180: col++; break;
					case 270: row++;
					}
				}

				if (col < 0 || col > 5 || row < 0 || row > 5) goto terminate;

				orga::_logger.writeln("\nData-Cell Lab " + QString::number(row * 6 + col) + ": ");
				int c = identifyColor(dataCellLabArray.at(row * 6 + col), redLabRef, greenLabRef, yellowLabRef, blueLabRef);
				switch (c) {
				case 0:
					outData.push_back(0);
					outData.push_back(0);
					break;
				case 1:
					outData.push_back(0);
					outData.push_back(1);
					break;
				case 2:
					outData.push_back(1);
					outData.push_back(0);
					break;
				case 3:
					outData.push_back(1);
					outData.push_back(1);
					break;
				}
			}

			for (int j = 0; j <= i; j++) {
				if (i % 2 == 0) {
					switch (rotation) {
					case 0: row++; break;
					case 90: col--; break;
					case 180: row--; break;
					case 270: col++;
					}
				}
				else {
					switch (rotation) {
					case 0: row--; break;
					case 90: col++; break;
					case 180: row++; break;
					case 270: col--;
					}
				}

				orga::_logger.writeln("\nData-Cell Lab " + QString::number(row * 6 + col) + ": ");
				int c = identifyColor(dataCellLabArray.at(row * 6 + col), redLabRef, greenLabRef, yellowLabRef, blueLabRef);
				switch (c) {
				case 0:
					outData.push_back(0);
					outData.push_back(0);
					break;
				case 1:
					outData.push_back(0);
					outData.push_back(1);
					break;
				case 2:
					outData.push_back(1);
					outData.push_back(0);
					break;
				case 3:
					outData.push_back(1);
					outData.push_back(1);
					break;
				}
			}

			continue;

		terminate:
			break;
		}
	}

		void extractDataCellLabColors(cv::Mat* image, std::vector<cv::Point*>* dataCellCoords, OUT std::vector<orga::Lab>& outLabArray) {
		outLabArray.clear();

		orga::_logger.writeln("\n**LAB COLOR EXTRACTION**\n");

		// Iterate through all the quinaryData cell coordinates.
		int iMax = dataCellCoords->size();
		for (int i = 0; i < iMax; i++)
		{
			cv::Point p = *dataCellCoords->at(i);

			// Extract rgb.
			cv::Vec3b color = image->at<cv::Vec3b>(p.y < 0 ? 0 : p.y, p.x < 0 ? 0 : p.x);

			// Convert rgb to Lab.
			orga::RGB rgb{ (float) color[0], (float) color[1], (float) color[2] };
			orga::Lab lab = orga::RGBToLab(rgb);

			outLabArray.push_back(lab);

			orga::_logger.writeln("Lab " +
				QString::number(i) + ": " +
				QString::number(lab.L) + " " +
				QString::number(lab.a) + " " +
				QString::number(lab.b)
			);
		}
	}

		int identifyColor(orga::Lab& lab, orga::Lab& redLabRef, orga::Lab& greenLabRef, orga::Lab& yellowLabRef, orga::Lab& blueLabRef) {

		float rd = eucledianDistance(lab, redLabRef);
		float gd = eucledianDistance(lab, greenLabRef);
		float yd = eucledianDistance(lab, yellowLabRef);
		float bd = eucledianDistance(lab, blueLabRef);

		orga::_logger.writeln("SeR = " + QString::number(rd));
		orga::_logger.writeln("SeG = " + QString::number(gd));
		orga::_logger.writeln("SeY = " + QString::number(yd));
		orga::_logger.writeln("SeB = " + QString::number(bd));

		if (gd <= rd && gd <= yd && gd <= bd) {
			orga::_logger.writeln("quaternary value: 1 (Green)");
			return 1;
		}

		if (bd <= rd && bd <= yd && bd <= gd) {
			orga::_logger.writeln("quaternary value: 3 (Blue)");
			return 3;
		}

		if (rd <= bd && rd <= yd && rd <= gd) {
			orga::_logger.writeln("quaternary value: 0 (Red)");
			return 0;
		}

		orga::_logger.writeln("quaternary value: 2 (Yellow)");
		return 2;
	}

		int identifyMarkerRotation(std::vector<orga::Lab>& labArray) {
			orga::Lab& lab14 = labArray.at(14);
			orga::Lab& lab15 = labArray.at(15);
			orga::Lab& lab20 = labArray.at(20);
			orga::Lab& lab21 = labArray.at(21);

			if (lab15.b >= lab14.b && lab15.b >= lab21.b && lab15.b >= lab20.b) {
				return 0;
			}
			else if (lab21.b >= lab14.b && lab21.b >= lab15.b && lab21.b >= lab20.b) {
				return 90;
			}
			else if (lab20.b >= lab14.b && lab20.b >= lab21.b && lab20.b >= lab21.b) {
				return 180;
			}
			else {
				return 270;
			}
		}

		float eucledianDistance(orga::Lab& lab1, orga::Lab& lab2) {
			return sqrt(pow(lab2.a - lab1.a, 2) + pow(lab2.b - lab1.b, 2));
			//return (fabs(lab2.a - lab1.a) + fabs(lab2.b - lab1.b));
		}

		void deconvolveStaticBits(std::vector<char>& oldData, OUT std::vector<char>& newData) {
			newData.clear();
			newData.assign(oldData.begin() + 8, oldData.end());
		}
	}

	void extractDataCellPoints(std::vector<cv::Point*>* squareContour, OUT std::vector<cv::Point>& outDataCellArray, int matrixSize) {
		cv::Point* p0 = squareContour->at(0);
		cv::Point* p1 = squareContour->at(1);
		cv::Point* p2 = squareContour->at(2);
		cv::Point* p3 = squareContour->at(3);

		Line line1;
		Line line2;
		Line line3;
		Line line4;

		// Determine whether P0->P1 or P0->P3 is clockwise, as the data needs to be extracted in clockwise rotation.
		int A = orga::getQuadrant(p0, p1) - orga::getQuadrant(p1, p3);
		int B = orga::getQuadrant(p0, p3);

		if (A == -1 || A == 3 || 
			(A == -2 && (B == 2 || B == 3)) ||
			(A == 2 && (B == 1 || B == 4))) {
			line1.setPoints(p0, p1);
			line2.setPoints(p1, p2);
			line3.setPoints(p2, p3);
			line4.setPoints(p3, p0);
		}
		else {
			line1.setPoints(p0, p3);
			line2.setPoints(p3, p2);
			line3.setPoints(p2, p1);
			line4.setPoints(p1, p0);
		}

		for (int i = 0; i < matrixSize; i++)
		{
			for (int j = 0; j < matrixSize; j++)
			{
				cv::Point point1 = line1.getSlicePointInLine(j + 1, matrixSize);
				cv::Point point2 = line2.getSlicePointInLine(i + 1, matrixSize);
				cv::Point point3 = line3.getSlicePointInLine(matrixSize - j, matrixSize);
				cv::Point point4 = line4.getSlicePointInLine(matrixSize - i, matrixSize);

				Line line5(&point1, &point3);
				Line line6(&point2, &point4);

				cv::Point intersect = getIntersection(line5, line6);

				outDataCellArray.push_back(intersect);
			}
		}
	}

	int identifyMarkerID(cv::Mat* image, std::vector<cv::Point*>* dataCellCoords)
	{
		// Get Lab value from the data cell coordinates placed within the image.
		std::vector<orga::Lab> labArray;
		detail::extractDataCellLabColors(image, dataCellCoords, OUT labArray);

		// Get marker data binary data.
		std::vector<char> bitData;
		detail::extractMarkerData(labArray, OUT bitData);

		std::vector<char> bitData2;
		detail::deconvolveStaticBits(bitData, OUT  bitData2);

		orga::_logger.writeln("\nMarker Binary Data (No Static Bits):");

		for (int i = 0; i < bitData2.size() - 1; i += 2) {
			int a = bitData2.at(i);
			int b = bitData2.at(i + 1);

			orga::_logger.write(QString::number(a) + QString::number(b) + " ");
		}

		orga::_logger.writeln("\n\n**CRC CHECK**\n");

		std::vector<char> mainBits;
		int result = orga::CRCDeconvolution(orga::generatorKey, bitData2, OUT mainBits);

		// If CRC pass, then return decoded marker id from the binary bits.
		if (result == 0) {
			orga::_logger.writeln("CRC Passed");

			unsigned long long int decimal = 0;
			for (int i = mainBits.size() - 1; i >= 0; i--) {
				decimal += mainBits.at(i) * powf(2, mainBits.size() - 1 - i);
			}

			orga::_logger.writeln("\nDecimal Equivalent = " + QString::number(decimal));
			orga::_logger.writeln("Marker ID (decimal) = " + QString::number(decimal + 1));

			return decimal;
		}
		else {
			orga::_logger.writeln("CRC Failed\n");

			return -1;
		}
	}
}