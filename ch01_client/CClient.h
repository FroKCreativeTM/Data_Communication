#pragma once

#include "Includes.h"

class CClient
{
private : 
	WSADATA			m_wsaData;
	// ������ ���� ����
	SOCKET			m_serverSocket;
	// �ּ� ����
	SOCKADDR_IN		m_serverAddress;
	// �����κ��� ���� ������ ���� ���
	char*			message;

private : 
	void errorHandling(const char* message);

public : 
	CClient(int argc, char** argv)
	{
		if (argc != 3)
		{
			printf("Usage : %s <IP> <port>\n", argv[0]);
			exit(-1);
		}
	}

	~CClient()
	{
		WSACleanup();
	}

	void Connect(int argc, char ** argv);
};

