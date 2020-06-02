#include "../complex/complex.hpp"
#include "../ff/fourier.hpp"
#include <vector>
#include <cmath>
#include <iostream>

int main() {
	std::vector<Complex> vec_f = {1 , 6 , 2 , 5 , 3 , 4}, vec_s, vec_F;
	for (auto complex_number: vec_f) {
		int pos = 0;
		std::cout << "f" << pos++ << " = " << complex_number;
	}
	vec_s = f2s(vec_f);
	vec_F = s2f(vec_s);
	std::cout << "SPECTR" << std::endl;
	for (auto complex_number: vec_s) {
		int pos = 0;
		std::cout << "s" << pos++ << " = " << complex_number;
	}
	std::cout << "FUNCTION" << std::endl;
	for (auto complex_number: vec_F) {
		int pos = 0;
		std::cout << "f" << pos++ << " = " << complex_number;
	}
	return 0;
}
