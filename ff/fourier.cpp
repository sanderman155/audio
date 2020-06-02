#include "fourier.hpp"
#include "../complex/complex.hpp"
#include <vector>
#include <cmath>

std::vector<Complex> f2s(std::vector<Complex> vec_f) {
	int n = vec_f.size();
	std::vector<Complex> vec_s;
	vec_s.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vec_s[i] += vec_f[j] ^ (-2 * M_PI * j * i / n);
		}
		vec_s[i] = vec_s[i] / n;
	}
	return vec_s;
}

std::vector<Complex> s2f(std::vector<Complex> vec_s) {
	int n = vec_s.size();
	std::vector<Complex> vec_f;
	vec_f.resize(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			vec_f[i] += vec_s[j] ^ (2 * M_PI * j * i / n);
		}
	}
	return vec_f;
}
