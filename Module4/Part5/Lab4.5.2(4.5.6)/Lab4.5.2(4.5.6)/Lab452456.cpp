// Lab452456.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include<string>
#include<iostream>
int main()
{
	std::string sentence;
	std::getline
	(std::cin, sentence);
	bool END;
	for (int i = 0; i < sentence.length(); i++)
	{
		do
		{
			END = false;
			if (sentence.substr(i, 1) == " " && sentence.substr(i + 1, 1) == " ")
			{
				sentence.erase(i + 1, 1);
				END = true;
			}
		} while (END);
	}
	std::cout << sentence << "\n";
}