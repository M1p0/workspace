#include "FileIO.h"
#include <iostream>
using namespace std;

void FileIO::Create(string location)
{
    ofstream CreateFile(location);
    CreateFile.close();
}

void FileIO::Write(string location, string data)
{
    ofstream WriteFile(location,ios::app);
    WriteFile << data;
    WriteFile.close();
}
 
void FileIO::Read(string location)
{
    char buffer[256];
    ifstream ReadFile(location);
    if (!ReadFile.is_open())
    {
        cout << "Fail to Read the file" << endl;
        return;
    }
    while (!ReadFile.eof())
    {
        ReadFile.getline(buffer, 100);
        cout << buffer << endl;
    }

}


void FileIO::CopyFile(char *SourceFile, char *NewFile)
{
    ifstream in;
    ofstream out;
    in.open(SourceFile, ios::binary);
    if (in.fail())
    {
        cout << "Fail to open the source file" << endl;
        in.close();
        out.close();
        return;
    }
    out.open(NewFile, ios::binary);
    if (out.fail())
    {
        cout << "Fail to create the new File" << endl;
        in.close();
        out.close();
        return;
    }
    else
    {
        out << in.rdbuf();
        out.close();
        in.close();
        return;
    }

}


void FileIO::ListDir()
{
    WIN32_FIND_DATA FileData;
    HANDLE hSearch;
    BOOL finished = FALSE;
    LPCTSTR lpFileName = L"D:\\*.*";

    hSearch= FindFirstFile(L"D:\\\*.*", &FileData);

    while (FindNextFile(hSearch, &FileData))
    {
    
        cout << "得到文件：" << FileData.cFileName<< endl;
    }
    
}
