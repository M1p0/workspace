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

    int x = 1;
    char *p = (char *)&x;

    if (*p)
    {
        printf("little\n");
    }
    else
    {
        printf("large\n");
    }
    return 0;
}





