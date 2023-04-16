#include "Socket.h"

Socket::Socket()
{
	log = Logger::GetInstance();
	sockfd = 0;
}

Socket::~Socket()
{

}

void Socket::Create()
{
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
       log->writeErrorEntry("Socket::Create", "unable to create ocket");
}
