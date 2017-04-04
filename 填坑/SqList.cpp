#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
typedef int ElemType;
#define LIST_INIT_SIZE 100


struct node
{

};

struct SqList
{
    ElemType *elem;
    int length, listsize;
};

void InitList(SqList &L)
{
    L.elem = new ElemType[LIST_INIT_SIZE];
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
}

void InsertList(SqList &L,int i,ElemType data)
{

    L.elem[i] = data;
    L.length++;

}

int Delete(SqList &L, int x,int y)
{
    int i;
    for (i=0;i<=L.length;i++)
    {
        if (L.elem[i]>=x&&L.elem[i]<=y)
        {
            for (int j = i; j < L.length - 1; j++)
            {
                L.elem[j] = L.elem[j + 1];
            }
            L.length--;
            return Delete(L, x, y);
        }
    }
    return 1;
}

void Free(SqList &L)
{
    ElemType *p;
    for (int i=0;i<L.length;i++)
    {
        p = &L.elem[i];
        if (L.elem[i]==1)
        {
            delete p;
            p = NULL;
        }
    }
}

void printSqList(SqList &L)
{
    int i;
    for (i = 0; i < L.length; i++)
        cout << L.elem[i] << "\t";
}



void Sort(SqList &L)
{
    int len = L.length;
    int front = 0;
    int end = len - 1;
    while (front<end)
    {
        if (L.elem[front]%2!=0)  //奇数
        {
            front++;
            continue;
        }

        if (L.elem[end]%2==0)  //偶数
        {
            end--;
            continue;
        }

        int temp = L.elem[front];
        L.elem[front] = L.elem[end];
        L.elem[end] = temp;



    }
}


int main()
{
    int num;
    int x = 1, y = 3;
    ElemType data;
    SqList L;
    InitList(L);
    cout << "输入第一个表的长度" << endl;
    cin >> num;
    cout << "输入数据" << endl;
    for (int i=0;i<num;i++)
    {
        //cin >> data;
        InsertList(L, i, i);
        //InsertList(L, i, data);
    }
    printSqList(L);
}