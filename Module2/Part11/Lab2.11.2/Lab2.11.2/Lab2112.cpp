// Lab2112.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	struct StartTime
	{
		int startH;
		int startM;
	};
	struct EndTime
	{
		int endH;
		int endM;
	};
	StartTime stt;
	EndTime ent;
	int diffHour, diffMinute;
	cout << "Enter StartTime" << endl;
	cin >> stt.startH;
	cin >> stt.startM;
	do
	{
		cout << "Enter EndTime" << endl;
		cin >> ent.endH;
		cin >> ent.endM;
	} while (stt.startH > ent.endH);

	if (ent.endM >= stt.startM)
	{
		diffHour = ent.endH - stt.startH;
		diffMinute = ent.endM - stt.startM;
	}
	else
	{
		diffMinute = (60 - stt.startM) + ent.endM;
		diffHour = ent.endH - stt.startH - 1;
	}
	cout << diffHour <<" "<< diffMinute;
	return 0;
}