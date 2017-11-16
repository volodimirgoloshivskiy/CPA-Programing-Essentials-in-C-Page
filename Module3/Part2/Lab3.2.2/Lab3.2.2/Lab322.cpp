// Lab322.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int main(void)
{
	int matrix[10][10] = {};
	int *pointerone, *pointertwo, *pointerthree;
	pointerone = &matrix[0][0];
	pointertwo = pointerone;
	pointerthree = pointerone;
	pointertwo++;
	for (int i = 0; i <10; i++)
	{
		*pointerone = i + 1;
		*pointertwo = *pointerone;
		for (int j = 0; j < 9; j++)
		{
			*pointertwo = *pointerone + *pointerthree;
			pointertwo++;
			pointerthree++;
		}
		pointertwo += 1;
		pointerthree += 1;
		pointerone += 10;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout.width(4);
			cout << matrix[i][j];
		}
		cout << endl;
	}
	return 0;
}