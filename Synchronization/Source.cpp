#include "Header.h"

int raii_template_test()
{
	for (int i = 0; i< 1e4;++i)
	{
		auto arp = auto_release_ptr<int64_t>(new int64_t[3]);
		int64_t* ptr = arp.getPtr();

		ptr[0] = 1;
		ptr[1] = 2;
		ptr[2] = 3;
	}

	system("pause");
	return 0;
}


/**
 *	auto_ptr doodle
 */

void func(std::auto_ptr<int> ap)
{
	std::cout << "The *ap is " << *ap << "\n";
}


class base
{
};

class derived : public base
{

};


int auto_ptr_doodle()
{
	
	std::auto_ptr<base> apbase = std::auto_ptr<derived>(new derived);
	
	return 0;
}


struct C
{
	int* data;
};




int shared_ptr__construct_destruct_doodle()
{
	auto deleter = [](int* p)
	{
		std::cout << "[deleter called]\n";
		delete p;
	};



	std::shared_ptr<int> p1;					//	Ĭ�Ϲ���, δ����κ�ָ��, reference count = 0
	std::shared_ptr<int> p2(nullptr);			//	ͬ��
	std::shared_ptr<int> p3(new int);			//	ӵ�� int ָ��, reference count = 1
	std::shared_ptr<int> p4(new int, deleter);	//	ͬ��, �������Լ��� destructor 
												//	�ṹ����ָ��, Ĭ�ϵ�destructor �����ͷ�ָ��ָ����ڴ�, ��Ҫ�Զ�ɾ����


	std::shared_ptr<int> p5(new int, [](int* p) {delete p; }, std::allocator<int>());	//	ͬp4, ��ӵ�ж����ķ�����/constructor
	std::shared_ptr<int> p6(p5);														//	��p5 reference count = 0, ��p6 ��reference count =0
																						//	����, p6 �� reference count �� p5 �Ļ����� +1

	std::shared_ptr<int> p7(std::move(p6));												//	��ȡp6 ��Դ������Ȩ, p6 ��ӵ�е�ָ��ָ�� nullptr, reference count = 0
	std::shared_ptr<int> p8(std::unique_ptr<int>(new int));								//	?
	
	std::shared_ptr<C>	obj(new C);
	std::shared_ptr<int> p9(obj, obj->data);		//	aliasing


	std::cout << "use_count:\n";
	std::cout << "p1: " << p1.use_count() << '\n';
	std::cout << "p2: " << p2.use_count() << '\n';
	std::cout << "p3: " << p3.use_count() << '\n';
	std::cout << "p4: " << p4.use_count() << '\n';
	std::cout << "p5: " << p5.use_count() << '\n';
	std::cout << "p6: " << p6.use_count() << '\n';
	std::cout << "p7: " << p7.use_count() << '\n';
	std::cout << "p8: " << p8.use_count() << '\n';
	std::cout << "p9: " << p9.use_count() << '\n';

	return 0;
}

int shared_ptr_assignment_doole()
{
	std::shared_ptr<int> foo;
	std::shared_ptr<int> bar(new int(10));

	foo = bar;	//	copy, reference count + 1 

	bar = std::make_shared<int>(20);	// stored pointer �ı�, reference count = 1

	std::unique_ptr<int> unique(new int(30));
	foo = std::move(unique);	//	move from unique_ptr


	foo.swap(bar);		//	����2��shared_ptr ָ����ڴ�

	std::cout << "*foo is : " << *foo << "\n";
	std::cout << "*bar is : " << *bar<< "\n";
	return 0;
}




/**
 *	unique_ptr doodle
 */


int unique_ptr_constructor_doodle()
{

	std::unique_ptr<int> pint(new int(5));


	return 0;
}


std::unique_ptr<int>& clone(int p)
{ 
	std::unique_ptr<int> pint(new int(p));

	return pint;
}


int unique_ptr_assignment_doodle()
{

	std::unique_ptr<int> pint(new int(10));
	
	std::unique_ptr<int> pint2 = std::move(pint);	//	ת������Ȩ, ԭ unique_ptr ָ��Ϊ nullptr


	std::unique_ptr<int> ret = clone(4);


	return 0;
}

int main()
{
	//raii_template_test();
	//auto_ptr_doodle();
	//shared_ptr_assignment_doole();

	//unique_ptr_constructor_doodle();
	unique_ptr_assignment_doodle();
	return 0;
}