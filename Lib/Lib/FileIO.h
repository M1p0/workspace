#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class FileIO
{
public:
    void Create(string location);//例如File.Create("c:\\test.txt")
    void Write(string location, string data);
    void Read(string location,int mode=0);  //0为文本方式 1为二进制方式 
    void Copy(string SourceFile, string NewFile);
    void ListDir(LPCTSTR lpFileName);
    void Backup();
    void CopyFolder(string szPath, string szTarget);
};
