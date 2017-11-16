// Lab321.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main(void) {
	int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
	int n = sizeof(vector) / sizeof(vector[0]);
	int *pointerone, *pointertwo;
	pointerone = vector;
	pointertwo = pointerone + 1;
	for (int i = 0; i < n - 1; i++)
	{
		if (*pointerone > *pointertwo)
		{
			pointerone = pointertwo;
			pointertwo += 1;
		}
		else
		{
			pointertwo += 1;
		}
	}
	cout << *pointerone << endl;
	return 0;
}