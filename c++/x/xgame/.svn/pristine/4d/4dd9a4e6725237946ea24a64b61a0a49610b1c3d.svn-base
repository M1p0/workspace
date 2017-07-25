#include <stdio.h>
#include <stdlib.h>

#include "xzero.h"
#include "xbuff.h"
#include "xnet.h"

//class A
//{
//public:
//    int f(int i)
//    {
//        printf("A::f() i = %d", i);
//        return 1;
//    }
//};
//
//class B
//{
//public:
//    virtual int f(int i)
//    {
//        printf("B::f() i = %d", i);
//        return 1;
//    }
//};
//
//class C : public B
//{
//public:
//    virtual int f(int i)
//    {
//        printf("C::f() i = %d", i);
//        return 1;
//    }
//};
//
//int f(int i)
//{
//    printf("G::f() i = %d", i);
//    return 1;
//}
//
//int main()
//{
//    xzero::KG_Delegate<int, int> d;
//    A a;
//    B b;
//    C c;
//
//    d += new xzero::KG_Function<A, int, int>(&a, &A::f);
//    d += new xzero::KG_Function<B, int, int>(&b, &B::f);
//    d += new xzero::KG_Function<B, int, int>(&c, &B::f); // ∂‡Ã¨
//    d += new xzero::KG_Function<void, int, int>(&f);
//
//    d(1);
//    return 0;
//}

class A
{
public:
    int f()
    {
        printf("A::f()");
        return 1;
    }
};

class B
{
public:
    virtual int f()
    {
        printf("B::f()");
        return 1;
    }
};

class C : public B
{
public:
    virtual int f()
    {
        printf("C::f()");
        return 1;
    }
};

int f()
{
    printf("G::f()");
    return 1;
}

//int main()
//{
//    xzero::KG_GlobalMemLeakDetect det;
//
//    new int(1);
//
//    xzero::KG_Delegate<void, int> d;
//    A a;
//    B b;
//    C c;
//
//    d += new xzero::KG_Function<A, void, int>(&a, &A::f);
//    d += new xzero::KG_Function<B, void, int>(&b, &B::f);
//    d += new xzero::KG_Function<B, void, int>(&c, &B::f); // ∂‡Ã¨
//    d += new xzero::KG_Function<void, void, int>(&f);
//
//    d();
//    return 0;
//}

int main()
{
    xnet::KG_MultiClientServerProxy *pProxy = ::new xnet::KG_MultiClientServerProxy;
    pProxy->Init("", 8888);
    xnet::SPIKG_ServerProxy spProxy = xnet::SPIKG_ServerProxy(pProxy);

    for (;;)
    {
        spProxy->Activate();
    }

    return 0;
}