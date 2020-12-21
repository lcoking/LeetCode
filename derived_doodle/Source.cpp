#include "Header.h"


void base_derived_pointer_test()
{
	A* pa = new A(1);
	B* pb = new B(2, 20);
	C* pc = new C(3);
	D* pd = new D(4, 40, 400, 4000);

	std::cout << "-------更改前-----" << std::endl;
	pa->display();
	pb->display();
	pc->display();
	pd->display();
	std::cout << "-----------------------" << std::endl;

	std::cout << "--------更改后-----------" << std::endl;

	pa = pd;
	pa->display();

	pb = pd;
	pb->display();

	pc = pd;
	pc->display();

	pd->display();
	std::cout << "-----------------------" << std::endl;

}


int main()
{

	base_derived_pointer_test();
	return 0;
}