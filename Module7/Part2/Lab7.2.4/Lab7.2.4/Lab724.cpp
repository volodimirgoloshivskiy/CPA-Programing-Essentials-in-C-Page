// Lab724.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include<iostream>
#include <string>
using namespace std;


class MyException
{
public:
	string message;
	MyException(string txt) : message(txt) {}
};
float square_area(float a)
{
	if (a <= 0)
		throw MyException("Your input is not valid. The area can't be negative.");
	return a*a;
}
float rectangle_area(float a, float b)
{
	if (a <= 0)
		throw MyException("Your input is not valid. The area can't be negative.");
	if (b <= 0)
		throw MyException("Your input is not valid. The area can't be negative.");
	return a*b;
}
int main(void)
{
	float a, b;
	cin >> a;
	cin >> b;
	try
	{
		float rsquare = square_area(a);
		float rrectangle = rectangle_area(a, b);
		cout << rsquare << endl << rrectangle << endl;
	}
	catch (MyException exception)
	{
		cout << exception.message << endl;
	}
	return 0;
}