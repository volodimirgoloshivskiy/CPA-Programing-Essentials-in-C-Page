// Lab3573.cpp: определяет точку входа для консольного приложения.
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
	bool isGreaterThan(Fraction that);
	bool isLessThan(Fraction that);
	bool isEqual(Fraction that);
private:
	int numerator;
	int denominator;
	int wholePart;
	void reduce();
};
bool Fraction::isGreaterThan(Fraction that)
{
	this->reduce();
	that.reduce();
	if ((double)this->numerator / this->denominator > (double)that.numerator / that.denominator)
		return true;
	else
		return false;
}
bool Fraction::isLessThan(Fraction that)
{
	this->reduce();
	that.reduce();
	if ((double)this->numerator / this->denominator < (double)that.numerator / that.denominator)
		return true;
	else
		return false;
}
bool Fraction::isEqual(Fraction that)
{
	this->reduce();
	that.reduce();
	if ((double)this->numerator / this->denominator == (double)that.numerator / that.denominator)
		return true;
	else
		return false;
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
	if (fraction.isGreaterThan(fraction2))
		cout << fraction.toString() << " > " << fraction2.toString() << endl;
	if (fraction.isLessThan(fraction2))
		cout << fraction.toString() << " < " << fraction2.toString() << endl;
	if (fraction.isEqual(fraction2))
		cout << fraction.toString() << " = " << fraction2.toString() << endl;
	return 0;
}