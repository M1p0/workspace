#pragma once

#include <thread>
#include <string>
#include <string.h>
#define BUF_SIZE 512

#ifdef _WIN32

#include <winsock2.h>
#pragma comment(lib,"Ws2_32.lib")

#else
#include <netinet/in.h> //�׽��ֵ�ַ�ṹ
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define SOCKET int
#define Sleep(x) sleep(x)
#endif 

#pragma pack(1)
struct Packet
{
    size_t Length;
    char Data[BUF_SIZE];
};
#pragma pack()


class MSocket
{
public:
    MSocket();
    ~MSocket();
    int Init();
    int Send(SOCKET Socket, char* Msg, int Length);
    int Recv(SOCKET Socket, char* Msg);
    int Connect(SOCKET s, const char *Name,int Port,int Family=AF_INET);
    int Bind(SOCKET s, int Port, int Family= AF_INET);

private:
    int RetVal;
    WSADATA wsd;
};

