#include "Class.h"




std::string derivedClass::getName() const	//�����޸�class member ����� ��const member function
{
	return _name;
}

int derivedClass::getID() const
{
	return _id;
}


my_INTERFACE bool getObject(void **pp_obj)
{
	baseClass *pdc = new derivedClass();
	*pp_obj = (void*)pdc;

	return true;
}