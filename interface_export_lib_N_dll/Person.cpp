


#include "Person.h"
#include "PersonImpl.h"

//constructor
Person::Person(std::string& name, int age):
	mPersonImpl(new PersonImpl(name, age))
{
	std::cout << "construct Person\n\n";
}

//destructor
Person::~Person()
{
	std::cout << "destruct Person\n\n";
}


//member functions
//调用 Implementation 中的相应 function
int Person::member_method(int arg)
{
	return mPersonImpl->impl_member_method(arg);
}
