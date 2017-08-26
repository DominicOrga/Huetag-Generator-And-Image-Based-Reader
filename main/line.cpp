#pragma once

#include "line.h"

namespace orga {

	Line::Line() {}

	Line::Line(cv::Point* startPoint, cv::Point* endPoint) {
		setPoints(startPoint, endPoint);
	}

	cv::Point Line::getSlicePointInLine(float slicePosition, int noOfSlices) {
		float d = length * (slicePosition / (noOfSlices + 1));

		float x = startPoint.x + (d / length) * (endPoint.x - startPoint.x);
		float y = startPoint.y + (d / length) * (endPoint.y - startPoint.y);

		return cv::Point(x, y);
	}

	void Line::setPoints(cv::Point* startPoint, cv::Point* endPoint) {
		this->startPoint = cv::Point(*startPoint);
		this->endPoint = cv::Point(*endPoint);

		length = sqrtf(powf(startPoint->x - endPoint->x, 2) + powf(startPoint->y - endPoint->x, 2));

		m = (endPoint->y - startPoint->y * 1.f) / (endPoint->x - startPoint->x);
		b = startPoint->y - m * startPoint->x;
	}


	cv::Point getIntersection(Line L1, Line L2) {
		float x, y;

		if (isinf(L1.m)) {
			x = L1.startPoint.x;
			y = L2.m * x + L2.b;
		}
		else if (isinf(L2.m)) {
			x = L2.startPoint.x;
			y = L1.m * x + L1.b;
		}
		else {
			x = (L2.b - L1.b) / (L1.m - L2.m);
			y = L1.m * x + L1.b;
		}

		return cv::Point(x, y);
	}

	int getQuadrant(cv::Point* p1, cv::Point* p2) {
		int x = p2->x - p1->x;
		int y = p2->y - p1->y;

		if (x >= 0 && y >= 0) {
			return 1;
		}
		else if (x < 0 && y >= 0) {
			return 2;
		}
		else if (x < 0 && y < 0) {
			return 3;
		}
		else {
			return 4;
		}
	}
}