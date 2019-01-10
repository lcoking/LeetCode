// interface_practice_normal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "duck.h"

int main()
{
	Duck *pDuck = new Duck();
	pDuck->Fly();
	pDuck->Quack();
	pDuck->Swim();

	delete pDuck;


	RedDuck *pRed = new RedDuck();
	pRed->Fly();
	pRed->Quack();
	pRed->Swim();
	
	delete pRed;

	pDuck = new RedDuck();
	pDuck->Fly();
	pDuck->Quack();
	pDuck->Swim();

	//basePtr ����base virtual function �� base::function_name ��ָ��
	pDuck->Duck::Fly();

	delete pDuck;
}

