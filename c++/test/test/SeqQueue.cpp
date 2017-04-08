#include <iostream>
using namespace std;
#define ElemType int 
#define MAXSIZE 50

struct SeqQueue
{
    ElemType elem[10];
    int front;
    int rear;
};

void InitQueue(SeqQueue *Q)
{
    Q->front = Q->rear = 0;
}

int EnterQueue(SeqQueue *Q, ElemType x)
{
    if ((Q->rear+1)%MAXSIZE==Q->front)
    {
        return -1;        //尾指针+1追上头指针
    }
    Q->elem[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 0;

}


//
//int DeleteQueue(SeqQueue *Q, ElemType *x)
//{
//
//}




