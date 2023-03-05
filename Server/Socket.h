#ifndef __SOCKET_H__
#define __SOCKET_H__
#include <sys/socket.h>

class Socket
{
    public:
        Socket();
        Socket(const Socket&) = delete;
        ~Socket();

        void CreateSocket();
        sockaddr_in addr;
        
        int sockfd;
};

#endif