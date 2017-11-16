// Lab346.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int number)
{
	if (number < 2)
		return false;
	for (int i = 2; i < number; i++)
	{
		if (number%i == 0)
		{
			return false;
			break;
		}
	}
}
int main(void)
{
	for (int i = 0; i <= 21; i++)
		if (isPrime(i))
			cout << i << " ";
	cout << endl;
	return 0;
}