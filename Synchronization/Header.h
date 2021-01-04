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
 *	shared_ptr for managing memory allocated by malloc & file pointer
 */

// �ͷ��ļ�ָ��
auto fileRelease = [](FILE* fp)
{
	fclose(fp);
	fp = NULL;
	std::cout << "fp released \n";
};


//	�ͷ� malloc ������ڴ�ռ�
template <typename T>
auto mallocFree = [](T* p)
{
	free(p);
	p = NULL;
	std::cout << "malloc memory freed \n";
	
};





