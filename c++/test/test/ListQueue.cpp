#include <iostream>
using namespace std;
#define  ElemType int

struct Node 
{
    ElemType data;
    Node *next;
};

struct LinkQueue 
{
    Node *front;
    Node *rear;
};

int InitQueue(LinkQueue *Q)
{
    Q->front = new Node;
    if (Q->front != NULL)
    {
        Q->rear = Q->front;
        Q->front->next = NULL;
        return 0;
    }
    else
        return -1;
}

int EnterQueue(LinkQueue *Q,ElemType x)
{
    Node *newnode;
    newnode = new Node;
    if (newnode != NULL)
    {
        newnode->data = x;
        newnode->next = NULL;
        Q->rear->next = newnode;
        Q->rear = newnode;
        return 0;
    }
    else
        return -1;
}

int DeleteQueue(LinkQueue *Q,ElemType *x)
{
    Node *p;
    if (Q->front==Q->rear)
    {
        return -1;
    }
    p = Q->front->next;
    Q->front->next = p->next;
    if (Q->rear==p)
    {
        Q->rear = Q->front;
    }
    *x = p->data;
    delete p;
    p = NULL;
    return 0;
}

