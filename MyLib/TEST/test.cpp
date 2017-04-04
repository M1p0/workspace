#include <process.h> 
#include <windows.h>
#include <iostream>
#include <string>
#include "list.h"
using namespace std;

#pragma warning(disable : 4102)

unsigned Counter=0;
unsigned CounterA = 0;
unsigned CounterB = 0;
//CRITICAL_SECTION g_cs;
Link Odd;
Link Even;
Link Number;


// ---------------------------------------------------------
unsigned __stdcall ProducerA(void *pArguments)
{
    cout << "Producer A is running " << endl;

    for (;;)
    {
        // 生产过程
        Sleep(1000);
        // 临界区保护，放入产品
        //KG_Guard guard(&g_mt);
         Number.Insert(CounterA++);
    }

    return 0;
}

unsigned __stdcall ProducerB(void *pArguments)
{
    cout << "Producer B is running " << endl;

    for (;;)
    {
        // 生产过程
        Sleep(1000);

        // 临界区保护，放入产品
        Number.Insert1(CounterB++);
    }

    return 0;
}

unsigned __stdcall CustomerA(void *pArguments)
{
    cout << "CustomerA is running " << endl;
    while (Counter <= 100)
    {
        if (Counter % 2 != 0)
        {
            Even.Insert(Counter);
        }
    }
    _endthreadex(0);
    return 0;
}

unsigned __stdcall CustomerB(void *pArguments)
{
    cout << "CustomerB is running " << endl;
    while (Counter <= 100)
    {
        if (Counter % 2 != 0)
        {
            Even.Insert(Counter);
        }
    }
    _endthreadex(0);
    return 0;
}



class Test : public KG_UnCopyable
{
};

class A
{
public:
    A() { cout << "A::A()" << endl; }
    ~A() { cout << "A::~A()" << endl; }
};

class B : public A
{
public:
    B() { cout << "B::B()" << endl; }
    ~B() { cout << "B::~B()" << endl; }
};

//int main()
//{
//    B b;
//    //HANDLE Producer[2];
//    //HANDLE Customer[2];
//    //unsigned ProducerA_ID, ProducerB_ID,CustomerA_ID,CustomerB_ID;
//    //Producer[0] = (HANDLE)_beginthreadex(NULL, 0, &ProducerA, NULL, 0, NULL);
//    //Producer[1] = (HANDLE)_beginthreadex(NULL, 0, &ProducerB, NULL, 0, NULL);
//    ////Customer[0] = (HANDLE)_beginthreadex(NULL, 0, &CustomerA, NULL, 0, NULL);
//    ////Customer[1] = (HANDLE)_beginthreadex(NULL, 0, &CustomerB, NULL, 0, NULL);
//
//    //getchar();
//    //Number.Output();
//    ////Odd.Output();
//    ////Even.Output();
//    //CloseHandle(Producer[0]);
//    //CloseHandle(Producer[1]);
//    ////CloseHandle(Customer);
//
//    //getchar();
//}



