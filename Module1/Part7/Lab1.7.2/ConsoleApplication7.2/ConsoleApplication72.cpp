// ConsoleApplication72.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main(void)
{
	float loli, loki;
	cin >> loki;
	cin >> loli;
	cout << ((abs(loki-loli)<0.000001) ? "Results are equal (by 0.000001 epsilon) " : "Results are not equal (by 0.000001 epsilon)") << endl;
    return 0;
}

