// Lab738.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <string>
using namespace std;
class IPAddress
{
private:
	int range;
	string address;

public:
	IPAddress(string address, int range);
};
IPAddress::IPAddress(string address, int range)
{
	int octetcsCount = 0;
	int index = -1;
	while (address.find(address, index + 1) != -1)
		octetcsCount++;
	octetcsCount++;
	if (octetcsCount != 4)
		throw;
}

int main()
{
	return 0;
}
