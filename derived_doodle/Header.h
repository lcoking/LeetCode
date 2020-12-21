#pragma once
#include <iostream>


class A
{
public:
	A(int a) : m_a(a){}
	void display()
	{
		std::cout << "Class A: m_a = " << m_a << "\n";
	}
protected:
	int m_a;
};


class B :public A
{
public:
	B(int a, int b) :A(a), m_b(b){}
	void display()
	{
		std::cout << "Class B: m_a = " << m_a << "\n"<<"m_b = "<<m_b<<"\n";
	}

protected:
	int m_b;

};


class C
{
public:
	C(int c) : m_c(c){}
	void display()
	{
		std::cout << "Class C: m_c = " << m_c << "\n";
	}

protected:
	int m_c;
};

class D : public B, public C
{
public:
	D(int a, int b, int c, int d) :B(a, b), C(c), m_d(d) {}
	void display()
	{
		std::cout << "Class D: m_a = " << m_a << "\n"\
			"m_b = " << m_b << "\n"\
			"m_c = " << m_c << "\n"\
			"m_d = " << m_d << "\n";
	}

private:
	int m_d;
};