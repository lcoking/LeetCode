// constructor__doodle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "MyClass.h"
#include "default_move_constructor.h"

// 形参是类对象
void  func1(MyClass arg)
{
}

// 返回值是类对象
MyClass func2()
{
	const char strArray[] = "func2 string";
	MyClass arg(strArray);
	return arg;
}


int main()
{

	//MyClass m0;
	//MyClass mc(22, 101.7);	

	//MyClass m1(mc);		// 用一个对象初始化另一个对象

	//MyClass m2 = mc;	// 用一个对象初始化另一个对象 
	//					// 这里是初始化, 不是赋值

	//func1(mc);			//形参为类对象

	//MyClass m3 = func2();	//函数返回值是类对象
	//
	//m2 = m0;			//m2 已初始化, 这里是赋值


	//return 0;


	





	//const char strArray[] = "wowo";


	//MyClass m0(strArray);


	//MyClass m1(std::move(m0));	
	//
	//MyClass m2(func2());





	//A a1(2.2, new int(4));
	//A a3 = a1;

	//A a4(1.1, new int(11));
	//A a2(std::move(a4));

	//A a5 = std::move(a1);

// 	A a1(2.2, new int(4));
// 
// 	A a4(1.1, new int(11));
// 
// 	a4 = std::move(a1);
// 
// 	std::cout << a1.getPtr() << std::endl;



	student stu1(2, 3);

	//student stu2;

}


