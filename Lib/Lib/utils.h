#pragma once
#include <iostream>
#include <string>
using namespace std;
void transfer(string &str, int mode); //mode function
                                      //1    toupper
                                      //2    tolower
template <class T>
T MIN(T num1, T num2)
{
    return num1 < num2 ? num1 : num2;
}

template <class T>
T MAX(T num1, T num2)
{
    return num1 > num2 ? num1 : num2;
}

template <class T>
int Match(T data, T array[], int length)   //string not included
{
    for (int i = 0; i < length; i++)
    {
        if (array[i] == data)
        {
            return 1;
        }
    }
    return 0;
};