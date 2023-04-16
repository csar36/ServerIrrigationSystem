#include "Logging/Logger.h"
#include "Server/Server.h"
#include <chrono>
#include <thread>




int main()
{
	Server myServer;

	myServer.Init();
	myServer.Start(3000);

	for(unsigned int i = 0; i < 1000; i++)
	{
		myServer.ListenForClients();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}


	Logger* myLogger = Logger::GetInstance();
	myLogger->writeInfoEntry("main", "Hallo");

	return 0;
}
