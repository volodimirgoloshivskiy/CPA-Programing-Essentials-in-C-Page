// LAB658.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <string>
using namespace std;

class IPAdd
{
private:
	string ip;

public:
	IPAdd();
	IPAdd(string ipAdress);
	string ToString();
};

IPAdd::IPAdd()
{
	this->ip = "0.0.0.0";
}

IPAdd::IPAdd(string ipAdress)
{
	this->ip = ipAdress;
}

string IPAdd::ToString()
{
	return this->ip;
}


struct IPArray {
	int number;
	IPAdd *ipadd;
};


class Network
{
private:
	IPArray iparray;
public:
	Network();
	Network(IPArray addresses);
	void PrintAdressses();
	void AddAddress(IPAdd newAddress);
};

Network::Network()
{
	this->iparray = IPArray();
}

Network::Network(IPArray addresses)
{
	this->iparray = addresses;
}

void Network::AddAddress(IPAdd newAddress)
{
	IPAdd *copied;

	copied = new IPAdd[this->iparray.number + 1];

	for (int i = 0; i < this->iparray.number; i++) {
		copied[i] = this->iparray.ipadd[i];
	}

	delete[] this->iparray.ipadd;

	copied[this->iparray.number] = newAddress;
	this->iparray.ipadd = copied;
	this->iparray.number++;
}

void Network::PrintAdressses()
{
	for (int i = 0; i < this->iparray.number; i++)
		cout << this->iparray.ipadd[i].ToString() << endl;
}


int main()
{
	string ip;
	Network *Network_1 = new Network();
	Network *Network_2 = new Network();

	for (int i = 0; i < 2; i++)
	{
		cin >> ip;
		Network_1->AddAddress(IPAdd(ip));
	}

	cin >> ip;
	Network_1->AddAddress(IPAdd(ip));
	Network_2->AddAddress(IPAdd(ip));

	for (int i = 0; i < 2; i++)
	{
		cin >> ip;
		Network_2->AddAddress(IPAdd(ip));
	}

	cout << "Network 1: " << endl;
	Network_1->PrintAdressses();

	cout << "Network 2: " << endl;
	Network_2->PrintAdressses();

	return 0;
}