// Lab342.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
bool isLeap(int year)
{
	if (year % 4 == 0)
		return true;
	else
		return false;
}
int monthLength(int year, int month)
{
	int Monthdays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeap(year))
	{
		Monthdays[1] = 29;
		return Monthdays[month - 1];
	}
	else
		return Monthdays[month - 1];

} int main(void)
{
	for (int yr = 2000; yr < 2002; yr++)
	{
		for (int mo = 1; mo <= 12; mo++)
			cout << monthLength(yr, mo) << " ";
		cout << endl;
	}
	return 0;
}