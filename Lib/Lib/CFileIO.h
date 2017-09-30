#pragma once
#include<iostream>
#include<cstdio>
#include <string>
using namespace std;

class CFileIO
{
public:
    string Read(string szPath, string szMode = "rb");
    void Write(string szPath, string szData, string szMode = "ab+");
};