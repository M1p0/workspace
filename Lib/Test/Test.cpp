#include <iostream>
#include <string>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "Public.h"
#include "CFileIO.h"
using namespace std;

#define BUFF_SZIE 1024*1024

int main()
{
    char a[32 * 1024] = {0};
    char* buffer=new char[BUFF_SZIE];
    CFileIO File;
    File.Read("d:\\test3.png",buffer ,0, BUFF_SZIE);
   // File.Write("d:\\test2.png", buffer, 0, BUFF_SZIE);
}





