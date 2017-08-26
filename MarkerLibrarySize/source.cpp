#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>

#include "crc.h"

static void decimalToTernary(int decimal, OUT std::vector<char>& outTernary) {
	outTernary.clear();

	do {
		int n = decimal % 3;
		outTernary.insert(outTernary.begin(), n);
		decimal /= 3;
	} while (decimal != 0);
}

static void ternaryToBinary(std::vector<char>& ternary, OUT std::vector<char>& outBinary) {
	outBinary.clear();

	for (int i = 0; i < ternary.size(); i++) {
		int ternaryBit = ternary.at(i);

		// bit is red (00)
		if (ternaryBit == 0) {
			outBinary.push_back(0);
			outBinary.push_back(0);
		}
		// bit is yellow (01)
		else if (ternaryBit == 1) {
			outBinary.push_back(0);
			outBinary.push_back(1);
		}
		// bit is blue (10)
		else {
			outBinary.push_back(1);
			outBinary.push_back(0);
		}
	}
}

static void extendDataBits(OUT std::vector<char>& data, int length) {
	while (data.size() < length) {
		data.insert(data.begin(), 0);
	}
}

static void addStaticBits(std::vector<char>& data) {
	// Add red at the beginning of the data.
	data.insert(data.begin(), 0);
	data.insert(data.begin(), 0);

	// Add yellow at the beginning of the data.
	data.insert(data.begin(), 1);
	data.insert(data.begin(), 0);

	// Add blue at the beginning of the data.
	data.insert(data.begin(), 0);
	data.insert(data.begin(), 1);
}

/// <summary>
/// Checks if the data contains consecutive bits of 1 starting from an even index.
/// </summary>
static bool containsConsecutive1sInEvenIndex(std::vector<char>& data) {
	for (int i = 0; i < data.size() - 1; i += 2) {
		int bit1 = data.at(i);
		int bit2 = data.at(i + 1);

		if (bit1 == 1 && bit2 == 1) {
			return true;
		}
	}

	return false;
}

static std::string formatTime(double timeInSeconds) {
	int hours = timeInSeconds / 3600;
	timeInSeconds -= timeInSeconds * hours;

	int minutes = timeInSeconds / 60;
	timeInSeconds -= timeInSeconds * minutes;

	return std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(timeInSeconds);
}

/// This program will count all possible permutations of the Huetag system's actual data (3^13) 
/// which will NOT produce a parity bit with consecutive 1's starting from an even index.
/// Why you ask? Because the Huetag system makes use of only three colors: red(00), yellow(01), and blue(10).
/// Now, if the CRC generated a parity bit containing 11, then no color can represent it.
void main() {
	int totalPermutations = powf(3, 13); // Total possible permutations of the actual data.

	int allowedPermutations = 0; // Total amount of allowed actual data permutations which does not produce a 
								 // parity bit with consecutive 1's starting from an even index.

	clock_t clockBegin = clock();
	for (int i = 0; i < totalPermutations; i++) {
		std::vector<char> ternary;
		decimalToTernary(i, OUT ternary);

		std::vector<char> actualData;
		ternaryToBinary(ternary, OUT actualData); // ternary bit 0 = binary bit 00 (red)
												  // ternary bit 1 = binary bit 01 (yellow)
												  // ternary bit 2 = binary bit 10 (blue)

		extendDataBits(OUT actualData, 26); // Each actual data is equal to 26 databits, since for every ternary bits is equal to 2 binary bits.
		addStaticBits(OUT actualData); // Attach the static bits from the actual data.

									   // Convolve the actual data with CRC.
		std::vector<char> convolvedData;
		orga::CRCConvolution(orga::generatorKey, actualData, OUT convolvedData);

		if (!containsConsecutive1sInEvenIndex(convolvedData)) {
			allowedPermutations++;
		}

		std::cout << "Parity Bits: " << std::flush;
		for (int i = 32; i < 72; i++) {
			std::cout << convolvedData.at(i) + 0 << std::flush;
			if (i % 2 != 0) {
				std::cout << " " << std::flush;
			}
		}

		std::cout << std::endl;

		clock_t clockEnd = clock();
		std::cout << "Total Permutations Tested: " << i + 1 << " / " << totalPermutations << std::endl;
		std::cout << "Total Allowed Permutations: " << allowedPermutations << std::endl;
		std::cout << "Elapsed CPU Time In Seconds: " << formatTime(double(clockEnd - clockBegin) / CLOCKS_PER_SEC) << std::endl;

		std::cout << std::endl;
	}

	system("pause");
}