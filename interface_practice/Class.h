#pragma once
#include <string>
#include <iostream>

#define Interface_member(terminal)		\
public:									\
	virtual std::string getName() const ##terminal	\
	virtual int getID() const ##terminal			


#define INTERFACE_BASE		Interface_member(=0;)
#define INTERFACE_DERIVED	Interface_member(;)

//条件编译
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
	INTERFACE_DERIVED	//每个member function 仍要手动实现
};


