// Lab235.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int main(void) {
	int n;
	do
	{
		cout << "Enter value bettwen 1 & 14" << endl;
		cin >> n;
		if (n <= 1 || n >= 14)
		{
			cout << "Invalid Value";
		}
	} while (n <= 1 || n >= 14);


	cout << '+';
	for (int i = 0; i < n; i++)
		cout << '-';

	cout << '+' << endl;
	for (int i = 0; i < n; i++)
	{
		cout << '|';
		for (int j = 0; j < n; j++)
			cout << ' ';
		cout << '|' << endl;
	}

	cout << '+';
	for (int i = 0; i < n; i++)
		cout << '-'; cout << '+' << endl;
	return 0;
}
