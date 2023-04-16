#ifndef __CLIENTSERVICE_H__
#define __CLIENTSERVICE_H__

#include <vector>
#include "Client.h"

class ClientService
{

public:
    ClientService();
    ClientService(const ClientService&) = delete;
    ~ClientService();

    void RegisterNewClient(Client* client);

    std::vector<int> myVector;
};

#endif
