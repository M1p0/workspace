#include "Sort.h"
#include<iostream>
#include <string>
using namespace std;
int Bubble_Sort(int str[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (str[i] > str[j])
            {
                int temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    } 
    return 0;
}