// Lab214.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	int year, month, day, weekday;
	do
	{
		cout << "year from 1900 to 2017" << endl;
		cin >> year;
	} while (year < 1900 || year>2017);
	do
	{
		cout << "month from 1 to 12" << endl;
		cin >> month;
	} while (month < 0 || month>12);
	do
	{
		cout << "day from 1 to 31 or 20 or 29 or 28" << endl;
		cin >> day;
	} while (day < 1 || day>31);

	month -= 2;
	if (month < 0)
	{
		month += 12;
		year -= 1;
	}
	month *= 83;
	month /= 32;
	month += day;
	month += year;
	month += year / 4;
	month -= year / 100;
	month += year / 400;
	weekday = month % 7;
	cout << weekday << endl;

	return 0;

}

