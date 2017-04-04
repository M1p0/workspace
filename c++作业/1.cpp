#include <iostream>
using namespace std;
int main()
{
    int i = 0, j = 0, k = 0;
    for (i = 1; i <= 5; i++)
    {
        for (k = i; k < 5; k++)
        {
            cout << " ";
        }
        for (j = 1; j <= 2 * i - 1; j++)
        {

            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}
