// Lab511.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	string name;
	int    age;
	int weight;
};
void print(Person* person)
{
	cout << person->name << " is " << person->age << " years old" << "and weight is" << person->weight << endl;
}
int main()
{
	Person person, next_person;
	person.name = "Harry";
	person.age = 23;
	person.weight = 64;
	cout << "Meet " << person.name << endl;
	print(&person);

	next_person.name = "Jane";
	next_person.age = 22;
	next_person.weight = 56;
	cout << "Meet " << person.name << endl;
	print(&next_person);
	return 0;
}
