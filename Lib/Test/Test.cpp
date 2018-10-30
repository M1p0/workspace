#include <string.h>
#include <iostream>
#include <Public.h>
#include <MemPool.h>
using namespace std;

//ÇÐ¸ÖÌõ
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
            q = MAX(q, Cut(p, n - i, r) + p[i]);
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




//ÕÒÓ²±Ò
const int N = 7;
int Count[N] = { 3,1,2,1,0,3,5 };
int Value[N] = { 1,2,5,10,20,50,100 };
vector<int> Res;

int solve(int money)
{
    int num = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        int c = MIN(money / Value[i], Count[i]);
        money = money - c * Value[i];
        num += c;
        if (c != 0)
        {
            for (int j = 0; j < c; j++)
            {
                Res.push_back(Value[i]);
            }
        }
    }
    if (money > 0)
    {
        num = -1;
    }
    return num;
}



//int main()
//{
//    int nArr[6][13] = { 0 };
//    int nCost[6] = { 0,2,5,3,10,4 };
//    int nVol[6] = { 0,1,3,2,6,2 };
//    int bagV = 12;
//    for (int i = 1; i < sizeof(nCost) / sizeof(int); i++)
//    {
//        for (int j = 1; j <= bagV; j++)
//        {
//            if (j < nVol[i])
//            {
//                nArr[i][j] = nArr[i - 1][j];
//            }
//            else
//            {
//                nArr[i][j] = MAX(nArr[i - 1][j], nArr[i - 1][j - nVol[i]] + nCost[i]);
//            }
//        }
//    }
//    cout << nArr[5][12] << endl;
//    return 0;
//}



class A
{
public:
    virtual void show() { cout << "A" << endl; }
protected:
private:
};


class B:public A
{
public:
    void show() { cout << "B" << endl; }
 

private:

};


int main()
{
    B b;
    A* a = new A();
    a->show();



}


