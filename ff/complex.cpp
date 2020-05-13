#include "complex.hpp"
Complex::Complex() {}
Complex::Complex(double re, double im = 0) {
    _re = re;
    _im = im;
}

double Complex::re() const {
    return _re;
}

Complex Complex::operator+=(const Complex& z) {
    _re += z._re;
    _im += z._im;
}

Complex Complex::operator*(double x) const {
    return Complex(_re * x, _im * x);
}


Complex Complex::operator/(double x) const {
    return Complex(_re / x, _im / x);
}

Complex Complex::operator/=(double x) {
    return (*this)/x;
}

Complex Complex::operator^(double alpha) const {
    return Complex(_re * cos(alpha) - _im * sin(alpha),
                    _im * cos(alpha) - _re * sin(alpha));
}

std::vector<Complex> f2s(const std::vector<Complex> &f) {
    std::vector<Complex> c;
    int n = f.size();
    c.resize(n);
    for (int k = 0; k < n; ++k) {
        for (int j = 0; j < n; ++j)
            c[k] += f[j] ^ ((-2 * M_PI * k * j) / n);
            c[k] /= n;
    }
    return c;
}

std::vector<Complex> s2f(const std::vector<Complex> &c) {
    std::vector<Complex> f;
    int n = c.size();
    f.resize(n);
    for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k) {
            double alpha = ((-2 * M_PI * k * j) / n);
            f[j] += c[k] ^ (alpha);
        }
    return f;
}
