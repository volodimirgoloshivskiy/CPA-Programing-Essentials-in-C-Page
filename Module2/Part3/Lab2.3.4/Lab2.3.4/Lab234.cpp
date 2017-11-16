// Lab234.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
s
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	double result = 1;
	cout << "Enter power" << endl;
	cin >> n;


	for (int i = 0; i < fabs(n); i++)
	{
		result /= 2;
	}
	cout << fixed << setprecision(20) << result << endl;
	return 0;
}