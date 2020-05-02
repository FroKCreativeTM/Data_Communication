#include "CServer.h"
#include "Includes.h"

int main(int argc, char** argv)
{
	CServer * server = new CServer(argc, argv);

	server->Connect(argc, argv);

	delete server;

	return 0;
}