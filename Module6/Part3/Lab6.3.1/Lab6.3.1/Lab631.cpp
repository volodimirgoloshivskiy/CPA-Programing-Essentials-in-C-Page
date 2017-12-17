// Lab631.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class DrawTree
{
public:
	virtual void Draw()
	{
		cout << " /\\ " << endl;
	}
};
class DrawLine : public DrawTree
{
	void Draw()
	{
		DrawTree::Draw();
		cout << "//\\\\" << endl;
	}
};
class DrawPlus : public DrawTree
{
	void Draw()
	{
		DrawTree::Draw();
		cout << "/++\\" << endl;
	}
};
class DrawStar : public DrawTree
{
	void Draw()
	{
		DrawTree::Draw();
		cout << "/**\\" << endl;
	}
};
int main()
{
	DrawTree** drawsomething = new DrawTree*[3];
	drawsomething[0] = new DrawLine();
	drawsomething[2] = new DrawPlus();
	drawsomething[1] = new DrawStar();
	for (int i = 0; i < 3; i++)
	{
		cout << "Drawing " << i + 1 << ":" << endl;
		drawsomething[i]->Draw();
	}
	return 0;
}