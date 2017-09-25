//beta function
#include <iostream>
#include <windows.h>
using namespace std;


int add(int a, int b)
{
    cout << a + b << endl;
    return a + b;
}

void timecost(int(*ptr)(int a, int b), int a, int b)
{
    DWORD start;
    DWORD end;
    start = GetTickCount();
    ptr(a,b);
    end = GetTickCount();
    cout << "time cost:" << end - start << endl;
}

//int main()
//{
//    timecost(add, 2, 3);
//    return 0;
//}
