#pragma once

#ifndef OUT
#define OUT
#endif

#include <vector>
#include "qrgb.h"

namespace orga {
	namespace detail {
		/// <summary>
		/// Determines the marker ID into its equivalent main bits.
		/// </summary>
		/// <param name='id'> The marker ID to derive the mainData. </param>
		/// <param name='mainData'> The main bits derived from the id. </param>
		void markerIDToMainData(int id, OUT std::vector<char>& mainData);

		/// <summary>
		/// Concatenates leading static bits to the bitData and returns it through outResult.
		/// </summary>
		/// <param name='bitData'> The bit data to be extended. </param>
		/// <param name='outResult'> The extended bit data concated with leading static bits. </param>
		void staticBitsConvolution(std::vector<char>& bitData, OUT std::vector<char>& outResult);
	}

	/// <summary>
	/// Identifies the color from the 72-bit data using the index of the desired data-cell's color.
	/// </summary>
	/// <para>
	/// The data is assumed to have a 72 databits, the total number of bits in 
	/// a single huetag marker. Each data-cell of a marker is represented by a 
	/// 2-bit digit: 00 (red), 01 (green), 10 (yellow) and 11 (blue).
	/// </para>
	/// <param name='data'> The 72-bit long marker data. </param>
	/// <param name='position'> The position of the data-cell color which extends between 0 - 35. </param>
	QRgb identifyDataCellColorViaBitData(std::vector<char>& data, int position);


	/// <summary>
	/// Generates the main bits and parity bits derived from the given ID, and 
	/// concatenates them together in convolvedBits.
	/// </summary>
	/// <param name='id'> The id to derive the marker data. </param>
	/// <param name='mainBits'> The main bits derived from the ID. </param>
	/// <param name='convolvedBits'> The bits convolved with CRC. </param>
	void generateMarkerData(int id, std::vector<char>& OUT mainBits, std::vector<char>& OUT convolvedBits);
}