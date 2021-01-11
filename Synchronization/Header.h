#pragma once
#include <iostream>
#include <memory>
#include <vector>

template<typename T>
class auto_release_ptr
{
public:
	auto_release_ptr(T* t) :_t(t) {};
	~auto_release_ptr()
	{
		delete[] _t;
	}

	T* getPtr()
	{
		return _t;
	}

private:
	T *_t;
};



/**
 *	shared_ptr for managing memory allocated by malloc & file pointer & dynamical arrays
 */

// 释放文件指针
struct fileRelease_struct
{
	void operator ()(FILE* fp)
	{
		fclose(fp);
		fp = NULL;
		std::cout << "fp released by class member function operator().\n";
	}
};

auto fileRelease_lambda = [](FILE* fp)
{
	fclose(fp);
	fp = NULL;
	std::cout << "fp released by lambda.\n";
};


//	释放 malloc 分配的内存空间
template <typename T>
struct mallocFree_struct
{
	void operator ()(T* p)
	{
		free(p);
		p = NULL;
		std::cout << "malloc memory freed by struct member operator().\n";
	}
};

template <typename T>
auto mallocFree_lambda = [](T* p)
{
	free(p);
	p = NULL;
	std::cout << "malloc memory freed by lambda.\n";
	
};


//	释放 new[] 分配的数组空间
template <typename T>
struct array_delete_struct
{
	void operator ()(T const* p)
	{
		delete[] p;
		printf("dynamically array deleted by class member operator(). \n");
	}
};

template <typename T>
auto array_delete_lambda = [](T const* p)
{
	delete[] p;
	printf("dynamically array deleted by lambda. \n");
};