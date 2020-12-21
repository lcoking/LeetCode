#include "Header.h"


typedef uint64_t PointerType;

unsigned short Hash(void* p)
{
	PointerType val = reinterpret_cast<PointerType>(p);

	return (unsigned short)(val ^(val>>16));
}


int reinterpret_cast_hash()
{
	int a[20];
	for (int i = 0; i < 20; ++i)
	{
		std::cout << Hash(a + i) << std::endl;
	}
	return 0;
}



int reinterpret_cast_const_test()
{
	typedef void (*FunctionPointer)(int);
	int value = 2;
	const int* pointer = &value;

	FunctionPointer funcP = reinterpret_cast<FunctionPointer>(pointer);	//	build OK, but nonsense, access violation

	int *p =  reinterpret_cast<int*>(pointer);	

	return 0;
}


int main()
{
	
	reinterpret_cast_hash();
	return 0;
}