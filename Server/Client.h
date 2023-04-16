#ifndef __CLIENT_H__
#define __CLIENT_H__
#include "Socket.h"
#include <netinet/in.h>
#include <string>




/**
 * @brief 
 * Protocoll: Bytes 0-1: length of the msg in bytes
 *            Bytes 2-n: msg
**/



class Client
{
    public:

        Client();
        ~Client();
        
        Socket socket;
        unsigned int clientId;

        std::string ReceiveMsgCharacterBased();
        void SendMsgCharacterProt(std::string msg);

        std::string ReceiveMsgProtocollBased();
        void SendMsgProtocollBased(std::string msg);
};


#endif
