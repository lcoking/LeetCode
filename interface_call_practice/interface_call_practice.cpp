// interface_call_practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "Class.h"

bool __declspec(dllimport)getObject(void **pp_object);

int main()
{
	baseClass *pbc = nullptr;
	void *pobj = nullptr;
	if (getObject(&pobj))
	{
		pbc = (baseClass*)pobj;
		
		std::cout << "The name is: " << pbc->getName() << std::endl <<
			"The ID is: " << pbc->getID() << std::endl;


		if (pbc!=nullptr)
		{
			delete pbc;
			pbc = nullptr;
		}
	}

	return 0;
}


