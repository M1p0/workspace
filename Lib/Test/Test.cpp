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
        cout << "������ԭ�ļ���ַ" << endl;
        cin >> SourceFile;
        cout << "���������ļ���ַ" << endl;
        cin >> NewFile;
        File.Copy(SourceFile, NewFile);
    }
    else if (cmd == "BackUp")
    {
        File.Backup();
    }


}
