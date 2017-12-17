// Lab35122.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include <string>
using namespace std;
class FarmAnimal
{
public:  FarmAnimal(double water_consumption);
		 double getWaterConsumption();

protected:double water_consumption;
};
FarmAnimal::FarmAnimal(double water_consumption)
{
	this->water_consumption = water_consumption;
}
double FarmAnimal::getWaterConsumption()
{
	return water_consumption;
}


class ConsumptionAccumulator
{
public:  ConsumptionAccumulator();
		 double getTotalConsumption();
		 void addConsumption(FarmAnimal animal);
protected:  double total_consumption;
};
ConsumptionAccumulator::ConsumptionAccumulator() : total_consumption(0)
{
}
double ConsumptionAccumulator::getTotalConsumption()
{
	return total_consumption;
}
void ConsumptionAccumulator::addConsumption(FarmAnimal animal)
{
	total_consumption += animal.getWaterConsumption();
}

class Cow :public FarmAnimal
{
public: Cow(double n) : FarmAnimal(n)
{
	water_consumption = n*8.6 / 100;
};
};

class Sheep :public FarmAnimal
{
public: Sheep(double n) : FarmAnimal(n)
{
	water_consumption = n*1.1 / 10;
};
};

class Horse :public FarmAnimal
{
public: Horse(double n) : FarmAnimal(n)
{
	water_consumption = n*6.8 / 100;
};
};
int main()
{
	ConsumptionAccumulator accumulator;
	string animal;
	int consumption, i = 0;
	do
	{
		cin >> animal;
		if (animal == "cow")
		{
			cin >> consumption;
			Cow cow(consumption);
			accumulator.addConsumption(cow);
		}
		else if (animal == "sheep")
		{
			cin >> consumption;
			Sheep sheep(consumption);
			accumulator.addConsumption(sheep);
		}
		else if (animal == "horse")
		{
			cin >> consumption;
			Horse horse(consumption);
			accumulator.addConsumption(horse);
		}
		i++;
	} while (i<3);

	cout << accumulator.getTotalConsumption();
	return 0;
}