#include <iostream>
#include "LinkList.h"
#include "FileIO.h"
#include <string>
using namespace std;

int main()
{

    //FileIO F;

    //string  szPath, szTemp;
    //cout << "请输入文件地址:" << endl;
    //cin >> szPath;
    //szTemp = szPath;
    //szPath += "\\*.*";


    //LPCTSTR lpPath;
    //lpPath = szPath.c_str();

    //F.ListDir(lpPath);

    //string source;
    //string target;
    //cout << "请输入原文件名:" << endl;
    //cin >> source;
    //source = szTemp + source;

    //cout << "请输入拷贝地址:" << endl;
    //cin >> target;

    //F.Create(target);
    //F.CopyFile(source, target);

    FileIO F;
    F.Backup();








}
