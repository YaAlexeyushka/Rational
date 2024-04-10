#include <iostream>

#ifndef RATIONAL_H
#define RATIONAL_H

using namespace std;

class Rational
{
public:
	int numer;
	int denom;

	Rational();
	Rational(int number);
	Rational(int n, int d);

	Rational& operator +=(const Rational& r);
	Rational operator +(const Rational& r) const;
	Rational operator -(const Rational& r) const;
	Rational& operator -=(const Rational& r);
	Rational operator -() const;
	Rational& operator /=(const Rational& r);
	Rational& operator *=(const Rational& r);
	Rational operator /(const Rational& r) const;
	Rational operator *(const Rational& r) const;

	bool operator ==(const Rational& r) const;
	bool operator !=(const Rational& r) const;
	bool operator <(const Rational& r) const;
	bool operator <=(const Rational& r) const;
	bool operator >(const Rational& r) const;
	bool operator >=(const Rational& r) const;

	operator int() const;
	operator double() const;

	void simplify();

	friend ostream& operator <<(ostream& out, const Rational& r);
	friend istream& operator >>(istream& in, Rational& r);

	Rational& operator ++();
	Rational operator ++(int);

	Rational& operator --();
	Rational operator --(int);
};

#endif