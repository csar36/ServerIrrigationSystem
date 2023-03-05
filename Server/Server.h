#ifndef __SERVER_H__
#define __SERVER_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <iostream>


#include "ClientManager.h"
#include "Socket.h"

class Server
{
public:
    Server();
    Server(const Server &) = delete; // Keine Kopie erlauben
    ~Server();

    Socket socket;
    ClientManager manager;

    void Init(sockaddr_in server_addr);
    void ListenForClients(Client *p_client);
    void Poll(Client *client);

    void Bind();

private:
    void error(std::string msg);
};

#endif
