// Lab345.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include<iostream>
#include<ctime>
using namespace std;
struct Date {
	int year; int month; int day;
};
Date today(void)
{
	time_t t = time(NULL);
	tm cTime = *localtime(&t);
	Date date = { cTime.tm_year + 1900, cTime.tm_mon + 1, cTime.tm_mday };
	return date;

}
int main(void)
{
	Date t = today();
	cout << t.year << "-" << t.month << "-" << t.day << endl;
	return 0;
}