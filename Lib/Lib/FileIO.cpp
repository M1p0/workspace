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
    ofstream WriteFile(location, ios::app|ios::binary);
    WriteFile.write(data.c_str(),data.size());
    WriteFile.flush();
    WriteFile.close();
}

void FileIO::Read(string location,int mode)
{
    char ch;
    char buffer[256];
    ifstream ReadFile(location,ios::binary);
    if (!ReadFile.is_open())
    {
        cout << "Failed to Read the file" << endl;
        return;
    }
    while (ReadFile.peek()!=EOF)                //或cout<<ReadFile.rdbuf()
    {
        if (mode==1)
        {
            ReadFile.get(ch);   //二进制方式
            cout << ch;
        }
        if (mode==0)
        {
            ReadFile.getline(buffer, 100);  //文本方式
            cout << buffer << endl;
        }
    }


}


void FileIO::Copy(string SourceFile, string NewFile)
{
    string data;
    char ch;
    ifstream in;
    ofstream out;
    in.open(SourceFile.c_str(), ios::binary);
    if (in.fail())
    {
        cout << "Failed to open source file" << endl;
        in.close();
        out.close();
        return;
    }
    out.open(NewFile.c_str(), ios::binary);
    if (out.fail())
    {
        cout << "Failed to create new file" << endl;
        in.close();
        out.close();
        return;
    }
    else
    {
        while (in.peek()!=EOF) //二进制方式写入文件
        {
            
            in.get(ch);
            data = ch;
            out.write(data.c_str(), data.size());  //每次仅读写一字节 效率需要优化
            out.flush();
        }
    }
    out.close();
    in.close();
    return;

}



void FileIO::ListDir(LPCTSTR lpFileName)
{
    WIN32_FIND_DATA FileData;
    HANDLE hSearch;

    hSearch = FindFirstFile(lpFileName, &FileData);
    while (FindNextFile(hSearch, &FileData))
    {
        if (FileData.dwFileAttributes==16)
            cout << "文件夹:" << FileData.cFileName << endl;
        else
            cout << "文件：" << FileData.cFileName << endl;
        //cout << FileData.dwFileAttributes << endl; //若为文件夹 则数值为16
    }
}




void FileIO::CopyFolder(string szPath, string szTarget)
{
    string szTemp;
    LPCTSTR lpFolder;
    WIN32_FIND_DATA FileData;
    HANDLE hSearch;
    szTemp = szPath;
    szPath = szPath + "\\*.*";
    lpFolder = szPath.c_str();
    hSearch = FindFirstFile(lpFolder, &FileData);
    while (FindNextFile(hSearch, &FileData))
    {
        if (FileData.dwFileAttributes == 16)
        {
            if (FileData.cFileName[0] == '.') //排除本级目录和父级目录
                continue;
            string *NewFolder = new string(szTemp);
            *NewFolder = *NewFolder + "\\" + FileData.cFileName; //新目录
            string *NewTarget = new string(szTarget);
            *NewTarget = *NewTarget + "\\" + FileData.cFileName;  //更改目标至文件夹
            CreateDirectory(NewTarget->c_str(), NULL); //在目标目录内创建文件夹
            CopyFolder(*NewFolder, *NewTarget);
        }
        else
        {
            string *szSource = new string(szTemp);
            string *Target = new string(szTarget);
            *Target = *Target + "\\" + FileData.cFileName;
            *szSource = *szSource + "\\" + FileData.cFileName;
            Copy(*szSource, *Target);
        }

    }
}



void FileIO::Backup() //功能不完善 需要修改
{
    string szSource;
    string szPath;
    string Temp;

    cout << "请输入文件目录:" << endl;
    cin >> szPath;
    Temp = szPath + "\\*.*";
    ListDir(Temp.c_str());
    cout << "请输入文件名:" << endl;
    cin >> szSource;

    string szTemp = szPath + "\\";
    string szTarget;
    string szTarget_Name;
    if (szSource == "*")
    {
        cout << "请输入目标地址:" << endl;
        cin >> szTarget;
        szTarget = szTarget + "\\";
        CopyFolder(szPath, szTarget);
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


