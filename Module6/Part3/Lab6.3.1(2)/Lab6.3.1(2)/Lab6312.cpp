// Lab6312.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

class Piece
{
public:
	Piece() { x = 98; y = 1; }

protected:
	char x;
	int y;

public:
	virtual bool Check(int x, int y)
	{
		if (x < 97 || x > 104 || y < 1 || y > 8)
			return false;
		return true;
	}
};

class Man : public Piece
{
	bool Check(int x, int y)
	{
		if (x < this->x)
			return false;

		if (abs(this->x - x) != 1 || abs(this->y - y) != 1)
			return false;

		return Piece::Check(x, y);
	}
};

class King : public Piece
{
	bool Check(int x, int y)
	{
		if (this->x - x == 0 || this->y - y == 0)
			return false;

		if (this->x - x != this->y - y)
			return false;

		return Piece::Check(x, y);
	}
};

int main()
{
	Piece* man = new Man();
	Piece* king = new King();

	cout << (man->Check('c', 2) ? "true" : "false") << endl;
	cout << (king->Check('d', 3) ? "true" : "false") << endl;
	cout << (man->Check('d', 3) ? "true" : "false") << endl;

	return 0;
}