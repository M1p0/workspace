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
    void Read(string location);
    void Copy(string SourceFile, string NewFile);
    void ListDir(LPCTSTR lpFileName);
    void Backup();
    void CopyFolder(string szPath, string szTarget);

};
