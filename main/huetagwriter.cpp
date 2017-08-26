
#include "huetagwriter.h"
#include "crc.h"
#include "global.h"

namespace orga {
	namespace detail {
		void markerIDToMainData(int id, OUT std::vector<char>& mainData) {
			mainData.clear();

			while (id != 0) {
				int a = id % 2;
				mainData.insert(mainData.begin(), a);
				id /= 2;
			}

			while (mainData.size() < 24) {
				mainData.insert(mainData.begin(), 0);
			}
		}

		void staticBitsConvolution(std::vector<char>& bitData, OUT std::vector<char>& outResult) {
			outResult.clear();
			outResult.resize(bitData.size());

			std::copy(bitData.begin(), bitData.end(), outResult.begin());

			// Concatenate leading 00 (red)
			outResult.insert(outResult.begin(), 0);
			outResult.insert(outResult.begin(), 0);

			// Concatenate leading 01 (green)
			outResult.insert(outResult.begin(), 1);
			outResult.insert(outResult.begin(), 0);

			// Concatenate leading 10 (yellow)
			outResult.insert(outResult.begin(), 0);
			outResult.insert(outResult.begin(), 1);

			// Concatenate leading 11 (blue)
			outResult.insert(outResult.begin(), 1);
			outResult.insert(outResult.begin(), 1);
		}
	}

	QRgb identifyDataCellColorViaBitData(std::vector<char>& data, int position) {
		int a = data.at(position * 2);
		int b = data.at(position * 2 + 1);

		if (a == 0 && b == 0) {
			return qRgb(236, 0, 140);
		}
		else if (a == 0 && b == 1) {
			return qRgb(0, 166, 81);
		}
		else if (a == 1 && b == 0) {
			return qRgb(255, 242, 0);
		}
		else {
			return qRgb(0, 174, 239);
		}
	}

	void generateMarkerData(int id, std::vector<char>& OUT mainBits, std::vector<char>& OUT markerData) {
		mainBits.clear();
		markerData.clear();

		detail::markerIDToMainData(id, OUT mainBits);

		std::vector<char> convolvedBits;
		orga::CRCConvolution(orga::generatorKey, mainBits, OUT convolvedBits);

		while (convolvedBits.size() < 64) {
			convolvedBits.insert(convolvedBits.begin(), 0);
		}

		detail::staticBitsConvolution(convolvedBits, OUT markerData);
	}
}