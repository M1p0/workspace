#include <winsock2.h>  
#include <iostream> 
#include <windows.h>
#include "MSocket.h"
using namespace std;
using namespace MSocket;



int Server::Init()
{
    if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0) //≥ı ºªØsocket
    {
        cout << "WSAStartup failed!" << endl;
        return -1;
    }

    return 0;
}

void Server::Set(int Port)
{

    this->Port = Port;
}


void Server::Show()
{
    cout << Port << endl;
}
