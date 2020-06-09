#ifndef FOURIER_HPP
#define FOURIER_HPP

#include "../complex/complex.hpp"
#include <vector>

std::vector<Complex> f2s(std::vector<Complex> vec_f);

std::vector<Complex> s2f(std::vector<Complex> vec_s);

void fft(std::vector<Complex> &a, bool invert);

void fftPrepare(std::vector <Complex> &a);

#endif
