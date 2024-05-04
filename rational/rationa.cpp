#include "rational.h"
#include <iostream>

using namespace std;

Rational::Rational() {
  numer = 0;
  denom = 1;
}

Rational::Rational(long double number) {
  numer = number;
  denom = 1;
}

Rational::Rational(long double n, long double d) {
  if (d == 0) {
    const char value[] = "zero division exception";
    throw value;
  }

  numer = n;
  denom = d;
  simplify();
}

Rational Rational::makeDecimal() {
    Rational result = numer / denom;

    return result;
}

long double Rational::square(long double num) {

  if (num < 0) {
      const char value[] = "root of a negative number exception";
      throw value;
  }

  if (num == 1) {
      return 1;
  }

  long double xn = num / 2.00;
  double precision = 0.000001;
  
  for (int n = 0; ( ( xn - num / xn ) ) > precision; n++) {
      xn = 0.5 * ( xn + ( num / xn ) );
  }

  return xn;

}

Rational Rational::squareRational() {
  Rational result = square(numer) / square(denom);

  return result;
}

Rational &Rational::operator+=(const Rational &r) {
  numer = (numer * r.denom + denom * r.numer);
  denom *= r.denom;
  simplify();

  return *this;
}

Rational Rational::operator+(const Rational &r) const {
  Rational res(*this);
  return res += r;
}

Rational Rational::operator-(const Rational &r) const {
  Rational res(*this);
  return res -= r;
}

Rational &Rational::operator-=(const Rational &r) { return (*this += (-r)); }

Rational Rational::operator-() const {
  Rational r(-numer, denom);
  return r;
}

void Rational::simplify() {
  long long int num1 = abs(numer), num2 = abs(denom);

  while (num1 != 0 and num2 != 0) {

    if (num1 > num2) {
      num1 = num2;
    }

    else {
      num2 %= num1;
    }

  }

  long long int nod = num1 + num2;

  numer /= nod;
  denom /= nod;
}

Rational &Rational::operator++() {
  numer += denom;
  return *this;
}

Rational Rational::operator++(int) {
  Rational r(*this);
  numer += denom;
  return r;
}

Rational &Rational::operator--() {
  numer -= denom;
  return *this;
}

Rational Rational::operator--(int) {
  Rational r(*this);
  numer -= denom;
  return r;
}

Rational &Rational::operator/=(const Rational &r) {
  Rational temp;
  temp.numer = r.denom;
  temp.denom = r.numer;
  return *this *= temp;
}

Rational &Rational::operator*=(const Rational &r) {
  numer *= r.numer;
  denom *= r.denom;
  simplify();
  return *this;
}

Rational Rational::operator/(const Rational &r) const {
  Rational temp(*this);
  return temp /= r;
}

Rational Rational::operator*(const Rational &r) const {
  Rational temp(*this);
  return temp *= r;
}

Rational::operator int() const { return numer / denom; }

Rational::operator double() const { return (double(numer)) / denom; }

bool Rational::operator==(const Rational &r) const {
  Rational temp_r(r);
  Rational temp_this(*this);

  temp_r.simplify();
  temp_this.simplify();

  return (temp_r.numer == temp_this.numer and temp_r.denom == temp_this.denom);
}

bool Rational::operator!=(const Rational &r) const { return !(r == *this); }

bool Rational::operator<(const Rational &r) const {
  return double(*this) < double(r);
}
bool Rational::operator<=(const Rational &r) const { return !(*this > r); }
bool Rational::operator>(const Rational &r) const {
  return double(*this) > double(r);
}
bool Rational::operator>=(const Rational &r) const { return !(*this < r); }

ostream &operator<<(ostream &out, const Rational &r) {
  if (r.denom == 1) {
    out << r.numer;
    return out;
  }

  out << r.numer << "/" << r.denom;
  return out;
}

istream &operator>>(istream &in, Rational &r) {
  in >> r.numer >> r.denom;
  r.simplify();
  return in;
}