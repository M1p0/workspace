#include "MString.h"
using namespace std;
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
    size_t nSize = mark.size();
    while (1)
    {
        size_t pos = 0;
        pos = s.find(mark, pos);
        if (pos == string::npos)
        {
            return;
        }
        s.erase(pos, nSize);
    }
}

int Mstrncpy(char *Dst, const char*Src, int Length)
{
    if (Dst==nullptr||Src==nullptr)
    {
        return -1;
    }
    else
    {
        return 0;
    }

}
