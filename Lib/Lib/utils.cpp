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

