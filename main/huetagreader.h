#pragma once

#ifndef OUT
#define OUT
#endif

#include <vector>
#include <opencv2/core.hpp>

namespace orga { class Lab; }

class QString;

namespace orga {
	namespace detail {
		/// <summary>
		/// Extract the binary data of a marker based on the colors of its data cells.
		/// </summary>
		/// <param name='dataCellLabArray'> The marker's data-cell lab colors. </param>
		/// <param name='rotation'> The rotation of the marker. </param>
		/// <param name='outData'> The binary data extracted from the marker's colors </param>
		void extractMarkerData(std::vector<orga::Lab>& dataCellLabArray, OUT std::vector<char>& outData);

		/// <summary>
		/// Extracts the Lab values from the data cell coordinates of a marker image.
		/// </summary>
		/// <param name='image'> The image containing the marker. </param>
		/// <param name='dataCellCoords'> The data cell coordinates of the marker. </param>
		/// <param name='outLabArray'> The list where the extracted lab values will be stored. </param>
		void extractDataCellLabColors(cv::Mat* image, std::vector<cv::Point*>* dataCellCoords, OUT std::vector<orga::Lab>& outLabArray);

		/// <summary>
		/// Identifies the Lab color whether it is red, green, yellow or blue by calculating their distance using euclidean distance algorithm.
		/// </summary> 
		/// <param name='lab'> The lab color to be analysed. </param>
		/// <param name='redLabRef'> The red lab reference to compare the lab to. </param>
		/// <param name='greenLabRef'> The green lab reference to compare the lab to. </param>
		/// <param name='yellowLabRef'> The yellow lab reference to compare the lab to. </param>
		/// <param name='blueLabRef'> The blue lab reference to compare the lab to. </param>
		/// <returns>
		/// Returns 0 (red), 1 (green), 2 (yellow), 3 (blue).
		/// </returns>
		int identifyColor(orga::Lab& lab, orga::Lab& redLabRef, orga::Lab& greenLabRef, orga::Lab& yellowLabRef, orga::Lab& blueLabRef);

		/// <summary>
		/// Determines the rotation of the marker by analysing its static cells.
		/// </summary>
		/// <param name='labArray'> The lab values of each data-cell of a specific huetag marker. </param>
		/// <returns>
		/// Returns 0, 90, 180, 270 respective to the marker's recognized rotation. 
		/// </returns>
		int identifyMarkerRotation(std::vector<orga::Lab>& labArray);

		/// <summary>
		/// Calculates the distance between two Lab colors using a and b as the x and y axis, respectively.
		/// </summary>
		/// <returns> The distance between the two colors. </returns>
		float eucledianDistance(orga::Lab& lab1, orga::Lab& lab2);

		void deconvolveStaticBits(std::vector<char>& oldData, OUT std::vector<char>& newData);
	}

	/// <summary>
	/// Extract data cell points from a square contour by treating it as a matrix of matrixSize.
	/// </summary>
	/// <param name='squareContour'> The square contour in which the data-cell points will be extracted. </param>
	/// <param name='outDataCellArray'> Stores all the extracted data-cell points. </param>
	/// <param name='matrixSize'> The interpreted matrix size of the square contour. </param>
	void extractDataCellPoints(std::vector<cv::Point*>* squareContour, OUT std::vector<cv::Point>& outDataCellArray, int matrixSize);

	/// <summary>
	/// Decodes the marker, returning its ID.
	/// </summary>
	/// <param name='image'> The image containing the marker. </param>
	/// <param name='dataCellCoords'> The data cell coordinates of the marker. </param>
	/// <returns> Returns the ID of the marker. Returns -1 if the marker is undecodable. </returns>
	int identifyMarkerID(cv::Mat* image, std::vector<cv::Point*>* dataCellCoords);	
}