#pragma once

#include <iostream>
#include<memory>	//for the usage of unique_ptr




class widget
{
public:
	widget(int);
	~widget();	//defined in the implementation file, where impl is a complete type
	widget(widget &&) = default;	//移动构造函数
	widget(const widget&) = delete;	//复制构造函数
	widget& operator=(widget &&) = default;
	widget& operator=(const widget &) = delete;
public:
	void draw() const;	//public API that will b forwarded to the implementation
	void draw();
	bool shown() const
	{
		return true;
	}
//private:
	class impl;	//things to be hidden go here
	std::unique_ptr<impl> pImpl;	//opaque pointer to forward-declared class
};


