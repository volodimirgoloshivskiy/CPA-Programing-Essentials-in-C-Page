// Lab233.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

int main()
{
	double n, power = 1;
	do
	{
		cout << "vvedit stepin" << endl;
		cin >> n;
	} while (n < 0 || n>63);//proverka na oshibki
	for (size_t i = 0; i < n; i++)
	{
		power *= 2;
	}
	cout << fixed << power << endl;
	return 0;
}