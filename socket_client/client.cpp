
#include <iostream>

//#include <WinSock2.h>
#include <WS2tcpip.h>	// for the usage of inet_pton
#include <string>	// for the usage of std::cin>>std::string
#include "console_Color.h"


#pragma comment(lib, "ws2_32.lib")


int main()
{
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA data;

	if (WSAStartup(sockVersion, &data) != 0)
	{
		return 0;
	}

	while (true)
	{
		SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (sclient == INVALID_SOCKET)
		{
			std::cout << RED << "\n invalid socket !\n" << RESET << std::endl;
			return 0;
		}

		sockaddr_in serAddr;
		serAddr.sin_family = AF_INET;
		serAddr.sin_port = htons(8888);

		inet_pton(AF_INET, "127.0.0.1", &serAddr.sin_addr);	// 将点分十进制字符串转为long 型

		// 连接失败
		if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
		{
			std::cout << YELLOW << "\n connect error !\n" << RESET << std::endl;
			closesocket(sclient);
			return 0;
		}

		std::string data;
		std::cin >> data;
		const char *sendData;
		sendData = data.c_str();
		send(sclient, sendData, (int)strlen(sendData), 0);

		char recvData[255];
		int ret = recv(sclient, recvData, 255, 0);
		if (ret>0)
		{
			recvData[ret] = 0x00;
			std::cout << recvData;
		}
		closesocket(sclient);

	}

	WSACleanup();
	return 0;

}

