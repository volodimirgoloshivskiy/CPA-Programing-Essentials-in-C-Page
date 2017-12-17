// Lab355.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<math.h>
#include <iomanip>

using namespace std;
class Fraction
{
public:
	Fraction(int numerator, int denominator);
	string toString();
	double toDouble();
private:
	int numerator;
	int denominator;
	int wholePart = NULL;
};
Fraction::Fraction(int numerator, int denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
}
string Fraction::toString()
{
	if (numerator%denominator == 0)
	{
		return to_string(numerator / denominator);
	}
	if (abs(denominator) < abs(numerator))
	{
		wholePart = numerator / denominator;
		numerator = numerator % denominator;
		if (denominator < 0 || numerator<0)
		{
			return  to_string(wholePart) + " " + to_string(abs(numerator)) + " / " + to_string(abs(denominator));
		}
		return to_string(wholePart) + " " + to_string(abs(numerator)) + " / " + to_string(abs(denominator));
	}
	if (denominator < 0 || numerator<0)
	{
		return  " - " + to_string(abs(numerator)) + " / " + to_string(abs(denominator));
	}
	return to_string(abs(numerator)) + " / " + to_string(abs(denominator));
}

double Fraction::toDouble()
{
	return (double)numerator / denominator;
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
	cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal " << endl;
	return 0;
}