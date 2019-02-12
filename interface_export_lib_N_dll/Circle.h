#pragma once
#include <iostream>
#include <cmath>

#define INTERFACE class __declspec(novtable)


INTERFACE  Circle
{
public:
	virtual ~Circle() = default;

	virtual double area();
};