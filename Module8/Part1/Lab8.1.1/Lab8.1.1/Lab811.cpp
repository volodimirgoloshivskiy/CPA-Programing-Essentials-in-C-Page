// Lab811.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Matrix
{
private:
	int val[2][2];
public: void Print()
{
	cout << val[0][0] << val[0][1] << "\n" << val[1][0] << val[1][1] << endl;
}
		void SetVal()
		{
			cin >> val[0][0] >> val[0][1] >> val[1][0] >> val[1][1];
		}
};



int main()
{
	Matrix matrix;
	matrix.SetVal();
	matrix.Print();
	return 0;
}