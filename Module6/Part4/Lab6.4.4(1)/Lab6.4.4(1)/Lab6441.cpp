// Lab6441.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
class StringValidator
{
public:virtual ~StringValidator() {};
	   virtual bool isValid(string input) = 0;
};

class ExactValidator :public StringValidator
{
private:string password;
public:virtual bool isValid(string input);

	   ExactValidator(string passwd)
	   {
		   this->password = passwd;
	   }
};
bool ExactValidator::isValid(string input)
{
	if (input == this->password)
		return true;
	return false;
};

class DummyValidator : public StringValidator
{
public:virtual bool isValid(string input);
};
bool DummyValidator::isValid(string input)
{
	return true;
};
void printValid(StringValidator &validator, string input)
{
	cout << "The string '" << input << "' is " << (validator.isValid(input) ? "valid" : "invalid") << endl;
};

int main() {
	DummyValidator dummy;
	printValid(dummy, "hello");
	cout << endl;
	ExactValidator exact("secret");
	printValid(exact, "hello");
	printValid(exact, "secret");
	return 0;
}