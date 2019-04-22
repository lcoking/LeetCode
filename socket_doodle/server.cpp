#include <iostream>

//#include <WinSock2.h>

#include <WS2tcpip.h>	// for the usage of inet_ntop

#include "console_Color.h"

#pragma comment(lib, "ws2_32.lib")




int main(int argc, char *argv[])
{
	// ��ʼ��WSA
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;

	if (WSAStartup(sockVersion, &wsaData)!=0)
	{
		return 0;
	}

	// ����socket
	SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (slisten == INVALID_SOCKET)
	{
		std::cout <<RED<< "\n socket "<<RESET<<"error !\n" << std::endl;
		return 0;
	}

	// ��IP �� �˿�
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8888);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;

	if (bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		std::cout << BLUE << "\n bind " << RESET << "error !\n" << std::endl;
	}

	// ��ʼ����
	if (listen(slisten, 5) == SOCKET_ERROR)
	{
		std::cout << YELLOW << "\n listen " << RESET << "error !\n" << std::endl;
	}

	// ѭ����������
	SOCKET sClient;
	sockaddr_in remoteAddr;
	int nAddrlen = sizeof(remoteAddr);

	char revData[255];
	while (true)
	{
		std::cout << "\n �ȴ�����...\n";
		sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);

		if (sClient  == INVALID_SOCKET)
		{
			std::cout << MAGENTA << "\n accept " << RESET << "error !\n" << std::endl;
			continue;
		}
		char str[255];
		std::cout << "\n ���յ�һ������: "<< inet_ntop(AF_INET,(void *)&remoteAddr.sin_addr, str, sizeof(str))<<std::endl;	

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
//	USHORT sin_port;	// �˿�
//	IN_ADDR sin_addr;	// internet ��ַ
//	CHAR sin_zero[8];	// �������sockaddr ������ͬ
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