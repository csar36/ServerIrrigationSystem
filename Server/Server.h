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
#include "../Logging/Logger.h"
class Server
{
public:
    Server();
    Server(const Server &) = delete; // Keine Kopie erlauben
    ~Server();
    unsigned int clientId;
    Logger* log;
    Socket socket;
    ClientManager manager;

    void Init();
    void Start(int portNo);
    void ListenForClients();
    void Poll(Client *client);

    struct sockaddr_in addr;
private:
    void error(std::string msg);
};


#endif
