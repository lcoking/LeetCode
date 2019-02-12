#pragma once
#include "Circle.h"


namespace Impl {
	class CircleImpl;
}



inline double PI()
{
	return  std::atan(1) * 4;
}


class Impl::CircleImpl :public Circle
{
public:
	CircleImpl(double rad);
	double area() override;
private:
	double radius;
};
