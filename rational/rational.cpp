#include "rational.h"
#include <iostream>

using namespace std;

Rational::Rational()
{
	numer = 0;
	denom = 1;
}

Rational::Rational(int number)
{
	numer = number;
	denom = 1;
}

Rational::Rational(int n, int d)
{
	if (d == 0) {
		const char value[] = "zero division exception";
		throw value;
	}

	numer = n;
	denom = d;
	simplify();
}

Rational& Rational::operator +=(const Rational& r)
{
	numer = (numer * r.denom + denom * r.numer);
	denom *= r.denom;
	simplify();

	return *this;
}

Rational Rational::operator +(const Rational& r) const
{
	Rational res(*this);
	return res += r;
}

Rational Rational::operator -(const Rational& r) const
{
	Rational res(*this);
	return res -= r;
}

Rational& Rational::operator -=(const Rational& r)
{
	return (*this += (-r));
}

Rational Rational::operator -() const
{
	Rational r(-numer, denom);
	return r;
}

void Rational::simplify()
{
	int temp_numer = numer, temp_denom = denom;

	while (temp_numer != 0 and temp_denom != 0 and (temp_numer != 1 and temp_denom != 1)) {

		if (abs(temp_numer) > abs(temp_denom)) {
			temp_numer %= abs(temp_denom);
		}

		else {
			temp_denom %= abs(temp_numer);
		}

	}

	if (temp_numer == numer and temp_denom == denom) {
		return;
	}

	int temp_max = max(temp_numer, temp_denom);

	if (temp_max != 0) {
		numer /= temp_max;
		denom /= temp_max;
	}

}

Rational& Rational::operator ++()
{
	numer += denom;
	return *this;
}

Rational Rational::operator ++(int)
{
	Rational r(*this);
	numer += denom;
	return r;
}

Rational& Rational::operator --()
{
	numer -= denom;
	return *this;
}

Rational Rational::operator --(int)
{
	Rational r(*this);
	numer -= denom;
	return r;
}

Rational& Rational::operator /=(const Rational& r) {
	Rational temp;
	temp.numer = r.denom;
	temp.denom = r.numer;
	return *this *= temp;
}

Rational& Rational::operator *=(const Rational& r) {
	numer *= r.numer;
	denom *= r.denom;
	simplify();
	return *this;
}

Rational Rational::operator /(const Rational& r) const {
	Rational temp(*this);
	return temp /= r;
}

Rational Rational::operator *(const Rational& r) const {
	Rational temp(*this);
	return temp *= r;
}

Rational::operator int() const {
	return numer / denom;
}

Rational::operator double() const {
	return (double(numer)) / denom;
}

bool Rational::operator ==(const Rational& r) const {
	Rational temp_r(r);
	Rational temp_this(*this);
	
	temp_r.simplify();
	temp_this.simplify();

	return (temp_r.numer == temp_this.numer and temp_r.denom == temp_this.denom);
}

bool Rational::operator !=(const Rational& r) const {
	return !(r == *this);
}

bool Rational::operator <(const Rational& r) const {
	return double(*this) < double(r);
}
bool Rational::operator <=(const Rational& r) const {
	return !(*this > r);
}
bool Rational::operator >(const Rational& r) const {
	return double(*this) > double(r);
}
bool Rational::operator >=(const Rational& r) const {
	return !(*this < r);
}


ostream& operator <<(ostream& out, const Rational& r) {
	out << r.numer << "/" << r.denom;
	return out;
}

istream& operator >>(istream& in, Rational& r) {
	in >> r.numer >> r.denom;
	r.simplify();
	return in;
}