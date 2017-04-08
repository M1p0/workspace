#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class FileIO
{
public:
    void Create(string location);//例如File.Create("c:\\test.txt")
    void Write(string location, string data);
    void Read(string location);
    void CopyFile(char *SourceFile, char *NewFile);
    void DeleteFile(string location);
};
 