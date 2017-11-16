// Lab361.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
void increment(int &var, int current = 1)
{
	var += current;
}
int main(void)
{
	int var = 0;
	for (int i = 0; i < 10; i++)
		if (i % 2)
			increment(var);
		else   increment(var, i);
		cout << var << endl;
		return 0;
}