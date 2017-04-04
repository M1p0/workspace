#include <iostream>
#include <string>
using  namespace std;
void subchar(char *ch, int startpos, int len)
{
    for (; startpos <= len; startpos++)
        cout << ch[startpos];
    cout << endl;
}
int main()
{
    int startpos;
    unsigned int i = 0;
    int len = 0;
    char ch[50];
    cout << "请输入一段字符串" << endl;
    cin >> ch;

    for (i = 0; i < strlen(ch); i++)
    {
        if (ch[i] >= '0' && ch[i] <= '9')
        {
            len++;
            if (len == 1)
                startpos = i;
            if (len >= 2 && (ch[i + 1] < '0' || ch[i + 1] > '9'))
            {
                subchar(ch, startpos, i);
                len = 0;
                startpos = 0;
            }
        }
    }
    return 0;
}

