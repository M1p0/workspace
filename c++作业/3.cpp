#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    cout << "请输入三个数" << endl;
    int a[3] = {0};
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    sort(a, a + 3);
    for (int i = 0; i < 3; i++)
        cout << a[i] << "  ";
}