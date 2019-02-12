// Interface_Implement_divided.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Shape.h"



int main()
{
	::Shape *pShape = new Impl::Smiley();
	pShape->rotate(12);
	return 0;
}


