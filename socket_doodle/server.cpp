#include <iostream>

//#include <WinSock2.h>

#include <WS2tcpip.h>	// for the usage of inet_ntop

#include "console_Color.h"

#pragma comment(lib, "ws2_32.lib")




int main(int argc, char *argv[])
{
	// 初始化WSA
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;

	if (WSAStartup(sockVersion, &wsaData)!=0)
	{
		return 0;
	}

	// 创建socket
	SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (slisten == INVALID_SOCKET)
	{
		std::cout <<RED<< "\n socket "<<RESET<<"error !\n" << std::endl;
		return 0;
	}

	// 绑定IP 和 端口
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8888);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;

	if (bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		std::cout << BLUE << "\n bind " << RESET << "error !\n" << std::endl;
	}

	// 开始监听
	if (listen(slisten, 5) == SOCKET_ERROR)
	{
		std::cout << YELLOW << "\n listen " << RESET << "error !\n" << std::endl;
	}

	// 循环接收数据
	SOCKET sClient;
	sockaddr_in remoteAddr;
	int nAddrlen = sizeof(remoteAddr);

	char revData[255];
	while (true)
	{
		std::cout << "\n 等待连接...\n";
		sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);

		if (sClient  == INVALID_SOCKET)
		{
			std::cout << MAGENTA << "\n accept " << RESET << "error !\n" << std::endl;
			continue;
		}
		char str[255];
		std::cout << "\n 接收到一个连接: "<< inet_ntop(AF_INET,(void *)&remoteAddr.sin_addr, str, sizeof(str))<<std::endl;	

		// receiving data
		int ret = recv(sClient, revData, 255, 0);
		if (ret > 0)
		{
			revData[ret] = 0x00;
			std::cout << revData;
		}

		// sending data
		const char *data2Send = "\n Hello, TCP client! \n";
		send(sClient, data2Send, (int)strlen(data2Send), 0);
		closesocket(sClient);
	}

	closesocket(slisten);
	WSACleanup();

	return 0;
}

////
//// IPv4 Socket address, Internet style
////
//typedef struct sockaddr_in {
//
//#if(_WIN32_WINNT < 0x0600)
//	short   sin_family;
//#else //(_WIN32_WINNT < 0x0600)
//	ADDRESS_FAMILY sin_family;		// AF_INET   IPv4
//									// AF_INET6  IPv6
//#endif //(_WIN32_WINNT < 0x0600)
//
//	USHORT sin_port;	// 端口
//	IN_ADDR sin_addr;	// internet 地址
//	CHAR sin_zero[8];	// 填充以与sockaddr 长度相同
//} SOCKADDR_IN, *PSOCKADDR_IN;
//
//
////
//// Structure used to store most addresses.
////
//typedef struct sockaddr {
//
//#if (_WIN32_WINNT < 0x0600)
//	u_short sa_family;
//#else
//	ADDRESS_FAMILY sa_family;           // Address family.
//#endif //(_WIN32_WINNT < 0x0600)
//
//	CHAR sa_data[14];                   // Up to 14 bytes of direct address.
//} SOCKADDR, *PSOCKADDR, FAR *LPSOCKADDR;