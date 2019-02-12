// interface_export_lib_N_dll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "CircleManager.h"

int main()
{
	Circle* pCircle = CircleManager::create(10.0);
	std::cout << pCircle->area() << std::endl;

	CircleManager::destory(pCircle);
	pCircle = nullptr;
}

