// Lab3592.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include <iomanip>
using namespace std;
class Point2D
{
public:  Point2D(double x, double y);
		 string toString();
		 double getX();
		 double getY();
private:double x;
		double y;
};

Point2D::Point2D(double x, double y)
{
	this->x = x;
	this->y = y;
};
double Point2D::getX()
{
	return this->x;
};
double Point2D::getY()
{
	return this->y;
};


class Line2D
{
public:  Line2D(double slope, double y_intercept);
		 Line2D(Point2D pointA, Point2D pointB);
		 string toString();

private:double slope;
		double y_intercept;
};
Line2D::Line2D(Point2D a, Point2D b)
{
	this->slope = (b.getY() - a.getY()) / (b.getX() - a.getX());
	this->y_intercept = a.getY() - this->slope*a.getX();
};
string Line2D::toString()
{
	if (this->y_intercept >= 0)
		return "y=" + to_string(this->slope) + " x " + "+" + to_string(this->y_intercept);
	else
		return "y=" + to_string(this->slope) + " x " + to_string(this->y_intercept);
};


int main()
{
	double x1, x2, y1, y2;
	cout << "Enter coordinates first point:" << endl;
	cin >> x1 >> y1;
	cout << "Enter coordinates second point:" << endl;
	cin >> x2 >> y2;
	Point2D firstpoint(x1, y1), secondpoint(x2, y2);
	Line2D line(firstpoint, secondpoint);
	cout << line.toString() << endl;
	return 0;
}