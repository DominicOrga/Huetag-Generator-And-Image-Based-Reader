#pragma once

#ifndef OUT
#define OUT
#endif

#include <opencv2/core.hpp>

namespace orga {
	/// <summary>
	/// Used to find the cell coordinates of a square contour by visualizing it as a matrix. 
	/// The matrix is constructed by these lines and each intersection point within the matrix 
	/// is considered as a cell coordinate.
	/// </summary>
	struct Line {
		Line();
		Line(cv::Point* startPoint, cv::Point* endPoint);

		/// <summary>
		/// Slices the line in noOfSlices and gets the slice point at slicePosition.
		/// </summary>
		/// <param name='slicePosition'> 
		/// The slice position based from the noOfSlices to which the point to be returned is retrieved. 
		/// The slicePosition must be less than or equal to noOfSlices. 
		/// </param>
		/// <param name=''> The number of slices to be made on the line. </param>
		/// <returns> The point coordinate of the given slicePosition. </returns>
		cv::Point getSlicePointInLine(float slicePosition, int noOfSlices);

		void setPoints(cv::Point* startPoint, cv::Point* endPoint);

		cv::Point startPoint;
		cv::Point endPoint;

		float length;
		float m;
		float b;
	};

	cv::Point getIntersection(Line L1, Line L2);

	/// <summary>
	/// Gets the quadrant of an imaginary line drawn from p1 to p2.
	/// </summary>
	/// <param name='p1'> The starting point of the imaginary line. </param>
	/// <param name='p2'> The end point of the imaginary line. </param>
	/// <returns> Returns quadrant 1, 2, 3 or 4. </returns>
	int getQuadrant(cv::Point* p1, cv::Point* p2);
}