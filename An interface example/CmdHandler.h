#pragma once
#include <iostream>
#include <string>	//for the usage of std::cin>>string object
//CmdHandle  ½Ó¿ÚÀà
class CmdHandler
{
public:
	virtual ~CmdHandler() {};
	virtual void OnCommand(const std::string &cmdline) = 0;
protected:
	CmdHandler() {};
private:
};