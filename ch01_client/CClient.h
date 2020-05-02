#pragma once

#include "Includes.h"

class CClient
{
private : 
	WSADATA			m_wsaData;
	// 접속할 소켓 정보
	SOCKET			m_serverSocket;
	// 주소 정보
	SOCKADDR_IN		m_serverAddress;
	// 서버로부터 받을 데이터 저장 장소
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

