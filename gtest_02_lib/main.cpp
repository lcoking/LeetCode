#include "pch.h"


#include "testHeader.h"




//Function main() is in gtest_main.cc
int main(int argc, char** argv)
{
	//add global test environment here
	testing::AddGlobalTestEnvironment(new FooEnvironment);


	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}