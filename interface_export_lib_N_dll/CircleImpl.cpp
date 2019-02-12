#include "CircleImpl.h"

Impl::CircleImpl::CircleImpl(double rad): radius(rad)
{
}

double Impl::CircleImpl::area()
{
	return PI()*radius*radius;
}
