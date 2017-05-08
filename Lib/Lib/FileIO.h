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
    void CopyFile(string SourceFile, string NewFile);
    void DeleteFile(string location);
    void ListDir(LPCTSTR lpFileName);
    void Backup();
};
 