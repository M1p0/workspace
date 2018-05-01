#include <iostream>
#include <string>
#include <MSocket.h>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "Public.h"
#include "CFileIO.h"
using namespace std;



int main()
{
    char buffer[1024];
    CFileIO File;
    File.SetBuffSize(1);
    File.Read("d:\\test.html",buffer ,0, 1024);
    //File.Copy("d:\\¸Ö±Ê.png", "D:\\¸Ö±Ê2.png");
    cout << buffer << endl;
}





