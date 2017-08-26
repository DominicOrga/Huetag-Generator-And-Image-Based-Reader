
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

#include "crc.h"

#define OUT

void decimalToBinary(int dec, OUT std::vector<char>& outData);

void main() {

	while (true) {
		int n;
		std::cout << "Number of databits: " << std::flush;
		std::cin >> n;

		std::string key;
		std::cout << "Key: " << std::flush;
		std::cin >> key;

		std::vector<char> keyVec;

		for (int i = 0; i < key.size(); i++) {
			int a = key.at(i) - 48;
			keyVec.push_back(a);
		}

		int dec = 0;
		while (n > 0) {
			n--;
			dec += pow(2, n);
		}

		std::cout << "\nChecking...\n" << std::endl;

		int d = 0;
		int c = 0;
		for (int i = 0; i <= dec; i++) {
			std::vector<char> binary;
			decimalToBinary(i, OUT binary);

			std::vector<char> remainder;
			orga::CRCDeconvolution(keyVec, binary, OUT remainder);

			std::cout << i << " = " << std::flush;

			for (int i = 0; i < binary.size(); i++) {

				if (i == binary.size() - keyVec.size() + 1) {
					std::cout << " " << std::flush;
				}

				std::cout << binary.at(i) + 0 << std::flush;
			}

			if (remainder.empty()) {
				c++;
				std::cout << " (CRC Passed)" << std::endl;
			}
			else {
				std::cout << " (CRC Rejected)" << std::endl;
			}

			if (++d == (int) pow(2, keyVec.size() - 1)) {
				std::cout << std::endl;
				d = 0;
			}
		}

		std::cout << "Quotient = " << c << std::endl;

		std::cout << "\n Again? [1] = Yes, [0] = No: " << std::flush;
		int a;
		std::cin >> a;

		if (a != 1) {
			break;
		}

		std::cout << std::endl;
	}
}

void decimalToBinary(int dec, OUT std::vector<char>& outData) {

	outData.clear();

	if (dec == 0) {
		outData.push_back(0);
	}	
	else {
		while (dec > 0) {
			int r = dec % 2;
			dec /= 2;

			outData.insert(outData.begin(), r);	
		}
	}

	
}