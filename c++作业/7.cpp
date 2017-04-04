#include <iostream>
using namespace std;
int main()
{
    float a, b, c;
    int i, n;
    a = 2.0;
    b = 1.0;
    c = a / b;
    cout << "请输入位数:";
    cin >> n;
    for (i = 2; i <= n; i++)
    {
        a = a + b;
        b = a - b;
        c = c + a / b;
    }
    cout << "结果为:" << c << endl;
}
