#pragma once

#ifndef OUT
#define OUT
#endif

#include <vector>

namespace orga {
	namespace detail {
		/// <summary>
		/// Divides the key and bitData using arithmetic modulo of 2 and returns the remainder to outRemainder.
		/// </summary>
		void XORRemainder(std::vector<char>& key, std::vector<char>& bitData, OUT std::vector<char>& outRemainder);

		/// <summary>
		/// XOR's bitData1 with bitData2 and stores the result to outResult.
		/// </summary>
		void XOR(std::vector<char>& bitData1, std::vector<char>& bitData2, OUT std::vector<char>& outResult);

		/// <summary>
		/// Removes any leading 0's from bitData and if a non-binary digit is found, then the operation is cancelled.
		/// <returns> Returns 0 if operation is successful. Returns 1 if a non-binary digit is found. </returns>
		/// </summary>
		int RemoveLeadingZeros(std::vector<char>& bitData, OUT std::vector<char>& outResult);
	}

	/// <summary>
	/// CRC convolves the bitData with the key and returns the result to outResult.
	/// <returns> 
	/// Returns 0 if the operation was successful.
	/// Returns 1 if a non-binary digit input was found which also cancels the function.
	///</returns>
	/// </summary>
	int CRCConvolution(std::vector<char>& key, std::vector<char>& bitData, OUT std::vector<char>& outResult);

	/// <summary>
	/// CRC deconvolves the bitData with the key and returns the remainder to outRemainder
	/// <returns> 
	/// Returns 0 if the operation was successful.
	/// Returns 1 if a non-binary digit input was found which also cancels the function.
	///</returns>
	/// </summary>
	int CRCDeconvolution(std::vector<char>& key, std::vector<char>& bitData, OUT std::vector<char>& outRemainder);

	extern std::vector<char> generatorKey;
}