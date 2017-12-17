// Lab512.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include<iostream>
#include<string>
using namespace std;

class Square
{
private:
	double    side;
	double    area;

public:
	void set_side(double side)
	{
		if (side > 0)
		{
			this->side = side;
			this->area = side *side;
			cout << "Square: side=" << this->side << " area=" << this->area << endl;
		}
	}
};
int main()
{
	Square s;
	s.set_side(4);
	s.set_side(2.0);
	s.set_side(-33.0);
	return 0;
}