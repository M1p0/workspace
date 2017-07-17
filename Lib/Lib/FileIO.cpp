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
    while (ReadFile.peek()!=EOF)                //��cout<<ReadFile.rdbuf()
    {
        if (mode==1)
        {
            ReadFile.get(ch);   //�����Ʒ�ʽ
            cout << ch;
        }
        if (mode==0)
        {
            ReadFile.getline(buffer, 100);  //�ı���ʽ
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
        while (in.peek()!=EOF) //�����Ʒ�ʽд���ļ�
        {
            
            in.get(ch);
            data = ch;
            out.write(data.c_str(), data.size());  //ÿ�ν���дһ�ֽ� Ч����Ҫ�Ż�
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
            cout << "�ļ���:" << FileData.cFileName << endl;
        else
            cout << "�ļ���" << FileData.cFileName << endl;
        //cout << FileData.dwFileAttributes << endl; //��Ϊ�ļ��� ����ֵΪ16
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
            if (FileData.cFileName[0] == '.') //�ų�����Ŀ¼�͸���Ŀ¼
                continue;
            string *NewFolder = new string(szTemp);
            *NewFolder = *NewFolder + "\\" + FileData.cFileName; //��Ŀ¼
            string *NewTarget = new string(szTarget);
            *NewTarget = *NewTarget + "\\" + FileData.cFileName;  //����Ŀ�����ļ���
            CreateDirectory(NewTarget->c_str(), NULL); //��Ŀ��Ŀ¼�ڴ����ļ���
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



void FileIO::Backup() //���ܲ����� ��Ҫ�޸�
{
    string szSource;
    string szPath;
    string Temp;

    cout << "�������ļ�Ŀ¼:" << endl;
    cin >> szPath;
    Temp = szPath + "\\*.*";
    ListDir(Temp.c_str());
    cout << "�������ļ���:" << endl;
    cin >> szSource;

    string szTemp = szPath + "\\";
    string szTarget;
    string szTarget_Name;
    if (szSource == "*")
    {
        cout << "������Ŀ���ַ:" << endl;
        cin >> szTarget;
        szTarget = szTarget + "\\";
        CopyFolder(szPath, szTarget);
    }
    else
    {
        szSource = szTemp + szSource;
        cout << "�����뿽����ַ:" << endl;
        cin >> szTarget;
        szTarget = szTarget + "\\";
        cout << "���������ļ���:" << endl;
        cin >> szTarget_Name;
        szTarget = szTarget + szTarget_Name;
        Copy(szSource, szTarget);
    }
}


