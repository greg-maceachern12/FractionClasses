#include "fractions_15gjm2.h"

#include <iostream>
#include <cstdlib>

using namespace std;

// empty constructor (0/1)
Fraction::Fraction() :
		numerator(0), denominator(1) {
}

// single number operator (gives x/1)
Fraction::Fraction(int v1) :
		numerator(v1), denominator(1) {
}

//full constructor (yields a numerator and denominator)
Fraction::Fraction(int v1, int v2) {
	// greatest common divisor
	int divisor = greatestCommonDenominator(abs(v1), abs(v2));

	//putting the fractions in their lowest form
	if (v2 < 0) {
		numerator = -v1 / divisor;
		denominator = -v2 / divisor;
	} else {
		numerator = v1 / divisor;
		denominator = v2 / divisor;
	}
}
// greatest common denominator function
int Fraction::greatestCommonDenominator(int a, int b) {
	// recursive approach. Keep calling GCD function until b parameter is 0, in which case, return a.
	return b == 0 ? a : greatestCommonDenominator(b, a % b);
}

// numerator getter
int Fraction::getNumerator() const {
	return numerator;
}

// denominator getter
int Fraction::getDenominator() const {
	return denominator;
}
// overloading for negative casting
Fraction Fraction::operator-() {
	return Fraction(-numerator, denominator);
}

//overloading for addition
Fraction operator+(const Fraction& v1, const Fraction& v2) {
	//checks if the denominator is the same as the as the other denominator. If so, easy addition.
	if (v1.getDenominator() == v2.getDenominator()) {
		int newValue = v1.getNumerator() + v2.getNumerator();
		return Fraction(newValue, v1.getDenominator());
	} else {
		// otherwise, cross multiply to get the closest denominator and add those two new fraction
		int newFraction1 = v1.getNumerator() * v2.getDenominator();
		int newFraction2 = v2.getNumerator() * v1.getDenominator();
		int newDenominator = v1.getDenominator() * v2.getDenominator();
		return Fraction((newFraction1 + newFraction2), newDenominator);
	}
}

// overloading for subtracting
Fraction operator-(const Fraction& v1, const Fraction& v2) {
	if (v1.getDenominator() == v2.getDenominator()) {
		int newValue = v1.getNumerator() - v2.getNumerator();
		return Fraction(newValue, v1.getDenominator());
	} else {
		int newFraction1 = v1.getNumerator() * v2.getDenominator();
		int newFraction2 = v2.getNumerator() * v1.getDenominator();
		int newDenominator = v1.getDenominator() * v2.getDenominator();
		return Fraction((newFraction1 - newFraction2), newDenominator);
	}
}

// overloading for multiplication
Fraction operator*(const Fraction& v1, const Fraction& v2) {
	// multiple both the numerator and the denominator
	return Fraction((v1.getNumerator() * v2.getNumerator()),
			(v1.getDenominator() * v2.getDenominator()));
}

//overloading for division
Fraction operator/(const Fraction& v1, const Fraction& v2) {
	int numerator = v1.getNumerator() * v2.getDenominator();
	int denominator = v1.getDenominator() * v2.getNumerator();
	return Fraction(numerator, denominator);
}

// overloading for +=
Fraction& Fraction::operator+=(const Fraction& v) {
	// add the value to the fraction and update the objects numerator and denominator.
	Fraction f = Fraction(numerator, denominator) + v;
	numerator = f.numerator;
	denominator = f.denominator;
	return *this;
}

// overloading for ++ (post increment)
Fraction& Fraction::operator++() {
	// use the previously defined += function to accomplish this
	numerator += denominator;
	return *this;
}

// overloading the ++(int) [pre increment]
Fraction Fraction::operator++(int v) {
	// since we'll be adding the value first, make the object and then perform the previously defined += operator
	Fraction f(numerator, denominator);
	numerator += denominator;
	return f;
}

// overloading the < operator
bool operator<(const Fraction& v1, const Fraction& v2) {
	// will return true or false. They must have the same denominator for this to be correct so cross multiply
	return (v1.getNumerator() * v2.getDenominator())
			< (v2.getNumerator() * v1.getDenominator());
}

// overloading the <= operator
bool operator<=(const Fraction& v1, const Fraction& v2) {
	return (v1.getNumerator() * v2.getDenominator())
			<= (v2.getNumerator() * v1.getDenominator());
}

// overloading the == operator
bool operator==(const Fraction& v1, const Fraction& v2) {
	// since it will only return true if the fractions are the same, can compare numerators and denominators of the values. Must use && since they both must be equal
	return (v1.getNumerator() == v2.getNumerator())
			&& (v1.getDenominator() == v2.getDenominator());
}

// overloading the != operator
bool operator!=(const Fraction& v1, const Fraction& v2) {
	// unlike the == only one side of the expression must be true, as if the numerator != numerator but denominator = denominator, they are still not equal.
	return (v1.getNumerator() != v2.getNumerator())
			|| (v1.getDenominator() != v2.getDenominator());
}

// overloading the >= operator
bool operator>=(const Fraction& v1, const Fraction& v2) {
	return (v1.getNumerator() * v2.getDenominator())
			>= (v2.getNumerator() * v1.getDenominator());
}

// overloading the > operator
bool operator>(const Fraction& v1, const Fraction& v2) {
	return (v1.getNumerator() * v2.getDenominator())
			> (v2.getNumerator() * v1.getDenominator());
}

// appending the divisor sign to make things easier
ostream& operator<<(ostream& out, const Fraction& v) {
	out << v.getNumerator() << "/" << v.getDenominator();
	return out;
}

istream& operator>>(istream& input, Fraction& fraction) {
	int fracNumerator;
	int fracDenominator;
	input >> fracNumerator;
	if (input.peek() != 10) {
		char nextChar;
		input >> nextChar;
		if (nextChar != '/') // skip the / sign
			fracDenominator = 1; // there is no / so just return 1 (whole number)
		else
			input >> fracDenominator; // get the denominator
		fraction = Fraction(fracNumerator, fracDenominator);
	} else
		fraction = Fraction(fracNumerator);
	return input;
}
// fraction exception class
FractionException::FractionException(const string& message) :
		errorMessage(message) {
}
string FractionException::what() {
	return errorMessage;
}

