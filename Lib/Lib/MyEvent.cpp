#include "MyEvent.h"
#include <mutex>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) sleep(x)
#endif

int Mtx_Lock(std::mutex &mtx)
{
    mtx.lock();
    return 0;
}

int Mtx_Unlock(std::mutex &mtx)
{
    mtx.unlock();
    return 0;
}

int Mtx_Init(std::mutex &mtx,bool Value)
{
    if (Value==true)
        mtx.lock();
    else
        mtx.unlock();
    return 0;
   
}

int Mtx_Wait(std::mutex &mtx)
{
    while (mtx.try_lock() != 1)
    {
        Sleep(1);
    }
    mtx.unlock();
    return 0;
}