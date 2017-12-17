// Lab514.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
class ShopItemOrder
{
	string name;
	int item_price;
	int number_of_items;
public:
	string get_name()
	{
		return this->name;
	}
	void set_name(string name)
	{
		this->name = name;
	}
	int get_number_of_items()
	{
		return this->number_of_items;
	}
	void set_number_of_items(int number_of_items)
	{
		this->number_of_items = number_of_items;
	}
	int get_item_price()
	{
		return this->item_price;
	}
	void set_item_price(int unit_price)
	{
		this->item_price = unit_price;
	}

	void TotalPrice()
	{
		cout << "TOTAL PRISE IS:" << this->number_of_items*this->item_price << endl;
	}

	void Print()
	{
		cout << "NAME:" << get_name() << '\n' << "UNIT PRICE:" << get_item_price() << '\n' << "NUMBER OF ITEMS:" << get_number_of_items() << endl;
	}
};

int main()
{
	ShopItemOrder order;
	order.set_name("Lemon");
	order.set_item_price(15);
	order.set_number_of_items(4);
	order.Print();
	order.TotalPrice();
	return 0;
}