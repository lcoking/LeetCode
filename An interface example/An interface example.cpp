// An interface example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "CmdInput.h"
#include "MyParser.h"
int main()
{
	CmdInput CInput;
	MyParser CParser;

	CInput.SetHandler(&CParser);
	CInput.run();

	return 0;
}


class Base
{
public:
	virtual int func(int n) const = 0;
};

class Derived :public Base
{
public:
	virtual int func(int n)const;
};




int Derived::func(int n) const
{
	return 0;
}
