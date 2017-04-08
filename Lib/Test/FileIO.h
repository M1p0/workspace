#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class FileIO
{
public:
    void Create(string location);//»ÁFile.Create("c:\\test.txt")
    void Write(string location, string data);
    void CopyFile(char *SourceFile, char *NewFile);
    void FileIO::Read(string location);
};
