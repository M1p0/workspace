#include <iostream>
#include <string>
#include <MSocket.h>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "Public.h"
using namespace std;



int main()
{
    int a = 10;
    int b;
    char Dst[4]="123";
    char Src[4] = "456";
    strncpy(Dst+2, Src,1);
    cout << Dst << endl;
    
   
   
}





