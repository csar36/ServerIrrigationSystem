#include "Server.h"

Server::Server()
{
	// Get Instance of Logger Oject
	log = Logger::GetInstance();
}

Server::~Server()
{}

void Server::Init()
{
	/*
	 * Get Socket and set Port
	 * Server Addr is fix.
	 */
   socket = new Socket();
   socket.Create();
}

void Server::Start(int portNo)
{
	/*
	 * Binded den Sockets im übergebenen Port
	 * */
	log->writeInfoEntry("Server::StartServer", "Socket created");
	bzero((char *) &addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(portNo);

    if (bind(socket.sockfd, (struct sockaddr *) &addr,sizeof(addr)) < 0)
    	log->writeErrorEntry("Server::Start", "unable to bind socket");
}


void Server::ListenForClients(Client* p_client)
{
	 Client* p_newClient = new Client();
	 p_newClient->socket.Create();
     if(listen(socket.sockfd, 5)==0)
     {
    	 socklen_t clilen = sizeof(p_newClient->socket.addr);
         p_client->socket.sockfd = accept(p_newClient->socket.sockfd,
                     (struct sockaddr *) &p_newClient->socket.addr,
                     &clilen);
         Server::clientId++;
         p_client->clientId = Server::clientId;
         manager.Clients.push_back(p_client);
         std::string logMsg= "Client was pushed to ClientManager with client Id ";
         logMsg += std::to_string(Server::clientId);
         log->writeErrorEntry("Server::ListenForClients", logMsg);
     }
     else
     {
    	 log->writeErrorEntry("Server::ListenForClients", "prepare to accept sockets on socket fd failed!");
     }

}

void Server::error(std::string msg)
{
   std::cout << msg << std::endl;
   exit(1);
}

