#include <iostream>
#include <cstdlib>
using namespace std;
void bubble(int str[], int len)
{
  int i, j, temp;
  for (i = 0; i <= len - 1; i++)
  {
    for (j = 0; j <= len - 1; j++)
    {
      if (str[j] > str[j + 1])
      {
        temp = str[j];
        str[j] = str[j + 1];
        str[j + 1] = temp;
      }
    }
  }
}

int main()
{
  int arr[10], len, i;
  for (i = 0; i < 10; i++)
    cin >> arr[i];
  len = sizeof(arr) / sizeof(arr[0]);
  bubble(arr, len);
  for (int i = 0; i <= 9; i++)
    cout << arr[i];
  return 0;

}