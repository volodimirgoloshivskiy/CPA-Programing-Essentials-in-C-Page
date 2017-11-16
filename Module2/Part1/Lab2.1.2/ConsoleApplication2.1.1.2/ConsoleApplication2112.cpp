// ConsoleApplication2112.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main(void) {
	float grossprice, taxrate, netprice, taxvalue;
	do
	{
		cout << "Enter a gross price: ";
		cin >> grossprice;
	} 
	while (grossprice <= 0);
	do
	{
		cout << "Enter a tax rate: ";
		cin >> taxrate;
	} while (taxrate<0 || taxrate >100);
	netprice = (grossprice * 100) / (100 + taxrate);
	taxvalue = grossprice - netprice;
	cout << "Net price: " << netprice << endl;
	cout << "Tax value: " << taxvalue << endl;
	return 0;
}
