#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char str[50];
    cin >> str;
    char *p1 = str, *p2 = str + strlen(str) - 1;
    for (; p1 < p2 && *p1 == *p2; ++p1, --p2);
    cout << (p1 < p2 ? "不是回文" : "是回文") << endl;
    return 0;
}