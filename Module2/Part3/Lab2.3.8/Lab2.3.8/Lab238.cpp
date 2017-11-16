// Lab238.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	int n;
	double f = 1;
	cout << "Enter number of rotation" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		f *= i;
	}
	cout << fixed << (int)f << endl;
	return 0;
}