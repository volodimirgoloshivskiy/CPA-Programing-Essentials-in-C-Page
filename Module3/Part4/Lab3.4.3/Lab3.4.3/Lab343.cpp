// Lab343.cpp: определяет точку входа для консольного приложения.
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
	int Monthdays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeap(year))
	{
		Monthdays[1] = 29;
		return Monthdays[month - 1];
	}
	else
		return Monthdays[month - 1];
}
int dayOfYear(Date date)
{
	int time = 0;
	for (int i = 1; i <date.month; i++)
	{
		time += monthLength(date.year, i);
	}
	time += date.day;
	return time;

}
int main(void)
{
	Date d;
	cout << "Enter year month day: ";
	cin >> d.year >> d.month >> d.day;
	cout << dayOfYear(d) << endl;
	return 0;
}