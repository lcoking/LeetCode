#pragma once

#include <string>

//前向声明实现类
class PersonImpl;

//INTERFACE
class Person
{
public:
	Person(std::string& name, int age);
	virtual ~Person();

	int member_method(int arg);

private:
	PersonImpl *mPersonImpl;	//指向 Implementation 的指针
};