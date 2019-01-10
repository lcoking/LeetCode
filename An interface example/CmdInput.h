#pragma once
#include "CmdHandler.h"


class CmdInput
{
public:
	CmdInput();


	void SetHandler(CmdHandler *pCHandler);
	int run();

private:
	CmdHandler *m_pCHandler;
};
