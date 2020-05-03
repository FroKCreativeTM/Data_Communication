#include "CClient.h"
#include "Includes.h"

int main(int argc, char** argv)
{
	CClient* client = new CClient(argc, argv);
	client->Connect(argc, argv);
	delete client;
	return 0;
}