

#include "PersonImpl.h"


PersonImpl::PersonImpl(std::string & name, int age):
	mName(name),
	mAge(age)
{

}

int PersonImpl::impl_member_method(int arg)
{
	/*	...	*/
	return arg;
}


