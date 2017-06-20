#include <iostream>
#include "LinkList.h"
#include "FileIO.h"
#include <string>
#include "utils.h"
using namespace std;


int main()
{
    FileIO File;
    string cmd = getcmd();
    if (cmd == "Copy")
    {
        string SourceFile, NewFile;
        cout << "请输入原文件地址" << endl;
        cin >> SourceFile;
        cout << "请输入新文件地址" << endl;
        cin >> NewFile;
        File.Copy(SourceFile, NewFile);
    }
    else if (cmd == "BackUp")
    {
        File.Backup();
    }


}
