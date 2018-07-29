#include <iostream>
#include <windows.h>
#include <utility>
#include <BitMap.h>
using namespace std;




int main()
{


    BitMap bitmap(32);
    bitmap.Insert(1);
    bitmap.Insert(2);
    cout << bitmap[0] << endl;
    cout << bitmap[1] << endl;
    cout << bitmap[2] << endl;
    cout << bitmap[31] << endl;
    bitmap[31] = 1;
}




