#include<iostream>
#include <string>
#include <typeinfo>
using namespace std;

class List
{
public:
    string name;
    int number;
    //List(int num = 100)
    //{
    //    number = num;
    //}
    //List(string str)
    //{
    //        number = 100;
    //}
    template <class T>
    List(T t)
    {
        number = 100;
    }
    void output()
    {
        cout << number << endl;
    }
};

int main()
{   
    string str;
    List A(str);
    A.output();
}
