// Lab713711.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int main(void)
{
	int a = 0, b = 0, c = 0;
	cin >> b;
	cin >> a;
	try
	{
		if (b == 0)
			throw string("You can`t divide by zero!");
		c = a / b;
	}
	catch (string &mistake)
	{
		cout << mistake << endl;
	}
	cout << c << endl;
	return 0;
}