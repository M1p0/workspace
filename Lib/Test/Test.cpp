#include <iostream>
#include "LinkList.h"
using namespace std;

int main()
{
    LinkList ListA;
    for (int i=0;i<5;i++)
    {
        ListA.Insert(i);
    }

    ListA.Output();
    ListA.Delete_Pos(5);
    ListA.Output();



    

}
