#include <iostream>
#include <string>
#include "tools.h"
#include "CFileIO.h"
#include <MSocket.h>
#include <cstdlib>
using namespace std;



int main()
{

    MSocket sock;
    //sock.Init();
    SOCKET sHost = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    sock.Connect(sHost, "192.168.1.2", 9000);

    char*s = "test";
    

    if (sock.Send(sHost, s, strlen(s)))
    {
        return 0;
    }

}






