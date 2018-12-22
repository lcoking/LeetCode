#pragma once
#include <string>
#include <iostream>

#define INTERFACE_(terminal)		\
public:									\
	virtual std::string getName() const ##terminal	\
	virtual int getID() const ##terminal			\


#define INTERFACE_BASE		INTERFACE_(=0;)
#define INTERFACE_DERIVED	INTERFACE_(;)

//��������
#define  myDLL_export

#ifdef myDLL_export
#define my_INTERFACE __declspec(dllexport)
#else
#define my_INTERFACE __declspec(dllimport)
#endif // myDLL_export


class baseClass
{
public:
	baseClass() 
	{
		_name = "blank";
		_id = 0;
	};
	virtual ~baseClass() {};

	INTERFACE_BASE

protected:
	std::string _name;
	int _id;

};

class derivedClass : public baseClass
{
	INTERFACE_DERIVED	//ÿ��member function ��Ҫ�ֶ�ʵ��
};


std::string derivedClass::getName() const	//�����޸�class member ����� ��const member function
{
	return _name;
}

int derivedClass::getID() const
{
	return _id;
}


my_INTERFACE bool getObject(void **pp_obj)
{
	baseClass *pdc = new derivedClass();
	*pp_obj = (void*)pdc;

	return true;
}