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

void fft(std::vector<Complex> &a, bool invert) {
	int n = a.size();
	if (n == 1)
		return;
	std::vector<Complex> a0(n/2),  a1(n/2);
	for (int i = 0, j = 0; i < n; i += 2, ++j) {
		a0[j] = a[i];
		a1[j] = a[i + 1];
	}
	fft(a0, invert);
	fft(a1, invert);
	double ang = 2 * M_PI/n * (invert? -1 : 1);
	Complex w(1),  wn(cos(ang), sin(ang));
	for (int i = 0; i < n/2; ++i) {
		a[i] = a0[i] + w * a1[i];
		a[i + n / 2] = a0[i] - w * a1[i];
		if (invert) {
			a[i] /= 2;
			a[i + n / 2] /= 2;
		}
		w *= wn;
	}
}

void fftPrepare(std::vector <Complex> &a) {
	int n_old = a.size(), n_new = 1;
	while(n_old > n_new)
		n_new *= 2;
	a.resize(n_new);
	for (int i = n_old; i < n_new; i++)
		a[i] = 0;
}
