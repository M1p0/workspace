#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float x, y, h;
    cout << "请输入坐标" << endl;
    cin >> x >> y;
    if (x >= 0 && y >= 0) {
        if (pow(x - 2, 2) + pow(y - 2, 2) <= 1)h = 4;
        else h = 0;
    }
    if (x >= 0 && y <= 0) {
        if (pow(x - 2, 2) + pow(y + 2, 2) <= 1)h = 7;
        else h = 0;
    }
    if (x <= 0 && y >= 0) {
        if (pow(x + 2, 2) + pow(y - 2, 2) <= 1)h = 10;
        else h = 0;
    }
    if (x <= 0 && y <= 0) {
        if (pow(x + 2, 2) + pow(y + 2, 2) <= 1)h = 18;
        else h = 0;
    }
    cout << "塔高为:" << h << endl;
    return 0;
}