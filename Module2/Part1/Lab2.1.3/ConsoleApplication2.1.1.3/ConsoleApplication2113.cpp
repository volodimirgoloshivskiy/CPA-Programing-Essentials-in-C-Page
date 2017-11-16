// ConsoleApplication2113.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main()
{
	int   sys;
	float m, foot, in, integer;
	cout << " 0 if metric,1 if imperial" << endl;
	cin >> sys;
	if (sys == 0)
	{
		cout << "Enter Distance" << endl;
		cout << "Metres:" << endl;
		cin >> m;
		in = m*39.37;
		float fractional = modf(in, &integer);
		foot = integer / 12;
		in = (int)integer % 12 + fractional;
		cout << (int)foot << "'" << fixed << setprecision(5) << in << "\"";

	}
	else if (sys == 1)
	{
		cout << "Enter Distance" << endl;
		cout << "Foots:" << endl;
		cin >> foot;
		cout << "Inches:" << endl;
		cin >> in;
		m = (foot * 12 + in) / 39.37;
		cout << m << "m";
	}
	return 0;
}

