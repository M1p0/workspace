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
        cout << "¹¹ÔìA" << endl;
    }
    ~A()
    {
        cout << "Îö¹¹A" << endl;
    }

};


int main()
{
    MemPool pool;


    A *a = new(pool) A;
    Destroy(a, pool);
    cout << pool.Capacity() << endl;

    

}




