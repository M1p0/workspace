#include<iostream>
using namespace std;

int main()
{
    int i, j;
    char a[40], b[40], c[80];
    cout << "input the first string:\n";
    cin >> a;
    cout << "input the second string:\n";
    cin >> b;
    for (i = 0; a[i] != '\0'; i++)
        c[i] = a[i];
    for (j = 0; b[j] != '\0'; j++)
        c[i + j] = b[j];
    c[i + j] = '\0';
    cout << c;
    return 0;
}