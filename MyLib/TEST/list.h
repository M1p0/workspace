#include <iostream>
using namespace std;

// ---------------------------------------------------------
class KG_UnCopyable
{
protected:
    KG_UnCopyable() {}
    ~KG_UnCopyable() {}

private:
    KG_UnCopyable(const KG_UnCopyable &r);
    KG_UnCopyable &operator=(const KG_UnCopyable &r);
};

//template <class MutexType>
//class KG_Guard : private KG_UnCopyable
//{
//private:
//    MutexType *m_Mutex;
//
//public:
//    explicit KG_Guard(MutexType *mutex) : m_Mutex(mutex)
//    {
//        m_Mutex->Lock();
//    }
//
//    ~KG_Guard()
//    {
//        m_Mutex->UnLock();
//    }
//};


class KG_Mutex : private KG_UnCopyable
{
public:
    KG_Mutex();
    ~KG_Mutex();

public:
    int Lock();
    int UnLock();

private: // CRITICAL_SECTION can't be used outside in Windows.
    CRITICAL_SECTION m_Mutex;
};

inline KG_Mutex::KG_Mutex()
{
    ::InitializeCriticalSection(&m_Mutex);
}

inline KG_Mutex::~KG_Mutex()
{
    ::DeleteCriticalSection(&m_Mutex);
}

inline int KG_Mutex::Lock()
{
    int nResult = false;

    ::EnterCriticalSection(&m_Mutex);

    nResult = true;
Exit0:
    return nResult;
}

inline int KG_Mutex::UnLock()
{
    int nResult = false;

    ::LeaveCriticalSection(&m_Mutex);

    nResult = true;
Exit0:
    return nResult;
}

class KG_Guard : private KG_UnCopyable
{
private:
    KG_Mutex *m_Mutex;

public:
    explicit KG_Guard(KG_Mutex *mutex) : m_Mutex(mutex)
    {
        m_Mutex->Lock();
    }

    ~KG_Guard()
    {
        m_Mutex->UnLock();
    }
};



struct  node
{

    int Data;
    node *Next;
};

class Link
{
private:
    node *head;
    KG_Mutex mt;
public:
    Link() { head = NULL; }
    void Insert(int a);
    void Insert1(int a);
    void Output();
};

void Link::Insert(int data)
{
    mt.Lock();

    node *newnode = new node;
    newnode->Data = data;
    newnode->Next = head;
    head = newnode;

    mt.UnLock();
}

void Link::Insert1(int data)
{
    KG_Guard g(&mt);

    node *newnode = new node;
    newnode->Data = data;
    newnode->Next = head;
    head = newnode;

}

void Link::Output()
{
    //EnterCriticalSection(&g_cs);
    node *current = head;
    while (current != NULL)
    {
        cout << current->Data << "\t";
        current = current->Next;
    }
    //LeaveCriticalSection(&g_cs);
    cout << endl;
}
