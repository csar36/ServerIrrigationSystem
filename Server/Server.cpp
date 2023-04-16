#include "Server.h"

Server::Server()
{
	// Get Instance of Logger Oject
	clientId = 0;
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
   socket = Socket();
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


void Server::ListenForClients()
{

	 Client* p_newClient = new Client();
	 p_newClient->socket.Create();
     if(listen(socket.sockfd, 5)==0)
     {
    	 socklen_t clilen = sizeof(p_newClient->socket.addr);
    	 p_newClient->socket.sockfd = accept(p_newClient->socket.sockfd,
                     (struct sockaddr *) &p_newClient->socket.addr,
                     &clilen);
    	 if(p_newClient->socket.sockfd < 0)
    	 {
    		 log->writeInfoEntry("Server::ListenForClients", "no client found.. retry!");
    	 }
    	 else
    	 {
             clientId++;
             p_newClient->clientId = Server::clientId;
             manager.Clients.push_back(p_newClient);
             std::string logMsg= "Client was pushed to ClientManager with client Id ";
             logMsg += std::to_string(Server::clientId);
             log->writeInfoEntry("Server::ListenForClients", logMsg);
    	 }

     }
     else
     {
    	 log->writeInfoEntry("Server::ListenForClients", "Failed - prepare to accept connections on socket FD!");
     }

}

void Server::error(std::string msg)
{
   std::cout << msg << std::endl;
   exit(1);
}

