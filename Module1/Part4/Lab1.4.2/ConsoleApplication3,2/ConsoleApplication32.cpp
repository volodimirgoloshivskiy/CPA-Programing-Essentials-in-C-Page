// ConsoleApplication32.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main(void) {
	float pi = 3.14159265359;
	float x, y;
	float pi2 = pi*pi;
	cout << "Enter value for x: ";
	cin >> x;
	float x2 = x*x;
	y = x2*(1+x2/(pi2*(x2-0.5)*(x2-0.5)))/(pi2*(x2+0.5));// put your code here
	cout << "y = " << y;
	return 0;
}

