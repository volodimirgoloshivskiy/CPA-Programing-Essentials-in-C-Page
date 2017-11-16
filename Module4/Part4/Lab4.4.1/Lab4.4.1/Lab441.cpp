// Lab441.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream> 
#include <string> 

using namespace std;

int Pangramcheck(int i, string pangram, string letters[])
{
	int j = 0;
	for (int k = 0; k <= pangram.length(); k++)
	{
		if (pangram.substr(k, 1) == (letters[i]))
		{
			j++;
		}
	}
	return j;
}
int main(void) {
	string pangram;
	string letters[] = { "a","b","c","d","e","f","g","h","i","j","k","l",
		"m","n","o","p","q","r","s","t","u","v","w","x","y","z" };
	getline(cin, pangram);

	for (int i = 0; i < 26; i++)
	{
		cout << letters[i] << "=" << Pangramcheck(i, pangram, letters) << endl;
	}
	return 0;
}