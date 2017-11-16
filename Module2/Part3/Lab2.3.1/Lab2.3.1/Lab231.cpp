// Lab231.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	int c0;
	do
	{
		cout << "Enter positive number" << endl;
		cin >> c0;
	} while (c0 <= 0);

	int i = 0;
	do
	{
		if (c0 % 2 == 0)
		{
			c0 /= 2;
		}
		else if (c0 % 2 != 0)
		{
			c0 = c0 * 3 + 1;
		}
		cout << c0 << endl;
		i++;
	} while (c0 != 1);
	cout << "Steps= " << i << endl;
	return 0;
}

