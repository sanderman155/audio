#include "../complex/complex.hpp"
#include "../ff/fourier.hpp"
#include <vector>
#include <cmath>
#include <iostream>

int main() {
	std::vector<Complex> vec_f = {1 , 6 , 2 , 5 , 3 , 4}, vec_s, vec_F;
	int pos = 0;
	for (auto complex_number: vec_f) {
		std::cout << "f" << pos++ << " = " << complex_number;
	}
	vec_s = f2s(vec_f);
	vec_F = s2f(vec_s);
	std::cout << "SPECTR" << std::endl;
	pos = 0;
	for (auto complex_number: vec_s) {
		std::cout << "s" << pos++ << " = " << complex_number;
	}
	std::cout << "FUNCTION" << std::endl;
	pos = 0;
	for (auto complex_number: vec_F) {
		std::cout << "f" << pos++ << " = " << complex_number;
	}
	std::cout << "FastFourierTransform" << std::endl;
	fftPrepare(vec_F);
	fft(vec_F, 0);
	pos = 0;
	for (auto complex_number: vec_F) {
		std::cout << "f" << pos++ << " = " << complex_number;
	}
	fft(vec_F, 1);
	pos = 0;
	for (auto complex_number: vec_F) {
		std::cout << "f" << pos++ << " = " << complex_number;
	}
	return 0;
}
