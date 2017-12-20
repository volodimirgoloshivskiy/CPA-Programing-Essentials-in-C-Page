// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//your code
int x = 15;
bool linecheck(int i, int j) {
	if (abs(i - j) <= x)
		return true;
	else
		return false;
}
int main()
{
	vector<int> original_values =
	{ 210, 314, 202, 110, 211, 302, 358, 229, 260, 411, 412, 311, 373, 483 };
	vector<int> noisy_values =
	{ 211, 324, 203, 113, 227, 320, 340, 210, 239, 411, 412, 333, 371, 501 };
	//your code
	pair <vector<int>::iterator, vector<int>::iterator>
		mycheck;
	do {
	
		mycheck = mismatch(original_values.begin(), original_values.end(), noisy_values.begin(), linecheck);
	cout << "First difference greater than " << x << " is found: " << *mycheck.first << " - " << *mycheck.second << endl;
	x++;
	} while (mycheck.first!=original_values.end());
	return 0;
}