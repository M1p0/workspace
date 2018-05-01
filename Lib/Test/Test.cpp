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
    char a[4096];
    memset(a, 0, 4096);
    CFileIO File;
    File.SetBuffSize(1);
    File.Read("d:\\test.html",a ,0, 4096);
    //File.Copy("d:\\¸Ö±Ê.png", "D:\\¸Ö±Ê2.png");
    cout << a << endl;
}





