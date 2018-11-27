#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\LeetCode_trail\Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test_searchInsert)
		{
			// TODO: Your test code here
			Leet_Solution *pLeet = new Leet_Solution;
			Assert::IsNotNull(pLeet);
			std::vector<int> tVect = {1, 5, 12, 16, 26, 32, 128, 267};
			int target = 2;

			Assert::AreEqual(pLeet->searchInsert(tVect, target), 1);
		}

		TEST_METHOD(Test_addString_1)
		{
			// TODO: Your test code here
			Leet_Solution *pLeet = new Leet_Solution;
			Assert::IsNotNull(pLeet);
			
			std::string num1 = "12";
			std::string num2 = "114";

			Assert::AreEqual(pLeet->addString(num1, num2), std::string("126"));
		}

		TEST_METHOD(Test_addString_2)
		{
			// TODO: Your test code here
			Leet_Solution *pLeet = new Leet_Solution;
			Assert::IsNotNull(pLeet);

			std::string num1 = "232";
			std::string num2 = "4";

			Assert::AreEqual(pLeet->addString(num1, num2), std::string("236"));
		}

	};
}