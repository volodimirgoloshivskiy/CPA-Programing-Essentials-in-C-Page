// Lab295.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int main(void)
{
	double matrix[][4] = { { 1, 2, 3, 4 },
	{ 2, 2, 3, 1 },
	{ 3, 3, 3, 2 },
	{ 4, 1, 2, 4 } };
	int side = sizeof(matrix[0]) / sizeof(matrix[0][0]);
	bool issymmetric = true;
	for (int i = 0; i < side; i++)
	{
		for (int k = 0; k < side; k++)
		{
			if (i == k)
				continue;
			else if (matrix[i][k] != matrix[k][i])
			{
				issymmetric = false;
				break;
			}
		}
	}
	if (issymmetric)cout << "The matrix is symmetric" << endl;
	else cout << "The matrix is not symmetric" << endl;
	return 0;
}