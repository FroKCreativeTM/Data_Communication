#include "CClient.h"

void CClient::errorHandling(const char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(-2);
}

void CClient::Connect(int argc, char** argv)
{
	int strLen;

	if (WSAStartup(MAKEWORD(2, 2), &m_wsaData) != 0)
	{
		this->errorHandling("WSAStartup() Error");
	}

	this->m_serverSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (this->m_serverSocket == INVALID_SOCKET)
	{
		this->errorHandling("socket() Error");
	}

	memset(&this->m_serverAddress, 0, sizeof(this->m_serverAddress));
	this->m_serverAddress.sin_family = AF_INET;
	this->m_serverAddress.sin_addr.s_addr = inet_addr(argv[1]);
	this->m_serverAddress.sin_port = htons(atoi(argv[2]));

	if (connect(this->m_serverSocket, (SOCKADDR*)&(this->m_serverAddress), sizeof(this->m_serverAddress)) == SOCKET_ERROR)
	{
		this->errorHandling("connect() Error");
	}

	this->message = new char[30];
	strLen = recv(this->m_serverSocket, this->message, sizeof(this->message) - 1, 0);
	
	if (strLen == -1)
	{
		this->errorHandling("recv() Error");
	}

	std::cout << "Message From server : " << message << ", length : " << strLen << std::endl;

	delete[] this->message;

	closesocket(this->m_serverSocket);

	WSACleanup();
}