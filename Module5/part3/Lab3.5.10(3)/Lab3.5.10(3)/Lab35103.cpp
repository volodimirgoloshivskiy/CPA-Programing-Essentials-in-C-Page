// Lab35103.cpp: определяет точку входа для консольного приложения.
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
		 bool Contains(Point2D point);
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
bool Line2D::Contains(Point2D point)
{
	if (point.getY() == this->slope*point.getX() + this->y_intercept)
		return true;
	else
		return false;
};

int main()
{
	double x1, x2, y1, y2, x3, y3;
	cout << "Enter coordinates first point:" << endl;
	cin >> x1 >> y1;
	cout << "Enter coordinates second point:" << endl;
	cin >> x2 >> y2;
	Point2D firstpoint(x1, y1), secondpoint(x2, y2);
	Line2D line(firstpoint, secondpoint);
	cout << "Enter coordinates contained point:" << endl;
	cin >> x3 >> y3;
	Point2D containedPoint(x3, y3);
	if (line.Contains(containedPoint))
		cout << "collinear" << endl;
	else
		cout << "not collinear" << endl;
	return 0;
}