#include <iostream>
#include <string>
#include <MSocket.h>
#include <cstdlib>
#include <thread>
#include <chrono>
using namespace std;



int main()
{
    MSocket sock;
    SOCKET s;
    SOCKET sClient;
    s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    sock.Bind(s, 9000);
    sock.Listen(s, 10);
    sClient = sock.Accept(s);

    char msg[1024];
    memset(msg, 0, 1024);
    while (true)
    {
        sock.Recv(sClient, msg, 4);
        cout << msg << endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));

}





