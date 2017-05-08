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


void FileIO::CopyFile(string SourceFile,string NewFile)
{
    ifstream in;
    ofstream out;
    in.open(SourceFile.c_str(), ios::binary);
    if (in.fail())
    {
        cout << "Fail to open the source file" << endl;
        in.close();
        out.close();
        return;
    }
    out.open(NewFile.c_str(), ios::binary);
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


void FileIO::ListDir(LPCTSTR lpFileName)
{
    WIN32_FIND_DATA FileData;
    HANDLE hSearch;

    hSearch= FindFirstFile(lpFileName, &FileData);
    while (FindNextFile(hSearch, &FileData))
    {
    
        cout << "�õ��ļ���" << FileData.cFileName<< endl;
    }
    
}

void FileIO::Backup()
{

    string  szPath, szTemp;
    cout << "�������ļ���ַ:" << endl;
    cin >> szPath;
    szTemp = szPath;
    szPath += "\\*.*";


    LPCTSTR lpPath;
    lpPath = szPath.c_str();

    ListDir(lpPath);

    string source;
    string target;
    cout << "������ԭ�ļ���:" << endl;
    cin >> source;
    source = szTemp + source;

    cout << "�����뿽����ַ:" << endl;
    cin >> target;

    Create(target);
    CopyFile(source, target);
}