#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <fstream>

class Complex {
    double _re, _im;
public:
    Complex();
    Complex(double re, double im);
    double re() const;
//    double amp() const;
//    double phase() const;
    Complex operator+=(const Complex &z);
    Complex operator/=(double x);
    Complex operator*(double x) const;
    Complex operator/(double x) const;
    Complex operator^(double alpha) const;
};
std::vector<Complex> f2s(const std::vector<Complex> &f);
std::vector<Complex> s2f(const std::vector<Complex> &c);
#endif
