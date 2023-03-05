#include "Socket.h"

Socket::Socket() {}

Socket::~Socket() {}

void Socket::CreateSocket()
{
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
}