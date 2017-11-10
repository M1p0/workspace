#include "utils.h"

void transfer(string &str, int mode)
{
    if (mode == 1)
    {
        for (auto &c : str)
        {
            c = toupper(c);
        }
    }
    else if (mode == 2)
    {
        for (auto &c : str)
        {
            c = tolower(c);
        }
    }
}


void deleteAllMark(string &s, const string &mark)
{
    unsigned int nSize = mark.size();
    while (1)
    {
        unsigned int pos = 0;
        pos = s.find(mark, pos);
        if (pos == string::npos)
        {
            return;
        }
        s.erase(pos, nSize);
    }
}

int Program_Mutex()
{
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
}