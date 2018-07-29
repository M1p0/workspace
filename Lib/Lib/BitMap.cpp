#include "BitMap.h"
#include <iostream>
#include <bitset>
using namespace std;


BitMap::BitMap()
{
    this->uSize = 0;
    this->uCapacity = 1024;
    Data = new unsigned int[uCapacity];
    memset(Data, 0, uCapacity * 4);
}

BitMap::BitMap(unsigned int size)
{
    this->uSize = 0;
    if (size <= 0)
    {
        cout << "BitMap:wrong size." << endl;
    }
    else
    {
        if (size % 32 != 0)
        {
            this->uCapacity = size / 32 + 1;
            Data = new unsigned int[uCapacity];
            memset(Data, 0, uCapacity * 4);
        }
        else
        {
            this->uCapacity = size / 32;
            Data = new unsigned int[uCapacity];
            memset(Data, 0, uCapacity * 4);
        }
    }
}

BitMap::~BitMap()
{
}

unsigned int BitMap::Capacity()
{
    return uCapacity * 32;
}

unsigned int BitMap::Size()
{
    return uSize;
}

int BitMap::Insert(unsigned int val)
{
    if (Exist(val))
    {
        cout << "BitMap:already have this element." << endl;
        return -1;
    }
    else
    {
        if (val >= this->Capacity())
        {
            cout << "BitMap:out of bound." << endl;
            return -1;
        }
        else
        {
            val = val + 1;
            int pos = 0;
            if (val % 32 == 0)
            {
                pos = val / 32 - 1; //数组从0开始
            }
            else
            {
                pos = val / 32;
            }
            Data[pos] = Data[pos] | (1 << ((val % 32) - 1));   //置1:data=data|(1<<(pos-1))
            uSize++;
            return 0;
        }
    }
}

bool BitMap::Exist(unsigned int val)
{

    if (val >= this->Capacity())
    {
        cout << "BitMap:out of bound." << endl;
        return false;
    }
    else
    {
        val = val + 1;
        int pos = 0;
        if (val % 32 == 0)
        {
            pos = val / 32 - 1;   //数组从0开始
        }
        else
        {
            pos = val / 32;
        }

        if ((Data[pos] & (1 << ((val % 32) - 1))) != 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}

int BitMap::operator[](unsigned int pos)
{
    if (pos % 32 == 0)
    {
        return (Data[pos / 32] & (1 << pos)) / pow(2, pos);
    }
    else
    {
        return (Data[pos / 32 + 1] & (1 << pos)) / pow(2, pos);
    }
}
