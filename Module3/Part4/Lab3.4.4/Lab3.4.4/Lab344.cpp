// Lab344.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include <iostream>
using namespace std;
struct Date {
	int year;
	int month;
	int day;
};
bool isLeap(int year) {
	if (year % 4 == 0)
		return true;
	else
		return false;
}
int monthLength(int year, int month)
{
	int monthVector[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeap(year))
	{
		monthVector[1] = 29;
		return monthVector[month - 1];
	}
	else
		return monthVector[month - 1];
}
int dayOfYear(Date date)
{
	int lenght = 0;
	for (int i = 1; i <date.month; i++)
	{
		lenght += monthLength(date.year, i);
	}
	lenght += date.day;
	return lenght;

}
int daysBetween(Date d1, Date d2)
{
	int lenght = 0;

	if (d1.year > d2.year)
	{
		return -1;
	}
	else if (d1.year == d2.year&&dayOfYear(d1) - dayOfYear(d2)>0)
	{
		return -1;
	}
	for (int i = d1.year; i <d2.year; i++)
	{
		if (isLeap(i))
			lenght += 366;
		else
			lenght += 365;
	}
	lenght += dayOfYear(d2) - dayOfYear(d1);
	return lenght;
}
int main()
{
	Date since, till;
	cout << "Enter first date (y m d): ";
	cin >> since.year >> since.month >> since.day;
	cout << "Enter second date (y m d): ";
	cin >> till.year >> till.month >> till.day;
	cout << daysBetween(since, till) << endl;
}