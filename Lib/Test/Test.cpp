#include <iostream>
#include <string>
#include "tools.h"
#include "CFileIO.h"
using namespace std;



#pragma pack(1)
struct SHeader
{
    size_t Length=1024;
};
struct SData
{
    char buf[1024];
};
#pragma pack()


int main()
{
    
    SHeader Header;
    Header.Length = 1024;

    char temp[1024];
    cin >> temp;
    cout << temp << endl;

    SData Data;
    memcpy(&Data.buf, &temp, 1024);
    cout << Data.buf << endl;

 

}





