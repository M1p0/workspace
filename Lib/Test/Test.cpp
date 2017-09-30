#include <iostream>
#include <string>
#include "tools.h"
#include "utils.h"
#include "FileIO.h"
#include "CFileIO.h"
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
    CFileIO File;
    string a;
    a=File.Read("d:\\test2\\1.txt");
    cout << a << endl;
    File.Write("d:\\test2\\2.txt", a);
}