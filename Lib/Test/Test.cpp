#include <string.h>
#include <iostream>
#include <Public.h>
#include <MemPool.h>
#include <vector>
#include <MString.h>
using namespace std;


void* operator new(size_t size)
{
    cout << "operator new:" << size << endl;
    return malloc(size);
}

int main()
{
    double* a = new double(5);
    getchar();
}





