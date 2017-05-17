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


void FileIO::Copy(string SourceFile,string NewFile)
{
    ifstream in;
    ofstream out;
    in.open(SourceFile.c_str(), ios::binary);
    if (in.fail())
    {
        cout << "Fail to open source file" << endl;
        in.close();
        out.close();
        return;
    }
    out.open(NewFile.c_str(), ios::binary);
    if (out.fail())
    {
        cout << "Fail to create new file" << endl;
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
        cout << "得到文件：" << FileData.cFileName<< endl;
    }
}


void FileIO::GetDir(LPCTSTR lpFileName)
{
    WIN32_FIND_DATA FileData;
    HANDLE hSearch;
    int i = 0;
    hSearch = FindFirstFile(lpFileName, &FileData);
    while (FindNextFile(hSearch, &FileData))
    {
        Name[i].szName=FileData.cFileName;
        Name[i + 1].szName = "\t";
        i++;
    }
}

void FileIO::Backup()
{


    string  szPath, szTemp;
    cout << "请输入文件地址:" << endl;
    cin >> szPath;
    szTemp = szPath+"\\";
    szPath += "\\*.*";


    LPCTSTR lpPath;
    lpPath = szPath.c_str();
    ListDir(lpPath);

    string szSource;
    string szTarget;
    string szTarget_Name;
    cout << "请输入原文件名:" << endl;
    cin >> szSource;
    if (szSource=="*")
    {
        GetDir(lpPath);
        cout << "请输入拷贝地址:" << endl;
        cin >> szTarget;
        szTarget = szTarget + "\\";
        for (int i=1;Name[i].szName!="\t";i++)
        {
            string szSourceTmp;
            string szTargetTmp;
            szSourceTmp= szTemp + Name[i].szName;
            szTargetTmp = szTarget + Name[i].szName;

            Copy(szSourceTmp, szTargetTmp);
        }

    }
    else
    {
        szSource = szTemp + szSource;
        cout << "请输入拷贝地址:" << endl;
        cin >> szTarget;
        szTarget = szTarget + "\\";
        cout << "请输入新文件名:" << endl;
        cin >> szTarget_Name;
        szTarget = szTarget + szTarget_Name;
        Copy(szSource, szTarget);
    }

}