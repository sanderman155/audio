#include "complex.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

Complex::Complex() {
	_re = 0;
	_im = 0;
};

Complex::Complex(double re, double im) {
	_re = re;
	_im = im;
};

Complex::Complex(const Complex &tmp) {
	_re = tmp._re;
	_im = tmp._im;
};

double Complex::re() const {
	return _re;
}


double Complex::im() const {
	return _im;
}

double Complex::amp() const {
	return sqrt(_re * _re + _im * _im);
}

double Complex::phase() const {
	if (_re == 0) {
		if (_im > 0)
			return M_PI/2;
		else
			return -M_PI/2;
		return 0;
	}
	return atan(_im/_re);
}
 
Complex Complex::operator+(Complex right) const {
	Complex tmp(_re + right._re, _im + right._im);
	return tmp;
}

Complex Complex::operator-(Complex right) const {
	Complex tmp(_re - right._re, _im - right._im);
	return tmp;
}

Complex Complex::operator*(double right) const {
	Complex tmp(_re * right, _im * right);
	return tmp;
}

Complex Complex::operator/(double right) const {
	Complex tmp(_re / right, _im / right);
	return tmp;
}

Complex Complex::operator^(double alpha) const {
	Complex obj(_re, _im);
	obj._re = this -> amp() * cos(this -> phase() + alpha);
	obj._im = this -> amp() * sin(this -> phase() + alpha);
	return obj;
}

Complex Complex::operator* (const Complex& right) const {
	Complex tmp(_re * right.re() - _im * right.im(),
				_re * right.im() + _im * right.re());
	return tmp;
}

Complex& Complex::operator=(const Complex &right) {
	_re = right._re;
	_im = right._im;
	return *this;
}

Complex& Complex::operator+=(const Complex &right) {
	(*this) = (*this) + right;
	return *this;
}

Complex& Complex::operator*=(const Complex &right) {
	(*this) = (*this) * right;
	return *this;
}

Complex& Complex::operator/=(double right) {
	(*this) = (*this) / right;
	return *this;
}


std::ostream& operator<<(std::ostream& output, const Complex& tmp) {
	if (tmp._im < 0) {
		output << std::setprecision(3) << std::fixed << tmp._re << " - " << -1 * tmp._im << "i\n";
	} else {
		output << std::setprecision(3) << std::fixed << tmp._re << " + " << tmp._im << "i\n";
	}
	return output;
}

std::istream& operator>>(std::istream& input, Complex& tmp) {
	input >> tmp._re;
	input >> tmp._im;
	return input;
}
