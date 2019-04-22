#pragma once



template <typename T>

class singleton
{
protected:
	singleton() { };


	singleton(const singleton &) = delete;
	singleton& operator=(const singleton &) = delete;
private:
	static T* m_instance;

public:
	static T* GetInstance();
};



template <typename T>
T* singleton<T>::GetInstance()
{
	return m_instance;
}

template <typename T>

T* singleton<T>::m_instance = new T();