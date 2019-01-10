#pragma once

//pure interface

typedef struct  po
{
	float x;
	float y;
	po() { x = 0.0f; y = 0.0f; }
	po(float a, float b) :x(a), y(b) {};
}Point;

using COLORREF = unsigned int;
using BYTE = unsigned char;
using WORD = unsigned short;
using DWORD = unsigned int;

template<typename T>
constexpr auto getRed(T rgb) { return ( (BYTE)(rgb) ); }
template<typename T>
constexpr auto getGreen(T rgb) { return ( (BYTE)( ( (WORD)(rgb) )>>8 ) ); }
template<typename T>
constexpr auto getBlue(T rgb) { return ( (BYTE)( (rgb)>>16 ) ); }



template<typename T1, typename T2, typename T3>
constexpr auto RGB(T1 r, T2 g, T3 b) { return ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16))); }

typedef struct colr
{
	COLORREF rgb;
	colr() { rgb = 0; }
	colr(BYTE r, BYTE g, BYTE b):rgb(RGB(r,g,b)) {}
}Color;



//__declspec(novtable)  修饰的类无虚函数表, 即虚函数都是 纯虚函数
#define INTERFACE class __declspec(novtable)



#define Interface_member(terminal)	\
public:							\
	virtual Point center() const  ##terminal	\
	virtual Color color() const ##terminal		\
	\
	virtual void rotate(int) ##terminal		\
	virtual void move(Point) ##terminal		\
	\
	virtual void redraw() ##terminal		

#define INTERFACE_BASE		Interface_member(=0;)
#define INTERFACE_DERIVED	Interface_member(;)

//A pure interface rarely have constructors
//There is NOTHING to construct
INTERFACE Shape		//pure interface
{
public:
	INTERFACE_BASE

};


//每个派生类都要实现接口
class Circle1 :public Shape
{
public:
	Circle1(Point p, unsigned int r, Color c) : cent(p), radius(r), colr(c) {}
	INTERFACE_DERIVED

private:
	Point cent;
	unsigned int radius;
	Color colr;
};

class Triangle :public Shape
{
public:
	Triangle(Point p1, Point p2, Point p3) { /*...*/};
	INTERFACE_DERIVED
};




//Implementing dual hierarchy by multiple-inheritance variant
class Circle :public Shape
{
public:
	virtual int Radius() const = 0;
};

class Smiley :public virtual Circle
{
public:

};


namespace Impl {
	class Shape;
	class Circle;
	class Smiley;
}


class Impl::Shape :public virtual ::Shape
{
public:
	Shape() {};
	~Shape() {};


	INTERFACE_DERIVED
};

Point Impl::Shape:: center() const
{
	return Point();
}

Color Impl::Shape::color() const 
{
	return Color();
}

void Impl::Shape::rotate(int a)
{

}




//Implementation
class Impl::Circle :public virtual ::Circle, public Impl::Shape
{
public:
	Circle() {};
	~Circle() {};

	int Radius() const override
	{
		/*...*/
		return 0;
	}


};


class Impl::Smiley:public virtual ::Smiley, public Impl::Circle
{
public:
	Smiley() {};
	~Smiley() {};

	//Implementation..
	virtual Point center() const
	{
		return Point();
	}

	virtual Color color() const
	{
		return Color();
	}

	virtual void rotate(int)
	{
	
	}

	virtual void move(Point)
	{

	}

	virtual void redraw()
	{

	}
};
