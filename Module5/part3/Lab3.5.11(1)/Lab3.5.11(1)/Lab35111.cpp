// Lab35111.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include<iostream>
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


class DummyAnimal : public FarmAnimal
{
public:  DummyAnimal(double given_water_consumption);
};
DummyAnimal::DummyAnimal(double given_water_consumption) : FarmAnimal(10)
{
	water_consumption = given_water_consumption;
}


class DoublingAnimal : public FarmAnimal
{
public:  DoublingAnimal(double given_water_consumption);
};
DoublingAnimal::DoublingAnimal(double given_water_consumption) : FarmAnimal(20)
{
	water_consumption = given_water_consumption;
}
void printConsumption(FarmAnimal animal)
{
	cout << "This animal consumes " << animal.getWaterConsumption() << " liters of water" << endl;
}
int main()
{
	FarmAnimal animalA(5);
	DummyAnimal animalB(12);
	DoublingAnimal animalC(21);
	cout << "animalA consumes " << animalA.getWaterConsumption() << " liters of water." << endl;
	cout << "What about the others ? " << endl;
	printConsumption(animalB);
	printConsumption(animalC);
	return 0;
}