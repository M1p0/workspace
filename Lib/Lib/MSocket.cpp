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

int MSocket::Send(SOCKET s, const char* Msg, int Length)
{
    int current = 0;
    int retVal = 0;
    if (Length==0)
    {
        send(s, Msg, 0, 0);
        int error = WSAGetLastError();
        if (error!=0)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    while (current < Length)
    {
#ifdef _WIN32
        retVal = send(s, Msg + current, Length - current, 0);
#else
        retVal = send(s, Msg + current, Length - current, MSG_NOSIGNAL);
#endif
        if (retVal <= 0)
        {
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
    fd_set fds;
    FD_ZERO(&fds);
    int recv_count = 0;
    while (current < Length)
    {
        int result = 0;
        if (recv_count == 0)
        {
            result = 1;
        }
        else
        {
            timeval tv = { 0,0 };
            if (!FD_ISSET(s, &fds))
            {
                FD_SET(s, &fds);
            }
            result = select(s+1, &fds, NULL, NULL, &tv);  //判断缓冲区是否还有数据
        }
        if (result > 0)
        {
#ifdef _WIN32

            retVal = recv(s, Msg + current, Length - current, 0);

#else
            retVal = recv(s, Msg + current, Length - current, MSG_NOSIGNAL);

#endif
            ++recv_count;
            if (retVal <= 0)
            {
                if (current != 0)
                {
                    return current;
                }
                else
                {
                    return -1;
                }
            }
            current = current + retVal;
        }
        else
        {
            break;
        }
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
        return -1;
    }
    else
    {
        return 0;
    }
}

int MSocket::Close(SOCKET s)
{
#ifdef _WIN32
    closesocket(s);
#else
    close(s);
#endif
    return 0;
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

int MSocket::Getpeername(SOCKET Client, Cli_Info &CInfo)
{
    sockaddr_in Sa_In;
#ifdef _WIN32
    int len = sizeof(Sa_In);
#else
    socklen_t len = sizeof(Sa_In);
#endif // _WIN32


    if (getpeername(Client, (struct sockaddr *)&Sa_In, &len) == 0)
    {
        CInfo.ip = inet_ntoa(Sa_In.sin_addr);
        CInfo.port = ntohs(Sa_In.sin_port);  //IPV6需要使用inet_pton()
        return 0;
    }
    else
    {
        return -1;
    }
}

int MSocket::GetHostByName(const char * HostName, char * HostIP,int Size)
{
    hostent* pHE = gethostbyname(HostName);
    if (pHE&&HostIP&&HostName)
    {
        if (strlen(inet_ntoa(*((in_addr*)pHE->h_addr_list[0])))>Size)
        {
            return -1;
        }
        else
        {
            strcpy(HostIP, inet_ntoa(*((in_addr*)pHE->h_addr_list[0])));
            return 0;
        }
        
    }
    else
    {
        return -1;
    }

}

