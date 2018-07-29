#include <iostream>
#include <windows.h>
#include <utility>
#include <BitMap.h>
using namespace std;




int main()
{


    BitMap bitmap(33);
    bitmap.Insert(0);
    bitmap.Insert(0);
    bitmap.Insert(0);
    cout << bitmap.Size() << endl;



}




