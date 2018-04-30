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
    char a[1024];
    memset(a, 0, 1024);
    CFileIO File;
    File.Read("d:\\test.html",a ,0, 1024);
    cout << a << endl;
}





