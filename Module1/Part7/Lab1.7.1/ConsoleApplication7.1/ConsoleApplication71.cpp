// ConsoleApplication71.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main(void)
{
	float x1 = 2.3;
	float x2 = 2.3;
	float x3= 2.12345;
	float x4 = 2.123456;
	int x5= 2.123456;
	cout << x1 << endl;
	cout.precision(2);
	cout << fixed << x2 << endl;
	cout.precision(5);
	cout << x3 << endl;
	cout.precision(2);
	cout << x4 << endl ;
	cout << x5;
    return 0;
}

