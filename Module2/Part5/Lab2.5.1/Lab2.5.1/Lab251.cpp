// Lab251.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	for (;;)
	{
		int i;
		float a, b, c;
		cout << "MENU:\n0-exit\n1-addition\n2-substraction\n3-multiplication\n4-division\nYour choise?" << endl;
		cin >> i;
		switch (i)
		{
		case 0:exit(0); break;
		case 1:puts("a+b enter a ,enter b");
			cin >> a;
			cin >> b;
			c = a + b;
			cout << c << endl;
			break;
		case 2:puts("a-b enter a ,enter b");
			cin >> a;
			cin >> b;
			c = a - b;
			cout << c << endl;
			break;
		case 3:puts("a*b enter a ,enter b");
			cin >> a;
			cin >> b;
			c = a * b;
			cout << c << endl;
			break;
		case 4:puts("a/b enter a ,enter b");
			cin >> a;
			cin >> b;
			c = a / b;
			cout << c << endl;
			break;
		default:puts("Invalid command");
			break;
		}
		cout << "\n";
	}
	return 0;
}