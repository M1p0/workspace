#include <iostream>
using namespace std;
#define ElemType int
#define MAXSIZE 3



struct SeqQueue
{
    ElemType elem[MAXSIZE];
    int front;
    int rear;
    int tag;
};

void InitQueue(SeqQueue *Q)
{
    Q->front = Q->rear = 0;
    Q->tag = 0;
}


int EnterQueue(SeqQueue *Q, ElemType x)
{
    if (Q->front == Q->rear && Q->tag == 1)
        return -1;
    if (Q->front == Q->rear  &&  Q->tag == 0)
        Q->tag = 1;
    Q->elem[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 0;
}

int DeleteQueue(SeqQueue *Q , ElemType *x)
{
    if (Q->front == Q->rear && Q->tag == 0)
        return -1;
    *x = Q->elem[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    if (Q->front == Q->rear)
        Q->tag = 0;
    return 0;
}

void main()
{
    int x;
    SeqQueue L;
    InitQueue(&L);
    EnterQueue(&L, 2);
    EnterQueue(&L, 3);
    EnterQueue(&L, 4);
    EnterQueue(&L, 5);
    EnterQueue(&L, 6);
    DeleteQueue(&L, &x);
    DeleteQueue(&L, &x);
    EnterQueue(&L, 7);
    EnterQueue(&L, 7);
    EnterQueue(&L, 7);


}