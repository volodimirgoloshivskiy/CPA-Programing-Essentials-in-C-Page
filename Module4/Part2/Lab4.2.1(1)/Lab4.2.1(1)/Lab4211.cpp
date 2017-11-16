// Lab4211.cpp: определяет точку входа для консольного приложения.
//
//Дивні назви лаб так що я помітив першу в якій було необхідно створити суматор
#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	unsigned long res = 0;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		res += i;
	}
	cout << res << endl;
	return 0;
}