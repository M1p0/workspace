#include <iostream>
#include <windows.h>
#include <process.h>
using namespace std;


HANDLE Event_Finish;
HANDLE Input_Finish;
HANDLE Output_Finish;
int num;
unsigned __stdcall In(void *pArgument)
{
    while (1)
    {
        WaitForSingleObject(Output_Finish, INFINITE);
        cout << "ÊäÈë:";
        cin >> num;
        ResetEvent(Output_Finish);
        SetEvent(Input_Finish);
    }
    _endthreadex(0);
    return 0;
}

unsigned __stdcall Out(void *pArgument)
{ 
    while (1)
    {
        WaitForSingleObject(Input_Finish, INFINITE);
        cout << "Êä³ö:"<<num << endl;
        ResetEvent(Input_Finish);
        SetEvent(Output_Finish);
    }

    SetEvent(Event_Finish);
    _endthreadex(0);
    return 0;
}



int main()
{
    Input_Finish=CreateEvent(NULL, TRUE, FALSE, NULL);
    Output_Finish = CreateEvent(NULL, TRUE, TRUE, NULL);
    Event_Finish = CreateEvent(NULL, TRUE, FALSE, FALSE);
    unsigned PRINT_1_ID, PRINT_2_ID;
    HANDLE PRO[2];
    PRO[0]= (HANDLE)_beginthreadex(NULL, 0, &In, NULL, 0, &PRINT_1_ID);
    PRO[1] = (HANDLE)_beginthreadex(NULL, 0, &Out, NULL, 0, &PRINT_2_ID);
    WaitForSingleObject(Event_Finish, INFINITE);
}