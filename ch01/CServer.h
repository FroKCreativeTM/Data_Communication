#pragma once

#include "Includes.h"

class CServer
{
private : 
	WSADATA			m_wsaData;
	// 소켓 정보
	SOCKET			m_serverSocket;
	SOCKET			m_clientSocket;
	// 주소 정보
	SOCKADDR_IN		m_serverAddress;
	SOCKADDR_IN		m_clientAddress;			

private :
	void error_message(const char* message);

private : 
	/* 필요없는 생성자들 막아두기. */
	CServer() {}
	CServer(const CServer& ref) {}
	CServer& operator=(const CServer& ref) {}

public : 
	CServer(int argc, char ** argv)
	{
		if (argc != 2)
		{
			printf("Usage : %s <port>\n", argv[0]);
			exit(-1);
		}
	}

	~CServer()
	{
		WSACleanup();
	}

	void Connect(int argc, char** argv);
};

