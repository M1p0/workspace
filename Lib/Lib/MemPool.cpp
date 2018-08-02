#include "MemPool.h"
#include <iostream>
using namespace std;







MemPool::MemPool()
{
    uBlockSize = 4 * 1024;
}

MemPool::~MemPool()
{
}


void * MemPool::Allocate(size_t uSize)
{
    void *pRtn = nullptr;
    bool bAllocated = false;
    list<Buffer>::iterator it;

    if (uSize <= 0)
    {
        pRtn = nullptr;
        bAllocated = true;
    }
    else
    {
        for (it = BufferList.begin(); it != BufferList.end(); it++)
        {
            if (it->uBufferSize >= uSize && it->bUsed == false)
            {
                it->bUsed = true;
                bAllocated = true;
                pRtn = it->pBufferAddress;
            }
            else
            {
                //do nothing
            }
        }
        if (bAllocated == false)
        {
            Buffer buff;
            size_t uAllocSize=0;
            if (uSize%uBlockSize != 0)
            {
                uAllocSize = (uSize / uBlockSize + 1)*uBlockSize;
            }
            else
            {
                uAllocSize = (uSize / uBlockSize)*uBlockSize;
            }
            buff.bUsed = true;
            buff.uBufferSize = uAllocSize;
            pRtn = new char[uAllocSize];
            memset(pRtn, 0, uAllocSize);
            buff.pBufferAddress = pRtn;
            bAllocated = true;
            BufferList.push_back(buff);
        }
        else
        {

        }
    }

    return pRtn;
}


void MemPool::Deallocate(void *p)
{

        list<Buffer>::iterator it;
        for (it = BufferList.begin(); it != BufferList.end(); it++)
        {
            if (it->pBufferAddress == p)
            {
                it->bUsed = false;
                memset(it->pBufferAddress, 0, it->uBufferSize);
            }
        }
}

void MemPool::SetBlockSize(size_t uSize)
{
    this->uBlockSize = uSize;
}

size_t MemPool::Capacity()
{
    size_t uCapacity = 0;
    list<Buffer>::iterator it;
    for (it=BufferList.begin();it!=BufferList.end();it++)
    {
        uCapacity += it->uBufferSize;
    }
    return uCapacity;
}