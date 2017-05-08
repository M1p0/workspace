#include <windows.h>
#include <iostream>
#include <string>
using namespace std;
void main()
{
    WIN32_FIND_DATA FindFileData;
    HANDLE hFind;

    hFind = FindFirstFile(L"d:\\Flashtool\\*.jar", &FindFileData);
    wcout << FindFileData.cFileName << endl;
    FindClose(hFind);

}

