// Lab241.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
size_t bit(int value)
{
	size_t count = 0;
	for (; value; value >>= 1)
		if (value & 1)
			count++;
	return count;
}
int main()
{
	unsigned long value;
	cout << "Enter value" << endl;
	cin >> value;
	cout << bit(value) << endl;
	return 0;
}
