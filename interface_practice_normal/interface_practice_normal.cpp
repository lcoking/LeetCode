// interface_practice_normal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "duck.h"

int main()
{
	//Duck *pDuck = new RedDuck();
	//pDuck->Fly();
	//pDuck->Quack();
	//pDuck->Swim();

	//delete pDuck;

	Duck *pDuck = new LandLubber();
	pDuck->Fly();
	pDuck->Quack();
	pDuck->Swim();

	delete pDuck;

	Behavior *pBehavior = new RedDuck();

	pBehavior->Fly();
	pBehavior->Quack();
	
	delete pBehavior;

	pBehavior = new LandLubber();
	pBehavior->Fly();
	pBehavior->Quack();

	delete pBehavior;

}

