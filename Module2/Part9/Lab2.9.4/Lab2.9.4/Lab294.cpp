// Lab294.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	double line[] = { 1., 2., 3., 4., 5. };
	int n = sizeof(line) / sizeof(line[0]);
	double ArithmeticalMean;
	double HarmonicalMean;
	double GeometricalMean;
	double RootMeanSquare;
	double a = 0;
	// Insert your code here
	for (int i = 0; i < n; i++)
	{
		a += line[i];
	}
	ArithmeticalMean = a / n;
	a = 0;
	for (int i = 0; i < n; i++)
	{
		a += 1 / line[i];
	}
	HarmonicalMean = n / a;
	a = 1;
	for (int i = 0; i < n; i++)
	{
		a *= line[i];
	}
	GeometricalMean = pow(a, 1.0 / n);
	a = 0;
	for (int i = 0; i < n; i++)
	{
		a += pow(line[i], 2);
	}
	RootMeanSquare = sqrt(a / n);
	cout << "Arithmetical Mean " << ArithmeticalMean << endl;
	cout << "Harmonicac Mean " << HarmonicalMean << endl;
	cout << "Geometrical Mean " << GeometricalMean << endl;
	cout << "RootMean Square " << RootMeanSquare ;

	return 0;
}
