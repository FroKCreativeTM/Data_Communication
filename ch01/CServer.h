#pragma once

#include "Includes.h"

class CServer
{
private : 
	WSADATA			m_wsaData;
	// ���� ����
	SOCKET			m_serverSocket;
	SOCKET			m_clientSocket;
	// �ּ� ����
	SOCKADDR_IN		m_serverAddress;
	SOCKADDR_IN		m_clientAddress;			

private :
	void error_message(const char* message);

private : 
	/* �ʿ���� �����ڵ� ���Ƶα�. */
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

