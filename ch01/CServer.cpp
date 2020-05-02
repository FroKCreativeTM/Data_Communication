#include "CServer.h"

void CServer::error_message(const char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(-2);
}

void CServer::Connect(int argc, char** argv)
{
	int clientAddressSize;
	char message[] = "Hello world~";

	if (WSAStartup(MAKEWORD(2, 2), &m_wsaData) != 0) 
	{
		this->error_message("WSAStartup() Error");
	}

	// 소켓 할당 (IPv4, TCP)
	this->m_serverSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (m_serverSocket == INVALID_SOCKET) 
	{
		this->error_message("socket() Error");
	}

	memset(&m_serverAddress, 0, sizeof(m_serverAddress));
	m_serverAddress.sin_family = AF_INET;
	m_serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	m_serverAddress.sin_port = htons(atoi(argv[1]));

	// 서버 소켓에 주소 정보 부착
	if (bind(this->m_serverSocket, (SOCKADDR*)&this->m_serverAddress, sizeof(this->m_serverAddress)) == SOCKET_ERROR)
	{
		this->error_message("bind() Error");
	}

	// 클라이언트 접속 대기
	if (listen(this->m_serverSocket, 5) == SOCKET_ERROR)
	{
		this->error_message("listen() Error");
	}

	// 클라이언트가 들어왔다면
	clientAddressSize = sizeof(this->m_clientAddress);
	// 접속 허용
	this->m_clientSocket = accept(this->m_serverSocket, (SOCKADDR*)&this->m_clientAddress, &clientAddressSize);	

	if (this->m_clientSocket == INVALID_SOCKET)
	{
		this->error_message("accept() Error");
	}

	send(this->m_clientSocket, message, sizeof(message), 0);

	closesocket(this->m_clientSocket);
	closesocket(this->m_serverSocket);

	WSACleanup();
}
