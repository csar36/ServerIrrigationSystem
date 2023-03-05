#ifndef __CLIENT_MANAGER__
#define __CLIENT_MANAGER__
#include <vector>
#include <cstdint>

#include "Client.h"

class ClientManager
{
public:
    ClientManager();
    ~ClientManager();

    std::vector<Client *> Clients;
    
    
    void RegisterNewClient();
    void setClientId(Client* client);

    
    Client *getClientbyID(int);
};

#endif