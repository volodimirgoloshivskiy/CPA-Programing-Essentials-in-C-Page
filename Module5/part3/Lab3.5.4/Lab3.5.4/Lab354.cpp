// Lab354.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class Subscription
{
public:
	Subscription()
	{
		this->id = 0;
		this->ownerName = "Unknown";
		this->validityInMonths = 0;
	}
	Subscription(int id, int validityInMonths, string ownerName)
	{
		if (id < 0)
			id = 0;

		this->id = id;

		if (validityInMonths < 0)
			validityInMonths = 0;

		this->validityInMonths = validityInMonths;

		if (ownerName.length() == 0)
			ownerName = "Unknown";

		this->ownerName = ownerName;
	}

private:
	int id;
	int validityInMonths;
	string ownerName;

public:
	int GetId()
	{
		return this->id;
	}
	bool Extend(int numOfMonths)
	{
		if (numOfMonths <= 0)
			return false;

		validityInMonths += numOfMonths;
		return true;
	}
	bool Cancel()
	{
		if (validityInMonths == 0)
			return false;

		validityInMonths = 0;
		return true;
	}
	string GetInfo()
	{
		return "Subscription ID: " + to_string(this->id) + ". Valid for "
			+ to_string(this->validityInMonths) + " months. Owner is "
			+ this->ownerName + ".";
	}
};

void ShowAllSubscriptions(Subscription*subscriptions, int count)
{
	bool subscriptionsNotFound = true;

	for (int i = 0; i < count; i++)
	{
		if (subscriptions[i].GetId() != 0)
		{
			subscriptionsNotFound = false;
			cout << subscriptions[i].GetInfo() << endl;
		}
	}
	if (subscriptionsNotFound)
	{
		cout << "There are no subscriptions in the system!" << endl;
	}
}

string Trim(string str)
{
	while (str[0] == ' ')
		str.erase(0, 1);

	while (str[str.length() - 1] == ' ')
		str.erase(str.length() - 1, 1);

	return str;
}

string RemoveExtraSpaces(string str)
{
	int index = 0;
	while ((index = str.find("  "), index) != -1)
		str = str.replace(index, 2, " ");

	return str;
}

string* SplitBySpace(string str, int &wordsCount)
{
	int begin = 0, end, index = -1;
	string* words;

	wordsCount = 0;

	str = Trim(str);

	str = RemoveExtraSpaces(str);

	while ((index = str.find(' ', index + 1)) != -1)
		wordsCount++;

	wordsCount++;
	words = new string[wordsCount];

	index = 0;

	while ((end = str.find(' ', begin)) != -1)
	{
		words[index] = str.substr(begin, end - begin);
		index++;

		begin = end + 1;
	}

	words[index] = str.substr(begin);

	return words;
}

int SearchById(Subscription*subscriptions, int id)
{
	for (int i = 0; i < 10; i++)
	{
		if (subscriptions[i].GetId() == id)
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	Subscription subscriptions[10];
	Subscription nonExisting;
	string command;
	string* splitedCommand;
	int wordsCount = 0;
	int idInArray;

	while (command != "quit")
	{
		ShowAllSubscriptions(subscriptions, 10);

		cout << "Enter command: ";
		getline(cin, command);

		splitedCommand = SplitBySpace(command, wordsCount);

		if (splitedCommand[0] == "extend")
		{

			if (wordsCount < 3)
			{
				cout << "Invalid paramters!" << std::endl;
				continue;
			}

			idInArray = SearchById(subscriptions, stoi(splitedCommand[1]));

			if (idInArray != -1)
			{
				if (!subscriptions[idInArray].Extend(stoi(splitedCommand[2])))
				{
					cout << "Invalid month count parameter!" << endl;
				}
			}

			else
			{
				cout << "Subscription with ID " << splitedCommand[1]
					<< " was not found!" << endl;
			}
		}
		else if (splitedCommand[0] == "cancel")
		{
			if (wordsCount < 2)
			{
				cout << "Invalid paramters!" << endl;
				continue;
			}

			idInArray = SearchById(subscriptions, stoi(splitedCommand[1]));

			if (idInArray != -1)
			{
				if (!subscriptions[idInArray].Cancel())
				{
					cout << "Validity month count was 0 before operation!" << endl;
				}
			}
			else
			{
				cout << "Subscription with ID " << splitedCommand[1]
					<< " was not found!" << endl;
			}
		}
		else if (splitedCommand[0] == "delete")
		{
			if (wordsCount < 2)
			{
				cout << "Invalid paramters!" << endl;
				continue;
			}

			idInArray = SearchById(subscriptions, stoi(splitedCommand[1]));

			if (idInArray != -1)
			{
				subscriptions[idInArray] = nonExisting;
			}
			else
			{
				cout << "Subscription with ID " << splitedCommand[1]
					<< " was not found!" << endl;
			}
		}
		else if (splitedCommand[0] == "create")
		{
			if (wordsCount < 4)
			{
				cout << "Invalid paramters!" << endl;
				continue;
			}

			idInArray = SearchById(subscriptions, std::stoi(splitedCommand[1]));

			if (idInArray != -1)
			{
				std::cout << "Subscription with ID " << splitedCommand[1]
					<< " already exists!" << std::endl;
			}
			else
			{
				idInArray = SearchById(subscriptions, 0);

				if (idInArray == -1)
				{
					cout << "Unfortunately, all subscriptions are used!" << endl;
				}
				else
				{
					subscriptions[idInArray] = Subscription
					(
						stoi(splitedCommand[1]),
						0,
						splitedCommand[2] + " " + splitedCommand[3]
					);
				}
			}
		}
	}

	return 0;
}