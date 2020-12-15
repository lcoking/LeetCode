#pragma once
#include <iostream>
#include <memory>

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