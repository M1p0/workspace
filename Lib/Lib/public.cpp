#include "Public.h"
using namespace std;

int Program_Mutex()
{
#ifdef _WIN32
    HANDLE hMutex = NULL;
    LPCTSTR lpszName = "APPMutex";
    int nRet;

    hMutex = ::CreateMutex(NULL, FALSE, lpszName);
    DWORD dwRet = ::GetLastError();

    switch (dwRet)
    {

    case 0:
    {
        nRet = 0;
        break;
    }

    case ERROR_ALREADY_EXISTS:
    {
        nRet = 1;   //program is already running
        break;
    }

    default:
    {
        nRet = -1; //create mutex failed
        break;
    }
    }
    return nRet;
#endif // _WIN32
}


