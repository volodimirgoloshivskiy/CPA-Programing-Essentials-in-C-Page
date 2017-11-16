// Lab232.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include<iostream>
#include <math.h>
using namespace std;
int main(void){
	double pi4 = 0.;
	long   n;
	cout << "Number of iterations? ";
	cin >> n;
	
	for (int o = 0; o < n; o++)
	{
		pi4 += pow(-1, o) / (double)(2 * o + 1);
	}

	cout.precision(20);
	cout << "Pi = " << (pi4 * 4.) << endl;
	return 0;
}

