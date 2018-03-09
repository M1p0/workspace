#include <iostream>
#include "MSocket.h"
using namespace std;


MSocket::MSocket()
{
    Init();
}
MSocket::~MSocket()
{
#ifdef _WIN32
    WSACleanup();
#endif
}

int MSocket::Send(SOCKET Socket, char* Msg, int Length)
{
    int current = 0;
    while (current < Length)
    {
#ifdef _WIN32
        RetVal = send(Socket, Msg, Length - current, 0);
#else
        RetVal = send(Socket, Msg, Length - current, MSG_NOSIGNAL);
#endif
        if (RetVal <= 0)
        {
            cout << "send failed" << endl;
            return -1;
        }
        current = current + RetVal;
    }
    return current;
}

int MSocket::Connect(SOCKET s, const char *Name, int Port, int Family)
{
    int retVal = 0;
    SOCKADDR_IN servAddr;
    servAddr.sin_family = Family;
    servAddr.sin_addr.s_addr = inet_addr(Name);
    servAddr.sin_port = htons((short)Port);
    retVal = connect(s, (sockaddr*)&servAddr, sizeof(servAddr));
    if (retVal == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }

}

int MSocket::Bind(SOCKET s, int Port, int Family)
{
    int retVal = 0;
    SOCKADDR_IN addrServ;
    addrServ.sin_family = Family;
    addrServ.sin_port = htons(Port);
    addrServ.sin_addr.s_addr = INADDR_ANY;
    retVal = ::bind(s, (sockaddr*)&addrServ, sizeof(addrServ));
    if (retVal != 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int MSocket::Init()
{
#ifdef _WIN32
    if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }

#else
    return 0;
#endif
}
