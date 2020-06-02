#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex {
	double _re , _im;
public:
	Complex();// { _re = 0; _im = 0; };
	Complex(double re , double im = 0);// { _re  = re; _im = im; };
	Complex(const Complex &object);//{ _re = object._re; _im = object._im; };
	~Complex() {};
	double re() const;
	double im() const;
	double amp() const;
	double phase() const;
	Complex operator + (Complex right) const;
	Complex operator - (Complex right) const;
	Complex operator * (double right) const;
	Complex operator / (double right) const;
	Complex operator ^ (double alpha) const;
	Complex& operator = (const Complex &object);
	Complex& operator += (const Complex &object);
	friend std::istream& operator >>(std::istream& out, Complex& object);
	friend std::ostream& operator << (std::ostream& in, const Complex& object);
};

#endif
