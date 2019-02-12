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



//__declspec(novtable)  ���ε������麯����, ���麯������ ���麯��
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

	INTERFACE_BASE

public:
	virtual ~Shape() = default;
};


//ÿ�������඼Ҫʵ�ֽӿ�
//class Circle1 :public Shape
//{
//public:
//	Circle1(Point p, unsigned int r, Color c) : cent(p), radius(r), colr(c) {}
//	INTERFACE_DERIVED
//
//private:
//	Point cent;
//	unsigned int radius;
//	Color colr;
//};
//
//class Triangle :public Shape
//{
//public:
//	Triangle(Point p1, Point p2, Point p3) { /*...*/};
//	INTERFACE_DERIVED
//};




//Implementing dual hierarchy by multiple-inheritance variant
class Circle :public virtual Shape
{
	//INTERFACE_BASE
public:
	virtual int Radius() const = 0;

	virtual ~Circle() = default;


};

class Smiley :public virtual Circle
{
public:

	virtual ~Smiley() = default;
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

void Impl::Shape::move(Point p)
{

}

void Impl::Shape::redraw()
{

}






//Implementation
class Impl::Circle :public virtual ::Circle, public Impl::Shape
{
public:
	Circle() {};
	~Circle() {};

	INTERFACE_DERIVED

	int Radius() const override
	{
		/*...*/
		return 0;
	}


};


Point Impl::Circle::center() const 
{
	return Point();
}

Color Impl::Circle::color() const
{
	return Color();
}

void Impl::Circle::rotate(int a)
{

}

void Impl::Circle::move(Point p)
{

}

void Impl::Circle::redraw()
{

}



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
		std::cout << "Impl::Smily   rotate ! \n\n";
	}

	virtual void move(Point)
	{

	}

	virtual void redraw()
	{

	}
	virtual int Radius() const
	{
		return 1;
	}
};
