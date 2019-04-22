#pragma once

#include "console_color.h"

#include <iostream>
#include <cstring>	// for the usage of memset, strcpy_s in C++
					// <memory.h> in C


#define TO_STR(x) #x
#define STR(x) TO_STR(x)

//	do..while(false) ʹ�ú�β��������Ϸֺ�";"
//	��������ֱ��
//	����©�ֺ���ᱨ��

#define custom_std_output(x)	\
	do{		\
	std::cout<<STR(x)<<std::endl;	\
	} while (false)




class MyClass
{
public:

// 	MyClass() :m_int(0), m_double(0.0)
// 	{
// 
// 	}
// 
// 	MyClass(int a, double b) :m_int(a), m_double(b)
// 	{
// 
// 	}
// 
// 	//�������캯��
// 	MyClass(const MyClass &ref)
// 	{
// 		m_int = ref.m_int;
// 		m_double = ref.m_double;
// 
// 		custom_std_output(\n copy constructor called \n\n);
// 	}
// 
// 	//���� =
// 	MyClass& operator=(const MyClass &ref)
// 	{
// 		m_int = ref.m_int;
// 		m_double = ref.m_double;
// 
// 		custom_std_output(\n overloaded operator called \n\n);
// 
// 		return *this;	//
// 	}

	MyClass() :m_int(0), m_double(0.0), m_pstr(nullptr)
	{

	}

	MyClass(const char value[]):m_int(0), m_double(0.0)
	{
		m_pstr = nullptr;
		size_t len = strlen(value);	// size_t ��WIN32 �ܹ��� unsigned int 4 �ֽ�
									// ��WIN64 �ܹ��� unsigned long 8 �ֽ�
		m_pstr = (char *)malloc( len + 1);
		if (m_pstr)
		{
			memset(m_pstr, 0, len + 1);
			strcpy_s(m_pstr, len + 1, value);	//destination, size in byte, source
		}
		
	}
	// copy constructor
	MyClass(const MyClass &ref)
	{
		m_int = ref.m_int;
		m_double = ref.m_double;
		//���
		m_pstr = nullptr;
		size_t len = strlen(ref.m_pstr);

		m_pstr = (char *)malloc(len + 1);

		if (m_pstr)
		{
			memset(m_pstr, 0, len + 1);
			strcpy_s(m_pstr, len + 1, ref.m_pstr);
		}
		







		
	}




	// move assignment operator 
	MyClass& operator=(MyClass &&other)
	{
		if (this!= &other)	// ��ַ��ͬ
		{
			// free the existing resource
			delete m_pstr;

			// copy the data from the source object
			m_int = other.m_int;
			m_double = other.m_double;
			m_pstr = other.m_pstr;

			// release the data from the source object
			// so that the destructor does not free the memory multiple times
			other.m_double = 0.0;
			other.m_int = 0;
			other.m_pstr = nullptr;

			
		}

		custom_std_output(\nmove assignment operator called\n\n);

		return *this;
	}

	// move constructor
	MyClass(MyClass &&ref):	m_int(0),
							m_double(0.0),
							m_pstr(nullptr)	// ǳ����
	{
		*this = std::move(ref);

		custom_std_output(\nmove constructor called\n\n);
	}

private:
	int m_int;
	double m_double;
	char *m_pstr;
};




class student
{
public:
	student(const int a, const int b):m_a(a), m_b(b)
	{
	}

private:
	int m_a;
	int m_b;
};