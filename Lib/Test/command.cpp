#include <iostream>
#include "FileIO.h"
#include <string>
using namespace std;

string command(FileIO &File)
{
    string cmd;
    cin >> cmd;
    if (cmd == "CopyFile")
    {
        File.CopyFile(str);
            //cout<<"CopyFile";
    }
    return cmd;
}

void command()
{
    string str;
    str = command();

    system("pause");
}
