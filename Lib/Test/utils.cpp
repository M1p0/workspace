#include "utils.h"
#include "FileIO.h"
using namespace std;

string getcmd()
{

    string cmd;
    cin >> cmd;
    return cmd;
}


void test()
{
    DWORD s = GetTickCount();
    FileIO File;
    File.CopyFolder("d:\\test", "d:\\test2");
    cout<<GetTickCount()-s<<endl;
}

