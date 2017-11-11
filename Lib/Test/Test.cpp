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




    CFileIO CFile;
    FileIO File;
    DWORD start;
    std::ios::sync_with_stdio(false);

    start = GetTickCount();
    CFile.CopyA("D:\\test\\ubuntu.iso", "E:\\test\\ubuntu2.iso");
    cout << "C Style:" << GetTickCount() - start << endl;
    

    start = GetTickCount();
    File.Copy("D:\\test\\ubuntu.iso", "E:\\test\\ubuntu.iso");
    cout << "C++ Style:" << GetTickCount() - start << endl;

    //start = GetTickCount();
    //CFile.CopyA("D:\\test\\ubuntu.iso", "E:\\test\\ubuntu2.iso");
    //cout << "C Style:" << GetTickCount() - start << endl;



}





