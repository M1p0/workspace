#include <iostream>
#include <windows.h>
#include <process.h>
using namespace std;


HANDLE Event_Finish;
HANDLE StopA;

unsigned __stdcall PrintA(void *pArgument)
{

    while (1)
    {

        if (WaitForSingleObject(StopA, 0) == WAIT_OBJECT_0 )
        {
            cout << "A stopped";
            SetEvent(Event_Finish);
            _endthreadex(0);
        }

        cout << "A" << endl;
    }
    _endthreadex(0);
    
}

unsigned __stdcall PrintB(void *pArgument)
{
    while (1)
    {

        cout << "B" << endl;
    }
    _endthreadex(0);
}


unsigned __stdcall Stop(void *pArgument)
{
    char ch;
    while (1)
    {
        if (ch = getchar() == '\n')
        {
            SetEvent(StopA);
        }
        break;
    }
    _endthreadex(0);
}



int main()
{
    Event_Finish = CreateEvent(NULL, TRUE, FALSE, FALSE);
    StopA = CreateEvent(NULL, TRUE, FALSE, FALSE);
    unsigned PRINT_1_ID, PRINT_2_ID;
    HANDLE PRO[2];
    HANDLE S;
    S = (HANDLE)_beginthreadex(NULL, 0, &Stop, NULL, 0, &PRINT_1_ID);
    PRO[0] = (HANDLE)_beginthreadex(NULL, 0, &PrintA, NULL, 0, &PRINT_1_ID);
    PRO[1] = (HANDLE)_beginthreadex(NULL, 0, &PrintB, NULL, 0, &PRINT_2_ID);
    WaitForSingleObject(Event_Finish, INFINITE);
}