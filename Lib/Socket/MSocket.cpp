#include <iostream>
#include "MSocket.h"
using namespace std;


int MSocket::Send(SOCKET Socket, string Msg)
{
#ifdef _WIN32
    RetVal=send(Socket, Msg.c_str(), Msg.size(), 0);
#elif defined __linux__
    RetVal=send(Socket, Msg.c_str(), Msg.size(), MSG_NOSIGNAL);
#endif

    return 0;
}
