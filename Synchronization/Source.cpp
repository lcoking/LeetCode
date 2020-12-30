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



	std::shared_ptr<int> p1;					//	默认构造, 未获得任何指针, reference count = 0
	std::shared_ptr<int> p2(nullptr);			//	同上
	std::shared_ptr<int> p3(new int);			//	拥有 int 指针, reference count = 1
	std::shared_ptr<int> p4(new int, deleter);	//	同上, 但是有自己的 destructor 
												//	结构里有指针, 默认的destructor 不会释放指针指向的内存, 需要自定删除器


	std::shared_ptr<int> p5(new int, [](int* p) {delete p; }, std::allocator<int>());	//	同p4, 但拥有独立的分配器/constructor
	std::shared_ptr<int> p6(p5);														//	若p5 reference count = 0, 则p6 的reference count =0
																						//	否则, p6 的 reference count 在 p5 的基础上 +1

	std::shared_ptr<int> p7(std::move(p6));												//	获取p6 资源的所有权, p6 所拥有的指针指向 nullptr, reference count = 0
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

	bar = std::make_shared<int>(20);	// stored pointer 改变, reference count = 1

	std::unique_ptr<int> unique(new int(30));
	foo = std::move(unique);	//	move from unique_ptr


	foo.swap(bar);		//	交换2个shared_ptr 指向的内存

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
	//std::unique_ptr<int> pint2 = std::move(pint);	//	转移所有权, 原 unique_ptr 指针为 nullptr
	
	//
	//std::unique_ptr<int> ret = clone(4);


	char msg[5] = { 65,66,67,68,69 };

	//char* data = read(msg,5)->getPayLoad();	//	data 无意义
	//std::cout << "data[0] = " << data[0] << "\n";


	auto data = read(msg, 5);
	char* data_payload = data->getPayLoad();
	std::cout << "data[0] = " << data_payload[0] << "\n";



	return 0;
}



/**
 *	shared_ptr 线程安全性
 */




int main()
{
	//raii_template_test();
	//auto_ptr_doodle();
	//shared_ptr_assignment_doole();

	//unique_ptr_constructor_doodle();
	//unique_ptr_assignment_doodle();





	return 0;
}