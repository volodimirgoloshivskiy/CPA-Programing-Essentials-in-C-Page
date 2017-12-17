// Lab3562.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
class Fraction
{
public:
	Fraction(int numerator, int denominator);
	string toString();
	Fraction plus(Fraction that);
	Fraction minus(Fraction that);
	Fraction times(Fraction that);
	Fraction by(Fraction that);
private:
	int numerator;
	int denominator;
	int wholePart;
	void reduce();
};

Fraction Fraction::plus(Fraction that)
{
	int num = this->numerator * that.denominator + that.numerator*this->denominator;
	int den = this->denominator * that.denominator;
	Fraction result(num, den);
	result.reduce();
	return result;
}
Fraction Fraction::minus(Fraction that)
{
	int num = this->numerator * that.denominator - that.numerator*this->denominator;
	int den = this->denominator * that.denominator;
	Fraction result(num, den);
	result.reduce();
	return result;
}
Fraction Fraction::by(Fraction that)
{
	int num = this->numerator * that.denominator;
	int den = this->denominator * that.numerator;
	Fraction result(num, den);
	result.reduce();
	return result;
}
Fraction Fraction::times(Fraction that)
{
	int num = this->numerator * that.numerator;
	int den = this->denominator * that.denominator;
	Fraction result(num, den);
	result.reduce();
	return result;
}
void Fraction::reduce()
{
	int t;
	int saveNum = this->numerator;
	int saveDen = this->denominator;
	while (this->numerator != 0)
	{
		t = this->numerator;
		this->numerator = this->denominator%this->numerator;
		this->denominator = t;
	}
	this->denominator = saveDen / t;
	this->numerator = saveNum / t;
}
Fraction::Fraction(int numerator, int denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
}
string Fraction::toString()
{
	if (this->numerator%this->denominator == 0)
	{
		return to_string(this->numerator / this->denominator);
	}
	if (abs(this->denominator) < abs(this->numerator))
	{
		this->wholePart = this->numerator / this->denominator;
		this->numerator = this->numerator % this->denominator;
		if (this->denominator < 0 || this->numerator<0)
		{
			return  to_string(this->wholePart) + " " + to_string(abs(this->numerator)) + " / " + to_string(abs(this->denominator));
		}
		return to_string(this->wholePart) + " " + to_string(abs(this->numerator)) + " / " + to_string(abs(this->denominator));
	}
	if (this->denominator < 0 || this->numerator<0)
	{
		return  " - " + to_string(abs(this->numerator)) + " / " + to_string(abs(this->denominator));
	}
	return to_string(abs(this->numerator)) + " / " + to_string(abs(this->denominator));
}

int main(void)
{
	int num, den;
	string input = "";
	do
	{
		getline(cin, input);
		num = stoi(input.substr(0, input.find('/')));
		den = stoi(input.substr(input.find('/') + 1));
	} while (den == 0);
	Fraction fraction(num, den);

	do
	{
		getline(cin, input);
		num = stoi(input.substr(0, input.find('/')));
		den = stoi(input.substr(input.find('/') + 1));
	} while (den == 0);
	Fraction fraction2(num, den);

	cout << fraction.plus(fraction2).toString() << endl;
	cout << fraction.minus(fraction2).toString() << endl;
	cout << fraction.by(fraction2).toString() << endl;
	cout << fraction.times(fraction2).toString() << endl;
	return 0;
}