// Lab3101.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

bool IsPresent(int balls[], int val, int ballsCount) {
	for (int i = 0; i < ballsCount; i++) {
		if (balls[i] == val) return true;
	}
	return false;
}

int main(void) {
	int maxball;
	int ballsno;
	int *ballMachine;
	int rnd = 1;
	int generetedBallNum;
	cout << "Max ball number? ";
	cin >> maxball;
	cout << "How many balls? ";
	cin >> ballsno;
	srand(time(NULL));
	ballMachine = new int[ballsno];
	for (int i = 0; i < ballsno; i++) {
		generetedBallNum = rand() % maxball + 1;
		if (IsPresent(ballMachine, generetedBallNum, ballsno)) {
			i--;
			continue;
		}
		ballMachine[i] = generetedBallNum;
	}
	for (int i = 0; i < ballsno; i++)
		cout << ballMachine[i] << ' ';
	cout << endl;
	delete[] ballMachine;
	return 0;
}