#include <vector>
#include <cmath>
#include "crc.h"

namespace orga {

	namespace detail {
		void XOR(std::vector<char>& bitData1, std::vector<char>& bitData2, OUT std::vector<char>& outResult) {
			outResult.clear();

			std::vector<char> bitData1Copy;
			RemoveLeadingZeros(bitData1, OUT bitData1Copy);

			std::vector<char> bitData2Copy;
			RemoveLeadingZeros(bitData2, OUT bitData2Copy);

			int size1 = bitData1Copy.size();
			int size2 = bitData2Copy.size();
			int diff = fabs(size2 - size1);


			if (size1 >= size2) {
				for (int k = 0, j = 0 - diff; k < size1; k++, j++) {
					char temp = bitData1Copy.at(k);

					if (j < 0) {
						if (outResult.size() != 0 || temp != 0) {
							outResult.push_back(temp);
						}
					}
					else {
						temp ^= bitData2Copy.at(j);
						if (outResult.size() != 0 || temp != 0) {
							outResult.push_back(temp);
						}
					}
				}
			}
			else {
				for (int k = 0, j = 0 - diff; k < size2; k++, j++) {
					char temp = bitData2Copy.at(k);

					if (j < 0) {
						if (outResult.size() != 0 || temp != 0) {
							outResult.push_back(temp);
						}
					}
					else {
						temp ^= bitData1Copy.at(j);
						if (outResult.size() != 0 || temp != 0) {
							outResult.push_back(temp);
						}
					}
				}
			}

		}

		void XORRemainder(std::vector<char>& key, std::vector<char>& bitData, std::vector<char>& outRemainder) {

			outRemainder.clear();

			std::vector<char> temp;
			for (int i = 0; i < bitData.size(); i++) {

				if (outRemainder.size() != 0 || bitData.at(i) != 0) {
					outRemainder.push_back(bitData.at(i));
				}

				if (outRemainder.size() < key.size()) {
					continue;
				}

				XOR(key, outRemainder, OUT temp);

				outRemainder.swap(temp);

				temp.clear();

			}

		}

		int RemoveLeadingZeros(std::vector<char>& bitData, OUT std::vector<char>& outResult) {
			outResult.clear();

			for (int i = 0; i < bitData.size(); i++) {
				char temp = bitData.at(i);

				if (temp != 0 && temp != 1) {
					outResult.clear();
					return 1;
				}

				if (outResult.size() != 0 || temp != 0) {
					outResult.push_back(temp);
				}
			}

			return 0;
		}
	}

	int CRCConvolution(std::vector<char>& key, std::vector<char>& bitData, OUT std::vector<char>& outResult) {
		std::vector<char> keyCopy;
		int a = detail::RemoveLeadingZeros(key, OUT keyCopy);

		if (a == 1) {
			return 1;
		}

		a = detail::RemoveLeadingZeros(bitData, OUT outResult);

		if (a == 1) {
			return 1;
		}

		for (int i = 1; i < keyCopy.size(); i++) {
			outResult.push_back(0);
		}

		std::vector<char> outRemainder;
		detail::XORRemainder(keyCopy, outResult, OUT outRemainder);

		while (outRemainder.size() < keyCopy.size() - 1) {
			outRemainder.insert(outRemainder.begin(), 0);
		}

		for (int i = 1; i < keyCopy.size(); i++) {
			outResult.pop_back();
		}

		outResult.insert(outResult.end(), outRemainder.begin(), outRemainder.end());

		return 0;
	}

	int CRCDeconvolution(std::vector<char>& key, std::vector<char>& bitData, OUT std::vector<char>& outRemainder) {
		std::vector<char> keyCopy;
		int a = detail::RemoveLeadingZeros(key, OUT keyCopy);

		if (a == 1) {
			return 1;
		}

		std::vector<char> bitDataCopy;
		a = detail::RemoveLeadingZeros(bitData, OUT bitDataCopy);

		if (a == 1) {
			return 1;
		}

		detail::XORRemainder(keyCopy, bitDataCopy, OUT outRemainder);

		return 0;
	}

	std::vector<char> generatorKey = { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };

	//std::vector<char> generatorKey = { 1,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,1,0,0,0,1,0,0,0,1 };
}