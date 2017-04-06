#include <iostream>
#include "FileIO.h"
#include <string>
using namespace std;

string command(FileIO &File)
{
    string cmd;
    cin>>cmd;
    if(cmd=="CopyFile")
    {
        File.CopyFile()
        //cout<<"CopyFile";
    }
    return cmd;
}

int main()
{
    string str;
    str=command();    

    system("pause");
}
