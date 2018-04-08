#include "MyEvent.h"
#include "Public.h"
#include <mutex>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
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
        MSleep(1, "ms");
    }
    mtx.unlock();
    return 0;
}