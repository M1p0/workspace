#include "LinkList.h"

void LinkList::Insert(int value)
{
    node *newnode = new node;
    newnode->Data = value;
    newnode->Next = head;
    head = newnode;
}

void LinkList::Output()
{
    node *current = head;
    while (current != nullptr)
    {
        cout << current->Data << "\t";
        current = current->Next;
    }
    cout << endl;
}

int LinkList::Length()
{
    int length = 0;
    node *current = head;
    while (current != nullptr)
    {
        length++;
        current = current->Next;
    }
    return length;
}

void LinkList::Delete_Value(int value)
{

    node *p = head;
    node *t = new node;
    //node *next = new node;
    while (p->Next != nullptr)
    {
        if (p->Next->Data == value)
        {
            t = p->Next;
            p->Next = t->Next;
            delete t;
            t = nullptr;
        }
        else
            p = p->Next;
    }
}

void LinkList::Delete_Pos(int pos)
{
    node *p = head;
    node *Del = new node;
    node *next = new node;
    int counter = 1;
    while (counter != pos - 1)
    {
        counter++;
        p = p->Next;
    }
    Del = p->Next;
    next = Del->Next;  //未完成
    p->Next = next;
    delete Del;
    Del = nullptr;

}

void LinkList::Set_Loop(int start, int end)
{
    node *Loop_start = head;
    node *Loop_end = head;
    for (int i = 1; i < end; i++)
    {
        Loop_end = Loop_end->Next;
    }
    Loop_end->Next = Loop_start;
}

void LinkList::Check_Loop()
{

    node *fast = head;
    node *slow = head;

    while (1)
    {
        if (head == nullptr || head->Next == nullptr)//链表为空或者只有一个结点
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
            if (fast->Next == nullptr || slow->Next == nullptr)//Next==Null即slow或fast为最后一个结点 不可能成环
            {
                cout << "Not Loop!" << endl;
                break;
            }
        }
    }
}






