#include <string.h>
#include <iostream>
#include <Public.h>
#include <MemPool.h>
using namespace std;


int Cut(int *p, int n, int *r)
{
    int q = -1;
    if (r[n] >= 0)
    {
        return r[n];
    }
    if (n == 0)
    {
        q = 0;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            q = MAX(q,Cut(p, n - i, r)+ p[i]);
        }
    }
    r[n] = q;
    return q;
}


int MemoCut(int *p, int n)
{
    int *r = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        r[i] = -1;
    }

    return Cut(p, n, r);


}





int main()
{

    int p[11] = {0, 1,5,8,9,10,17,17,20,24,30 };

    cout << MemoCut(p, 7) << endl;
    
}