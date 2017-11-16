// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main(void) {
	bool answer;
	int value;
	cout << "Enter a value: ";
	cin >> value;
	if (answer = 0 <= value < 10) {
		cout << (answer ? "THAT'S TRUE :)" : "THAT'S NOT TRUE :(") << endl;
		return 0;
	}
	if (answer = 0 < value < 10) {
		cout << (answer ? "THAT'S TRUE :)" : "THAT'S NOT TRUE :(") << endl;
		return 0;
	}
	if (answer = 2 < value < 20) {
		cout << (answer ? "THAT'S TRUE :)" : "THAT'S NOT TRUE :(") << endl;
		
		return 0;
	}
	if (answer =  value == 111) {
		cout << (answer ? "THAT'S TRUE :)" : "THAT'S NOT TRUE :(") << endl;
		return 0;
	}
	
}

