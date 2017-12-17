// Lab6443.cpp: определяет точку входа для консольного приложения.
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
	if (regex_search(pattern, regex("\\d")) && regex_search(pattern, regex("[a-z]")) &&
		regex_search(pattern, regex("[A-Z]")) && regex_search(pattern, regex("\\W")))
		return true;
	return false;
};

class LengthValidator : public StringValidator
{
public:  LengthValidator(int min, int max);
		 bool isValid(string input);
private:  MinLengthValidator min_validator;
		  MaxLengthValidator max_validator;
		  PatternValidator pat_val;
};
LengthValidator::LengthValidator(int min, int max) : min_validator(min), max_validator(max), pat_val("") {
}
bool LengthValidator::isValid(string input)
{
	return (!min_validator.isValid(input) && !max_validator.isValid(input) && pat_val.isValid(input));
}

void printValid(StringValidator &validator, string input)
{
	cout << "The string'" << input << "' is " << (validator.isValid(input) ? "valid" : "invalid") << endl;
}

int main()
{
	cout << "Password length must be 8 \nhave at least one upper-case letter\nhave at least one lower-case letter\nhave at least one digit\nhave at least one special character\n" << endl;
	LengthValidator val(8, 8);
	printValid(val, "a1Bfg?vd");
	return 0;
}