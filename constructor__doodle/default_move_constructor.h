#pragma once
#include <iostream>
#include "console_color.h"
class A
{
public:

	//普通构造函数
	A(double a, int *p = new int):// default arugment (HERE int *p) should be at the end of argument list
						pInt(p), 
						m_double(a)	
	{
		std::cout << YELLOW << "\n normal "<< RESET <<"constructor called\n"<< std::endl;
	}

//  	// user-declared copy constructor
//  	A(const A &ref):m_double(ref.m_double)
//  	{
//  
//  		// 深拷贝
//  		pInt = nullptr;
//  		size_t arrayLen = sizeof(ref.pInt);
//  
//  		pInt = new int[arrayLen];
//  		memset(pInt, 0, arrayLen);
//  
//  		memcpy(pInt, ref.pInt, arrayLen);
//  
//  		std::cout << RED <<"\n copy " << RESET << "constructor called\n" << std::endl;
//  	}


// 	// user-declared copy assignment operator
// 	A& operator=(const A &ref)
// 	{
// 		m_double = ref.m_double;
// 
// 		// 深拷贝
// 		// lambda ?
// 		pInt = nullptr;
//  		size_t arrayLen = sizeof(ref.pInt);
//  
//  		pInt = new int[arrayLen];
//  		memset(pInt, 0, arrayLen);
//  
//  		memcpy(pInt, ref.pInt, arrayLen);
//  
//  		std::cout << GREEN <<"\n copy assignment operator " << RESET << "called\n" << std::endl;
// 
// 
// 		return *this;
// 
// 	}


// 	// move assignment operator
// 	A& operator=(A &&ref)
// 	{
// 
// 		if (this != &ref)
// 		{
// 			delete pInt;
// 
// 			m_double = ref.m_double;
// 			pInt = ref.pInt;
// 
// 
// 			ref.m_double = 0.0;
// 			ref.pInt = nullptr;
// 		}
// 
// 		std::cout << MAGENTA << "\n move assignment operator " << RESET << "called\n" << std::endl;
// 
// 		return *this;
// 		
// 	}


	~A()
	{
		delete pInt;
		pInt = nullptr;
		m_double = 0.0;
	}


	int* getPtr()
	{
		return pInt;
	}
private:
	int *pInt;
	double m_double;
};

