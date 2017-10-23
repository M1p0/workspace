#include "FileIO.h"


void FileIO::Create(string location)
{
    ofstream CreateFile(location);
    CreateFile.close();
}

void FileIO::Write(string location, string data)
{
    ofstream WriteFile(location, ios::app | ios::binary);
    WriteFile.write(data.c_str(), data.size());
    WriteFile.flush();
    WriteFile.close();
}

void FileIO::Read(string location, int mode)
{
    char *buffer;
    ifstream ReadFile(location, ios::binary);
    if (!ReadFile.is_open())
    {
        cout << "Failed to Read the file" << endl;
        return;
    }

    if (mode == 1)
    {
        ReadFile.seekg(0, ios::end); //定位指针到最后
        long size = ReadFile.tellg();  //获取文件大小
        ReadFile.seekg(0, ios::beg);//重新定位指针至文件头
        buffer = new char[size];
        ReadFile.read(buffer, size);
        cout << buffer << endl;
        delete[]buffer;
    }
    if (mode == 0)
    {
        ReadFile.seekg(0, ios::beg);
        cout << ReadFile.rdbuf() << endl;  //文本方式
    }


}


void FileIO::Copy(string SourceFile, string NewFile)   //无法拷贝到不存在的目录 
{
    ifstream in;
    ofstream out;
    char* buffer;
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
        DWORD R, W;    //R为读取时间 W为写入时间
        in.seekg(0, ios::end); //定位指针到最后
        long size = in.tellg();  //获取文件大小     大文件拷贝存在问题
        in.seekg(0, ios::beg);//重新定位指针至文件头
        buffer = new char[size];
        R = GetTickCount();
        in.read(buffer, size);
        cout << "read:" << GetTickCount() - R << endl;
        W = GetTickCount();
        out.write(buffer, size);
        out.flush();
        cout << "write:" << GetTickCount() - W << endl;
        delete[]buffer;
    }
    in.close();
    out.close();
    return;

}



void FileIO::ListDir(LPCTSTR lpFileName)
{
    WIN32_FIND_DATA FileData;
    HANDLE hSearch;

    hSearch = FindFirstFile(lpFileName, &FileData);
    while (FindNextFile(hSearch, &FileData))
    {
        if (FileData.dwFileAttributes & 16)  
            cout << "文件夹:" << FileData.cFileName << endl;
        else
            cout << "文件:" << FileData.cFileName << endl;
        //cout << FileData.dwFileAttributes << endl; //文件夹属性为16
                                                     //由于可以有多个属性 所以需要用&
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
    CreateDirectory(szTarget.c_str(), NULL);   //创建父级目录
    while (FindNextFile(hSearch, &FileData))
    {
        if (FileData.dwFileAttributes & 16)
        {
            if (FileData.cFileName[0] == '.') //排除本级目录和父级目录
                continue;
            string *NewFolder = new string(szTemp);
            *NewFolder = *NewFolder + "\\" + FileData.cFileName; //新目录
            string *NewTarget = new string(szTarget);
            *NewTarget = *NewTarget + "\\" + FileData.cFileName;  //更改目标至文件夹
            CreateDirectory(NewTarget->c_str(), NULL); //在目标目录内创建文件夹
            CopyFolder(*NewFolder, *NewTarget);
            delete NewFolder;
            delete NewTarget;
        }
        else
        {
            string *szSource = new string(szTemp);
            string *Target = new string(szTarget);
            *Target = *Target + "\\" + FileData.cFileName;
            *szSource = *szSource + "\\" + FileData.cFileName;
            Copy(*szSource, *Target);
            delete szSource;
            delete Target;
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


