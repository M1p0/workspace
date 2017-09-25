#pragma once
#include <iostream>
#include <string>
using namespace std;
void transfer(string &str, int mode); //mode function
                                      //1    toupper
                                      //2    tolower



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