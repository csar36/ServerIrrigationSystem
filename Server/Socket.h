#ifndef __SOCKET_H__
#define __SOCKET_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <iostream>
#include <string.h>

#include "Logger.h"

class Socket
{
    public:
        Socket();
        Socket(const Socket&) = delete;
        ~Socket();

        void Create();

        Logger *log;
        struct sockaddr_in addr;
        int sockfd;
};

#endif
