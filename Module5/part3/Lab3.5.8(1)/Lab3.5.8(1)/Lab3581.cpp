// Lab3581.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include <math.h>
using namespace std;
class Point2D
{
public:  Point2D(double x, double y);
		 string toString();
		 double toDouble();
		 double lineTo(Point2D that);
private:
	double x;
	double y;
};
Point2D::Point2D(double x, double y)
{
	this->x = x;
	this->y = y;
};
double Point2D::lineTo(Point2D that)
{
	return sqrt(pow(that.x - this->x, 2) + pow(that.y - this->y, 2));
};


int main()
{
	double x1, x2, y1, y2;
	cout << "Enter coordinates first point:" << endl;
	cin >> x1 >> y1;
	cout << "Enter coordinates second point:" << endl;
	cin >> x2 >> y2;
	Point2D firstpoint(x1, y1), secondpoint(x2, y2);
	cout << firstpoint.lineTo(secondpoint) << endl;
	return 0;
}