#include <iostream>
#include <string>
#include "tools.h"
#include "utils.h"
#include "FileIO.h"
#include "CFileIO.h"
#include "Hw_event.h"
using namespace std;



int main()
{
    //FileIO File;
    //string cmd;
    //cmd = getcmd();
    //if (cmd == "BackUp")
    //{
    //    File.Backup();
    //}
    //File.Read("D:\\test.txt");
    //test();
    SetDelay(3000);
    SetMouse(484, 376);
    LeftDown();
    SetDelay(1000);
    SetMouse(495, 376);
    LeftUp();

}