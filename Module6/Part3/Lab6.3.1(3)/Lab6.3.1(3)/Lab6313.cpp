// Lab6313.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class IPAdd
{
public:
	IPAdd()
	{
		this->ip = "0.0.0.0";
	}
	IPAdd(string ip)
	{
		this->ip = ip;
	}
	IPAdd(IPAdd *ip)
	{
		this->ip = ip->ip;
	}

	virtual void Print()
	{
		cout << this->ip;
	}

protected:
	string ip;
};

class CheckedIP : public IPAdd
{
public:
	CheckedIP()
	{
		isCorrect = true;
	}
	CheckedIP(string ip) : IPAdd(ip)
	{
		this->isCorrect = this->Check();
	}
	CheckedIP(CheckedIP *ip) : IPAdd(ip)
	{
		isCorrect = ip->isCorrect;
	}

	void Print()
	{
		IPAdd::Print();
		cout << " -" << (this->isCorrect ? " " : " Not ") << "correct";
	}
private:
	bool isCorrect;

	bool Check()
	{
		string currentOctet;
		int index = -1;
		int dotsCount = 0;

		while ((index = this->ip.find('.', index + 1)) != -1)
			dotsCount++;

		if (dotsCount < 3)
			return false;

		index = -1;

		for (int i = 0; i < 4; i++)
		{
			if (i == 3)
			{
				currentOctet = this->ip.substr(index + 1);
			}
			else
			{
				currentOctet = this->ip.substr(index + 1,
					this->ip.find('.', index + 1) - index - 1);
			}

			index = this->ip.find('.', index + 1);

			try
			{
				if (stoi(currentOctet) < 0 || stoi(currentOctet) > 255)
					return false;
			}
			catch (invalid_argument)
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	IPAdd **ipc = new IPAdd*[3];
	string ip;

	getline(cin, ip);
	ipc[0] = new IPAdd(ip);

	getline(cin, ip);
	ipc[1] = new CheckedIP(ip);

	getline(cin, ip);
	ipc[2] = new CheckedIP(ip);


	for (int i = 0; i < 3; i++)
	{
		ipc[i]->Print();
		cout << endl;
	}

	return 0;
}