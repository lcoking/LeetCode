#pragma once
#include "CmdHandler.h"
class MyParser : public CmdHandler
{
public:
	MyParser();
	~MyParser();

	virtual void OnCommand(const std::string &cmdline);	//

private:
	int Split(const std::string &text, std::string &parts);
};

