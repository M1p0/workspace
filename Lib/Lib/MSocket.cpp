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

int MSocket::Send(SOCKET s, char* Msg, int Length)
{
    int current = 0;
    int retVal = 0;
    while (current < Length)
    {
#ifdef _WIN32
        retVal = send(s, Msg, Length - current, 0);
#else
        retVal = send(s, Msg, Length - current, MSG_NOSIGNAL);
#endif
        if (retVal <= 0)
        {
            cout << "send failed" << endl;
            return -1;
        }
        current = current + retVal;
    }
    return current;
}


int MSocket::Recv(SOCKET s, char * Msg, int Length)
{
    int current = 0;
    int retVal = 0;
    while (current < Length)
    {
#ifdef _WIN32
        retVal = recv(s, Msg, Length, 0);
#else
        retVal = recv(s, Msg, Length, MSG_NOSIGNAL);
#endif
        if (retVal <= 0)
        {
            cout << "recv failed" << endl;
            return -1;
        }
        current = current + retVal;
    }
    return current;
}

int MSocket::Connect(SOCKET s, const char *Name, int Port, int Family)
{
    int retVal = 0;
    sockaddr_in servAddr;
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
        cout << "Connect failed" << endl;
        return -1;
    }

}

int MSocket::Bind(SOCKET s, int Port, int Family)
{
    int retVal = 0;
    sockaddr_in addrServ;
    addrServ.sin_family = Family;
    addrServ.sin_port = htons(Port);
    addrServ.sin_addr.s_addr = INADDR_ANY;
    retVal = ::bind(s, (sockaddr*)&addrServ, sizeof(addrServ));
    if (retVal != 0)
    {
        cout << "Bind failed" << endl;
        return -1;
    }
    else
    {
        return 0;
    }
}

int MSocket::Listen(SOCKET s, int Backlog)
{
    int retVal = 0;
    retVal = listen(s, Backlog);
    if (retVal != 0)
    {
        cout << "Listen failed" << endl;
        return -1;
    }
    else
    {
        return 0;
    }
}

SOCKET MSocket::Accept(SOCKET s)
{
    SOCKET sClient;
#ifdef _WIN32
    int addrClientlen;
#else
    socklen_t addrClientlen;
#endif
    sockaddr_in addrClient;
    addrClientlen = sizeof(addrClient);
    sClient = accept(s, (sockaddr*)&addrClient, &addrClientlen);
    return sClient;
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
