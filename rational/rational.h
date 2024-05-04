#include <iostream>

#ifndef RATIONAL_H
#define RATIONAL_H

using namespace std;

class Rational {

  long double square(long double num);
  void simplify();

public:
  long double numer;
  long double denom;

  Rational();
  Rational(long double number);
  Rational(long double n, long double d);

  Rational makeDecimal();
  Rational squareRational();

  Rational &operator+=(const Rational &r);
  Rational operator+(const Rational &r) const;
  Rational operator-(const Rational &r) const;
  Rational &operator-=(const Rational &r);
  Rational operator-() const;
  Rational &operator/=(const Rational &r);
  Rational &operator*=(const Rational &r);
  Rational operator/(const Rational &r) const;
  Rational operator*(const Rational &r) const;

  bool operator==(const Rational &r) const;
  bool operator!=(const Rational &r) const;
  bool operator<(const Rational &r) const;
  bool operator<=(const Rational &r) const;
  bool operator>(const Rational &r) const;
  bool operator>=(const Rational &r) const;

  operator int() const;
  operator double() const;

  friend ostream &operator<<(ostream &out, const Rational &r);
  friend istream &operator>>(istream &in, Rational &r);

  Rational &operator++();
  Rational operator++(int);

  Rational &operator--();
  Rational operator--(int);
};

#endif