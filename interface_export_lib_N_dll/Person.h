#pragma once

#include <string>

//ǰ������ʵ����
class PersonImpl;

//INTERFACE
class Person
{
public:
	Person(std::string& name, int age);
	virtual ~Person();

	int member_method(int arg);

private:
	PersonImpl *mPersonImpl;	//ָ�� Implementation ��ָ��
};