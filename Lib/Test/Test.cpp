#include <iostream>
#include <string>
#include <MSocket.h>
#include <cstdlib>
using namespace std;



int main()
{


    MSocket sock;
    SOCKET sClient;
    SOCKET sHost = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    sock.Bind(sHost, 9000);
    sock.Listen(sHost, 5);
    sClient = sock.Accept(sHost);
    while (true)
    {
        char buff[4];
        memset(buff,0, 4);
        sock.Recv(sClient, buff, 4);
        cout << buff << endl;
    }


    //MSocket sock;
    //SOCKET s;
    //s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    //sock.Connect(s, "192.168.1.2", 9000);
    //while (true)
    //{
    //    sock.Send(s, "123", 3);
    //    Sleep(100);
    //}



}






