// Lab6442.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include<iostream>
#include<string>
#include<regex>
using namespace std;
class StringValidator
{
public:virtual ~StringValidator() {};
	   virtual bool isValid(std::string input) = 0;
};

class MinLengthValidator :public StringValidator
{
	int length;
public:MinLengthValidator(int length)
{
	this->length = length;
}
	   bool isValid(string input);
};
bool MinLengthValidator::isValid(string input)
{
	if (input.length() > this->length)
		return true;
	return false;
};

class MaxLengthValidator :public StringValidator
{
private:int length;
public:MaxLengthValidator(int length)
{
	this->length = length;
}
	   bool isValid(string input);
};
bool MaxLengthValidator::isValid(string input)
{
	if (input.length() < this->length)
		return true;
	return false;
};

class PatternValidator :public StringValidator
{
private:string pattern;
public:bool isValid(string input);
	   PatternValidator(string pattern)
	   {
		   this->pattern = pattern;
	   }
};
bool PatternValidator::isValid(string pattern)
{
	if (regex_match(pattern, regex(this->pattern)))
		return true;
	return false;
};


void printValid(StringValidator &validator, string input)
{
	cout << "The string '" << input << "' is " << (validator.isValid(input) ? "valid" : "invalid") << endl;
}
int main()
{
	cout << "MinLengthValidator" << endl;
	MinLengthValidator min(6);
	printValid(min, "hello");
	printValid(min, "welcome");
	cout << endl;
	cout << "MaxLengthValidator" << endl;
	MaxLengthValidator max(6);
	printValid(max, "hello");
	printValid(max, "welcome");
	cout << endl;
	cout << "PatternValidator" << endl;
	PatternValidator digit("\\d\\d\\d");
	printValid(digit, "123");
	printValid(digit, "valid and invalid ones");
	cout << endl;
	return 0;
}