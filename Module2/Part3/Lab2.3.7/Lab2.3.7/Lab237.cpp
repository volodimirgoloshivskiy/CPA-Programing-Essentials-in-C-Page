// Lab237.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
using namespace std;
int main()
{
	double f1 = 1, f2 = 1, f3;
	int n;
	cout << "Enter number of rotation" << endl;
	cin >> n;
	for (int i = 0; i <n - 2; i++)
	{
		f3 = f1;
		f1 += f2;
		f2 = f3;
	}
	cout << f1 << endl;
	return 0;
}