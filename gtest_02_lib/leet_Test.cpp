#include "pch.h"
#include <atlbase.h>	// for the usage of "CComPtr"
#include <gtest/gtest.h>
#include "testHeader.h"



///*	LeetCode solution test suite	*/
//Leet_Solution *leetSolution_Suite::pleet = NULL;	//����static member variable ֻ�Ǹ�����
//													//����.cpp �ж���
//
//
//TEST_F(leetSolution_Suite, searchInsert_test)
//{
//
//	std::vector<int> tVect = { 103, 452, 1009, 1625, 3098 };
//	int target = 2018;
//
//	EXPECT_EQ(pleet->searchInsert(tVect, target), 4);
//
//
//}
//
//TEST_F(leetSolution_Suite, addString_test)
//{
//
//	std::string num1 = "10622";
//	std::string num2 = "1014";
//
//	//EXPECT_STREQ ֧�� char* �� wchar_t*
//	EXPECT_STREQ(pleet->addString(num1, num2).c_str(), "11636");
//
//}
//

//�����Լ��
int greatestCommonDivisor(int a, int b)
{
	if (a == 0 || b == 0)
	{
		throw "Do NOT do that!";
	}
	int c = a % b;
	if (c == 0)
	{
		return b;
	}
	return greatestCommonDivisor(b, c);
}

////�жϻ�����
//bool MutuallyPrime(int m, int n)
//{
//	return !(greatestCommonDivisor(m, n) > 1);
//}
//
////�ж�����
////return true if N is a prime number
//bool isPrime(int n)
//{
//	//Trivial case 1: small numbers
//	if (n <= 1)
//	{
//		return false;
//	}
//	//Trivial case 2: even numbers
//	if (n % 2 == 0)
//	{
//		return n == 2;
//	}
//
//	//Try to divide N by every odd number i, starting from 3
//	for (int i = 3; ; i += 2)
//	{
//		//Only have to try i up to the square root of N
//		if (i > n / i)
//		{
//			break;
//		}
//		//i <= N/i < N
//		//If N is divisible by i, N is not prime
//		if (n%i == 0)
//		{
//			return false;
//		}
//	}
//
//	//N has no integer factor in the range(1, n)m and thus is prime
//	return true;
//}
//
//
//TEST(AssertionTest, H0)
//{
//	EXPECT_ANY_THROW(greatestCommonDivisor(10, 0));
//	EXPECT_THROW(greatestCommonDivisor(0, 5), const char*);
//	EXPECT_NO_THROW(greatestCommonDivisor(1, 2));
//}
//
//TEST(PredicateAssertionTest, Demo)
//{
//	int m = 5, n = 6;
//	//��ӡ�������, 2 ����2������, ���5��
//	EXPECT_PRED2(MutuallyPrime, m, n);
//
//}
//
////
//
//TEST_F(leetSolution_singleTest, COM_Test)
//{
//
//	CComPtr<IUnknown> shell;	//COM�ӿ�ָ����
//	EXPECT_HRESULT_SUCCEEDED(shell.CoCreateInstance(L"Excel.Application"));
//
//}
//
////template <typename T> class FooType
////{
////public:
////	void Bar()
////	{
////		testing::StaticAssertTypeEq<int, T>();
////	}
////
////};
////
////TEST(TypeAssertionTest, Demo)
////{
////	FooType<bool> fooType;
////	fooType.Bar();
////}
//
//
//INSTANTIATE_TEST_CASE_P(demo, IsPrimeParamTest, ::testing::Values(3, 5, 11, 13, 14, 16, 23));
//
//TEST_P(IsPrimeParamTest, primeTest)
//{
//	int param = GetParam();
//	EXPECT_TRUE(isPrime(param));
//}




std::vector<testWP_st> suite4VPT::inputs;

INSTANTIATE_TEST_CASE_P(Demo, suite4VPT, ::testing::ValuesIn(suite4VPT::caseInit(suite4VPT::inputs)));
//INSTANTIATE_TEST_CASE_P(Demo, suite4VPT, ::testing::ValuesIn(suite4VPT::inputs));

TEST_P(suite4VPT, test1)
{
	const testWP_st &n = suite4VPT::GetParam();
	//false ������ַ���
	EXPECT_EQ(n.exp, greatestCommonDivisor(n.a, n.b))<<"\n\nNOT EQUAL!\n\n";
}



//REGISTER_TYPED_TEST_CASE_P(TypeTest, demo);
//
//TYPED_TEST_P(TypeTest, demo)
//{
//	//Inside a test, refer to the special name 'TypeParam' to get the type parameter
//	//Since we are inside a derived class template, C++ requires us to visit the members of TypeTest via 'this'
//	TypeParam n = 0;
//
//
//}
//
//
//
//typedef testing::Types<char, int, unsigned int> myTypes;
//INSTANTIATE_TYPED_TEST_CASE_P(my, TypeTest, myTypes);



