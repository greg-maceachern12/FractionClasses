/*
 * fraction.h
 *
 *  Created on: Oct 17, 2018
 *      Author: greg maceachern
 */

#ifndef FRACTIONS_15GJM2_H_
#define FRACTIONS_15GJM2_H_

#include <iostream>
#include <string>

using namespace std;

// exception class
class FractionException {
private:
	string errorMessage; // error message
public:
	FractionException(const string& msg); // constructor for the exception
	string what(); // returns the specific error message
};

class Fraction {
//	all private variables for the fraction class
private:
	int denominator;
	int numerator;
	int greatestCommonDenominator(int, int); //function to calculate the gcd of two numbers

public:
	Fraction(); // 0/1
	Fraction(int); //numerator is 1
	Fraction(int, int); //numerator, denominator

	int getNumerator() const; //getter for numerator
	int getDenominator() const; //getter for denominator

	//Operator Overloads
	friend Fraction operator-(const Fraction& v1, const Fraction& v2); // subtraction operator

	friend Fraction operator+(const Fraction& v1, const Fraction& v2); // addition/positive operator
	friend Fraction operator/(const Fraction& v1, const Fraction& v2); // division operator
	friend Fraction operator*(const Fraction& v1, const Fraction& v2); // multiplication operator
	Fraction operator-(); //negative operator

	Fraction& operator++(); // post increment addition operator
	Fraction operator++(int); // pre increment addition operator
	Fraction& operator+=(const Fraction& v); // add to variable operator

	friend bool operator<(const Fraction& v1, const Fraction& v2); // less than operator
	friend bool operator>(const Fraction& v1, const Fraction& v2); // greater than operator
	friend bool operator==(const Fraction& v1, const Fraction& v2); // equal to operator
	friend bool operator!=(const Fraction& v1, const Fraction& v2); // not equal to operator
	friend bool operator<=(const Fraction& v1, const Fraction& v2); // less or equal to operator
	friend bool operator>=(const Fraction& v1, const Fraction& v2); // greater or equal to operator

	friend ostream& operator<<(ostream& out, const Fraction& v); // output stream operator
	friend istream& operator>>(istream& in, Fraction& retFrac); // input stream operator


};

#endif /* FRACTIONS_15GJM2_H_ */

