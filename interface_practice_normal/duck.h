#pragma once


#include <iostream>
#include "console_Color.h"

#define Interface class __declspec(novtable)

#define Interface_member(terminal)	\
public:							\
	virtual void Fly() const ##terminal			\
	virtual void Quack() const ##terminal

#define COMMON	Interface_member(;)

Interface Behavior
{
	COMMON
};



class Duck :public Behavior
{
	COMMON

public:
	void Swim() 
	{
		std::cout << "Duck SWIM!\n\n";
	}
};


void Duck::Quack() const
{
	std::cout << "Duck Quack!\n\n";
}

void Duck::Fly() const
{
	std::cout << "Duck Fly!\n\n";
}


class RedDuck :public Duck
{
	COMMON
};

void RedDuck::Quack() const
{
	std::cout << RED << "RedDuck Quack!\n\n"<< RESET;
}

void RedDuck::Fly() const
{
	std::cout << RED << "RedDuck Fly!\n\n" << RESET;
}


class LandLubber :public Duck
{
	COMMON
};