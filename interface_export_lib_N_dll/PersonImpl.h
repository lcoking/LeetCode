#pragma once

#include <string>
#include <iostream>

class PersonImpl
{
public:
	PersonImpl(std::string &name, int age);
	virtual ~PersonImpl() = default;

	int impl_member_method(int arg);

private:
	std::string &mName;
	int mAge;
};

