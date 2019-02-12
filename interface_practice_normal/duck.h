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



Interface Duck :public Behavior
{
	COMMON

public:
	virtual void Swim() const;
};





class RedDuck :public Duck
{
	COMMON
public:
	virtual void Swim() const;
};

void RedDuck::Quack() const
{
	std::cout << RED << "RedDuck Quack!\n\n"<< RESET;
}

void RedDuck::Fly() const
{
	std::cout << RED << "RedDuck Fly!\n\n" << RESET;
}

void RedDuck::Swim() const
{
	std::cout << RED << "RedDuck Swim!\n\n" << RESET;
}


class LandLubber :public Duck
{
	COMMON
public:
	virtual void Swim() const;
};

void LandLubber::Quack() const
{
	std::cout << MAGENTA << "LandLubber Quack!\n\n" << RESET;
}

void LandLubber::Fly() const
{
	std::cout << MAGENTA << "LandLubber Fly!\n\n" << RESET;
}

void LandLubber::Swim() const
{
	std::cout << MAGENTA << "LandLubber CAN NOT Swim!\n\n" << RESET;
}

