#include "CmdInput.h"


CmdInput::CmdInput()
{
	m_pCHandler = nullptr;
}

void CmdInput::SetHandler(CmdHandler *pCHandler)
{
	m_pCHandler = pCHandler;
}

int CmdInput::run()
{
	std::string cmdline;

	while (true)
	{
		std::cout << "> \n";
		std::cin >> cmdline;
		if (cmdline.compare("exit") == 0)
		{
			break;
		}

		if (m_pCHandler)
		{
			m_pCHandler->OnCommand(cmdline);
		}

	}
	return 0;

}