#pragma once

#include <thread>
#include <string>
#include <string.h>


#ifdef _WIN32

#include <winsock2.h>
#pragma comment(lib,"Ws2_32.lib")

#elif defined __linux__
#include <netinet/in.h> //�׽��ֵ�ַ�ṹ
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define SOCKET int
#endif 

class MSocket
{
public:
    int Send(SOCKET Socket,std::string Msg);
    int Recv(SOCKET Socket, std::string Msg);
private:
    int RetVal;
};

