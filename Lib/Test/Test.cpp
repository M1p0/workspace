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
    //CFileIO File;
    //string s;
    //s=File.Read("d:\\test.txt");
    //cout << s << endl;
    //cout<<"pos:"<<s.find("222")<<endl;

    FileIO File;
    File.CopyFolder("d:\\test2", "d:\\test3");

}