#pragma once

#include "CircleImpl.h"




class CircleManager
{
public:
	static Circle *create(double radius);

	static void destory(Circle *pCircle);

};