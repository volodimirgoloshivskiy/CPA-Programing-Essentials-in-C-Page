// Lab3102.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
struct Collection
{
	int  elno;
	int *elements;
};
void AddToCollection(Collection &col, int element)
{
	int *copy;

	copy = new int[col.elno + 1];

	for (int i = 0; i < col.elno; i++) {
		copy[i] = col.elements[i];
	}

	delete[] col.elements;

	copy[col.elno] = element;
	col.elements = copy;
	col.elno++;
}
void PrintCollection(Collection col)
{
	cout << "[ ";
	for (int i = 0; i < col.elno; i++)
		cout << col.elements[i] << " ";
	cout << "]" << endl;
}
int main(void)
{
	Collection collection = { 0, NULL };
	int elems;
	cout << "How many elements? ";
	cin >> elems;
	srand(time(NULL));
	for (int i = 0; i < elems; i++)
		AddToCollection(collection, rand() % 100 + 1);
	PrintCollection(collection);
	delete[] collection.elements;
	return 0;
}