#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct File_Name
{
    string szName;
};

class FileIO
{
public:
    File_Name Path[256];
    void GetDir(LPCTSTR lpFileName);
    void Create(string location);//例如File.Create("c:\\test.txt")
    void Write(string location, string data);
    void Read(string location);
    void Copy(string SourceFile, string NewFile);
    void DeleteFile(string location);
    void ListDir(LPCTSTR lpFileName);
    void Backup();
};
 
