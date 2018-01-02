#pragma once
#include <winsock2.h>  
#include <process.h>
#include <string>
#include <mutex>
#pragma comment(lib,"Ws2_32.lib")

namespace MSocket
{

    class Server
    {
    public:
        Server() {};
        ~Server() {};
        int Init();
        void Set(int Port);
        void Show();
    private:
        SOCKADDR_IN addrSer;      //服务器地址 
        WSADATA wsd;//WSADATA变量  
        int Port = 0;
    };

    class Client 
    {
    public:
        Client() {};
        ~Client() {};
        int Init();
        void Set();
    private:
        WSADATA wsd;//WSADATA变量  
    };





}