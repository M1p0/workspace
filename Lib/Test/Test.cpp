#include <iostream>
#include <windows.h>
#include <BitMap.h>
#include <MemPool.h>
using namespace std;


class A
{
public:
    A()
    {
        cout << "����A" << endl;
    }
    ~A()
    {
        cout << "����A" << endl;
    }

};


int main()
{
    MemPool pool;


    A *a = new(pool) A;
    Destroy(a, pool);
    cout << pool.Capacity() << endl;

    

}




