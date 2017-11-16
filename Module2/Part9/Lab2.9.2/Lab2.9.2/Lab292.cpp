// Lab292.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	int banknote[5] = { 50,20,10,5,1 };
	int money;
	cin >> money;
	do
	{
		for (int i = 0; i < 5; i++)
		{
			for (;;)
			{
				if (money >= banknote[i])
				{
					money -= banknote[i];
					cout << banknote[i] << " ";
				}
				else
					break;
			}
		}
	} while (money != 1);
	return 0;
}