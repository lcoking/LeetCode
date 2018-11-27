#pragma once

#include "..\LeetCode_trail\Header.h"





//Global environment events
//可以定义多个继承自 Environment 的子类, 实现不同的 global events
class FooEnvironment :public testing::Environment
{
public:
	virtual void SetUp()
	{
		// add global setup below

	}

	virtual void TearDown()
	{
		// add global tear-down below
	}
private:

};

//Suite events
class leetSolution_Suite :public testing::Test
{

protected:
	static void SetUpTestCase()
	{
		std::cout << "test suite 1 setup\n\n";
		pleet = new Leet_Solution;


		ASSERT_TRUE(pleet);


	}

	static void TearDownTestCase()
	{
		delete pleet;
		pleet = nullptr;
		std::cout << "test suite 1 teardown\n\n";
	}

	//Some expensive resource shared by all tests
	//static T* shared_resource_;
public:
	 static Leet_Solution *pleet;
};


//Single test events
class leetSolution_singleTest:public testing::Test
{
public:

protected:
	virtual void SetUp()
	{
		//Before calling any COM functions, a thread needs to call CoInitialize to load the COM infrastructure (and to enter an apartment).
		//Once a thread calls CoInitialize, the thread is free to call COM APIs.
		CoInitialize(nullptr);
	}

	virtual void TearDown()
	{
		CoUninitialize();
	}
private:
};

//Test with parameters
class IsPrimeParamTest:public::testing::TestWithParam<int>
{

};
