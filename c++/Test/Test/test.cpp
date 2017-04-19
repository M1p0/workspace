#include <iostream>
#include <vector>
#define MAXLEN 40
using namespace std;

struct SString
{
    char ch[MAXLEN];
    int len = 0;
};


void Replace(SString *r,char ch1,char ch2)
{
    int len = r->len;
    for (int i=0;i<len;i++)
    {
        if (r->ch[i]==ch1)
        {
            r->ch[i] = ch2;
        }
    }
}


void Reverse(SString *r)
{
    int len = r->len;
    for (int i=0;i<len/2;i++)
    {
        char temp;
        temp = r->ch[i];
        r->ch[i] = r->ch[len - i];
        r->ch[len - i] = temp;
    }
}

void Delete(SString *r, char ch)
{
    int len = r->len;
    for (int i=0;i<len;i++)
    {
        if (r->ch[i]==ch)
        {
            for (int j=i;j<len-1;j++)
            {
                r->ch[j] = r->ch[j + 1];    //数组向前移 以替代ch
            }
            r->ch[len] = '\0';       //移动完成 将尾数删除
            len--;                  //变更长度
        }
    }
}


void RightShift(int* arr, int Length, int K)   //Length为数组长度 K为右移长度
{
    while (K--)
    {
        int t = arr[Length - 1];
        for (int i = Length - 1; i > 0; i--)
            arr[i] = arr[i - 1];
        arr[0] = t;
    }
}            //时间复杂度为O(N²)

int main()
{
    int a[5] = { 1,2,3,4,5 };
    RightShift(a, 5, 6);

    for (int i=0;i<5;i++)
    {
        cout << a[i] << endl;
    }

    
}