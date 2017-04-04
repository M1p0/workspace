#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int i = 0, j = 0, k = 0;

    for (i = 2; abs(i) <= 2; i--)
    {
        for (k = 1; k <= abs(i); k++)
        {
            cout << " ";
        }

        for (j = 0; j < 5 - 2 * abs(i); j++)
        {

            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}