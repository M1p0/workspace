#include <iostream>
#include "LinkList.h"
using namespace std;


void Link::Insert(int value)
{
    node *newnode = new node;
    newnode->Data = value;
    newnode->Next = head;
    head = newnode;
}

void Link::Output()
{
    node *current = head;
    while (current != NULL)
    {
        cout << current->Data << "\t";
        current = current->Next;
    }
    cout << endl;
}
 
int Link::Length()
{
    int length = 0;
    node *current = head;
    while (current != NULL)
    {
        length++;
        current = current->Next;
    }
    return length;
}

void Link::Delete_Value(int value)
{

    node *p = head;
    node *t = new node;
    //node *next = new node;
    while (p->Next != NULL)
    {
        if (p->Next->Data == value)
        {
            t = p->Next;
            p->Next = t->Next;
            delete t;
            t = NULL;
        }
        else
            p = p->Next;
    }
}

void Link::Delete_Pos(int pos)
{
    node *p = head;
    node *t = new node;
    node *next = new node;

}

void Link::Set_Loop(int start, int end)
{
    node *Loop_start = head;
    node *Loop_end = head;
    for (int i = 1; i < end; i++)
    {
        Loop_end = Loop_end->Next;
    }
    Loop_end->Next = Loop_start;
}

void Link::Check_Loop()
{

    node *fast = head;
    node *slow = head;

    while (1)
    {
        if (head == NULL || head->Next == NULL)//链表为空或者只有一个结点
        {
            cout << "Not Loop!" << endl;
            break;
        }
        else
        {
            fast = fast->Next->Next;
            slow = slow->Next;
            if (fast == slow)//不同速度的指针相遇 说明链表成环
            {
                cout << "isLoop!" << endl;
                break;
            }
            if (fast->Next == NULL || slow->Next == NULL)//Next==Null即slow或fast为最后一个结点 不可能成环
            {
                cout << "Not Loop!" << endl;
                break;
            }
        }
    }
}






