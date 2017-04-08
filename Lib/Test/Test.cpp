#include <iostream>
#include "LinkList.h"
using namespace std;

void Merge(Link &List1, Link &List2, Link &List3)
{
    int len1, len2;
    len1 = List1.Length();
    len2 = List2.Length();
    node *p, *t;
    p = List1.head;
    t = List2.head;

    for (; len1 > 0 && len2 > 0;)
    {
        if (p->Data < t->Data)
        {
            List3.Insert(p->Data);
            len1--; 
            p = p->Next;
        }
        else
        {
            List3.Insert(t->Data); 
            len2--;
            t = t->Next;
        }
        if (len1 == 0)
        {
            for (int i = 0; i < len2; i++)
            {
                List3.Insert(t->Data);
                t = t->Next;
            }
        }
        if (len2 == 0)
        {
            for (int i = 0; i < len1; i++)
            {
                List3.Insert(p->Data);
                p = p->Next;
            }
        }
    }
}




int main()
{
    Link ListA, ListB, ListC;
    ListA.Insert(1);
    ListA.Delete_Value(1);
    ListA.Output();


}
