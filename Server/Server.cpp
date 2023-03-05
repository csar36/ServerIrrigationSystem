#include "Server.h"

Server::Server() {}

Server::~Server() {}

void Server::Init(sockaddr_in server_addr)
{
   socket.addr = server_addr;
}

void Server::Bind()
{
   socket.CreateSocket();
   if (bind(socket.sockfd, (struct sockaddr *) &socket.addr,
         sizeof(socket.addr)) < 0)
         error("ERROR on binding");
}

void Server::ListenForClients(Client* p_client)
{
     listen(socket.sockfd, 5);
     int clilen = sizeof(p_client->socket.addr);
     p_client->socket.sockfd = accept(socket.sockfd,
                 (struct sockaddr *) &p_client->socket.addr,
                 &clilen);
     manager.Clients.push_back(p_client);
}

void Server::error(std::string msg)
{
   std::cout << msg << std::endl;
   exit(1);
}

