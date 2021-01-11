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

	//std::unique_ptr<int> pint(new int(5));


	auto pint(std::make_unique<int>(1));	//	recommended


	return 0;
}



class T
{
public:

	T(const char *addr, int offset)
	{
		serial_payload = std::make_unique<std::vector<char>>(addr, addr + offset);	
	}

	char* getPayLoad()
	{
		return serial_payload->data();
	}

private:
	std::unique_ptr<std::vector<char>> serial_payload;
};



std::unique_ptr<T> read(const char *msg, int offset)
{
	auto data (std::make_unique<T>(msg, 5));
	
	return data;
}


std::unique_ptr<int> clone(int p)
{ 
	std::unique_ptr<int> pint(new int(p));

	return pint;
}







int unique_ptr_assignment_doodle()
{

	//std::unique_ptr<int> pint(new int(10));
	//std::unique_ptr<int> pint2 = std::move(pint);	//	ת������Ȩ, ԭ unique_ptr ָ��Ϊ nullptr
	
	//
	//std::unique_ptr<int> ret = clone(4);


	char msg[5] = { 65,66,67,68,69 };

	//char* data = read(msg,5)->getPayLoad();	//	data ������
	//std::cout << "data[0] = " << data[0] << "\n";


	auto data = read(msg, 5);
	char* data_payload = data->getPayLoad();
	std::cout << "data[0] = " << data_payload[0] << "\n";



	return 0;
}



/**
 *	shared_ptr �̰߳�ȫ��
 */




/**
 *	shared_ptr ����ɾ����
 */

void shared_ptr_custom_deleter_test()
{
	//// file pointer
	//FILE* fp1 = NULL;
	//FILE* fp2 = NULL;

	//errno_t res1 = fopen_s(&fp1, "test00.txt", "r+");
	//std::shared_ptr<FILE> sp1(	fp1, 
	//							fileRelease_struct()
	//						);
	//
	//errno_t res2 = fopen_s(&fp2, "test01.txt", "r+");
	//std::shared_ptr<FILE> sp2(	fp2, 
	//							fileRelease_lambda
	//						);

	//// memory allocated by malloc()
	//std::shared_ptr<int> sp1(	(int*)malloc(sizeof(int)), 
	//							mallocFree_struct<int>()
	//						);		

	//std::shared_ptr<float> sp2(	(float*)malloc(sizeof(float)), 
	//							mallocFree_lambda<float>	
	//							//	lambda ��ʹ��ģ������ T, ����lambda ʱҪ���廯 T �Ķ�Ӧ����
	//						);



	//	dynamical array allocated by new[]
	std::shared_ptr<int> sp1(	new int[10], 
								array_delete_struct<int>()
							);

	std::shared_ptr<int> sp2(	new int[10],
								array_delete_lambda<int>
							);

}


/**
 *	shared_ptr ѭ������
 */

struct Node
{
	Node(int value) :_value(value)
	{
		std::cout << "Node()\n";
	}

	~Node()
	{
		std::cout << "~Node()\n";
	}

	int _value;
	//std::shared_ptr<Node> _prev;
	//std::shared_ptr<Node> _next;
	std::weak_ptr<Node> _prev;
	std::weak_ptr<Node> _next;
};

void shared_ptr_recursive_reference_test()
{
	std::shared_ptr<Node>sp1(new Node(1));
	std::shared_ptr<Node>sp2(new Node(2));

	std::cout << sp1.use_count() << std::endl;
	std::cout << sp2.use_count() << std::endl;

	sp1->_next = sp2;
	sp2->_prev = sp1;

	std::cout << sp1.use_count() << std::endl;
	std::cout << sp2.use_count() << std::endl;

}


/**
 *	shared_from_this
 */

class A
{
public:
	A(int y = 0) :x(y) {}
	~A()
	{
		printf("Class A destructor called. \n");
	}

	A* getThis()
	{
		return this;
	}

private:
	int x = 3;
};


class B : public std::enable_shared_from_this<B>
{
public:
	B(int y = 0) :x(y) {}
	~B()
	{
		printf("Class B destructor called. \n");
	}

	std::shared_ptr<B> getThis()
	{
		return shared_from_this();
	}

private:
	int x;
};

class F :public B
{
public:
	F(long y = 0) :x(y) {}
	
	std::shared_ptr<F> getThis()
	{
		return std::static_pointer_cast<F>(shared_from_this());
	}

private:
	long x;
};


void shared_from_this_test()
{
	std::shared_ptr<B> sp1(new B());
	std::shared_ptr<B> sp2(sp1->getThis());

	printf("The reference count of sp1 is %ld\n", sp1.use_count());
	printf("The reference count of sp2 is %ld\n", sp2.use_count());

}



int main()
{
	//raii_template_test();
	//auto_ptr_doodle();
	//shared_ptr_assignment_doole();

	//unique_ptr_constructor_doodle();
	//unique_ptr_assignment_doodle();
	
	shared_ptr_custom_deleter_test();

	//shared_ptr_recursive_reference_test();
	//shared_from_this_test();





	return 0;
}