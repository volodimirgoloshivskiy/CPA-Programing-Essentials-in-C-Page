// Lab2111.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	struct TimeOfDay
	{
		int hour, minute;
	};
	TimeOfDay Clock;
	int moment;
	do
	{
		cout << "hour 0-24" << endl;
		cin >> Clock.hour;
	} while (Clock.hour<0 || Clock.hour>24);
	do
	{
		cout << "minute 0-59" << endl;
		cin >> Clock.minute;
	} while (Clock.minute<0 || Clock.minute >= 60);
	cout << "time of moment" << endl;
	cin >> moment;

	Clock.minute += moment;
	if (Clock.minute >= 60)
	{
		Clock.hour += Clock.minute / 60;
		if (Clock.hour>23)
		{
			Clock.hour %= 24;
		}
		Clock.minute %= 60;
	}

	cout << Clock.hour << ":" << Clock.minute << endl;
	return 0;
}
