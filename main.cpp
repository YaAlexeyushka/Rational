#include "rational/rational.h"
#include <fstream>
#include <iostream>

using namespace std;

Rational calculateDiscriminant(const Rational a, const Rational b, const Rational c) {

	Rational D = (b * b) - Rational(4) * a * c;

	if (D < Rational(0)) {
		const char value[] = "negative discriminant";
		throw value;
	}

	return D;

}

void calculateRoots(const Rational a, const Rational b, const Rational c,
		Rational *px1, Rational *px2) {

	try {
		Rational D = calculateDiscriminant(a, b, c);

		*px1 = (-b + (b * b - Rational(4) * a * c).squareRational())
			/ (Rational(2) * a);

		*px2 = (-b - (b * b - Rational(4) * a * c).squareRational())
			/ (Rational(2) * a);
	}
	catch (...) {
		cerr << "Error!";
	}

	*px1 = (*px1).makeDecimal();
	*px2 = (*px2).makeDecimal();

}

int main() {

  setlocale(LC_ALL, "RU-ru");

  Rational a;
  Rational b;
  Rational c;

  cout << "ax^2 + bx + c = 0" << '\n' << "enter a, b, c to calculate the equation" << endl;
  cin >> a >> b >> c;

  Rational x1, x2;
  calculateRoots(a, b, c, &x1, &x2);

  cout << x1 << ' ' << x2;

}
