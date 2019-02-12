

#include "CircleManager.h"


Circle * CircleManager::create(double radius)
{
	Circle *pCircle = new Impl::CircleImpl(radius);

	return pCircle;
}

void CircleManager::destory(Circle * pCircle)
{
	delete pCircle;
}
