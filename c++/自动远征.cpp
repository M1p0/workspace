#include <afx.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
//x2,y2为补给时选择舰队的坐标 x2,y2为补给舰队的坐标
//x3,y3为远征坐标  x4,y4为选择远征后选择舰队的坐标  z远征时间(适当延迟)
//x5,y5为选择海域坐标
//a,b分别为远征编号以及舰队编号
//Check1函数判断远征
//Check2函数判断舰队 并调整延迟时间

struct Map
{
    int x;
    int y;
};

string a, b, str;
int  x2, y2, x3, y3, x4, y4, x5, y5, z1,z2;
int Check1(string a);
int Check2(string b);
int Check3(string a);
void main()
{

    Map a[3][3] =
    {
        { {0,0},{0,1},{0,2} },
        { {1,1},{1,2},{1,3} },
        { {2,1},{2,2},{2,3} }
    };

    srand((unsigned)time(NULL));
    cout << "请输入远征编号如:1-1" << endl;
    cin >> a;
    cout << "请输入舰队编号如:2" << endl;
    cin >> b;
    Check1(a);
    Check2(b);
    Check3(a);
    cout << "下一次循环：" << z1 / 60000 << "分钟" << endl;
    cout << "设置延迟启动的时间:" << endl;
    cin >> z2;
    cout << "输入start以启动程序" << endl;
    cin >> str;
    if (str == "start")
    {
        cout << "程序将在" << z2 << "分钟后开始\n"
            << "请最小化控制台!" << endl;
        Sleep(z2*60000);
        for (int i = 0; i < 10000; i++)
        {
            Sleep(rand()%30000);//防封号 随机睡眠0-30s
            ::SetCursorPos(191, 534);//出击
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            ::SetCursorPos(41, 316);//母港
            Sleep(2000);
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            for (int j = 1; j <= 3; j++)//防止多个资源同时收到
            {
                Sleep(2000);
                ::SetCursorPos(417, 519);//收资源
                mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                Sleep(9000);
                mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                Sleep(3198);
                mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            }
            Sleep(60000);
            ::SetCursorPos(80, 499);//补给
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(3082);
            ::SetCursorPos(x2, y2);//补给时舰队的坐标
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(3401);
            ::SetCursorPos(118, 395);//补给舰队
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(5435);
            ::SetCursorPos(64, 340);
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(4853);
            ::SetCursorPos(203, 544);
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(2869);
            ::SetCursorPos(673, 512);
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(4000);
            ::SetCursorPos(x5, y5);//选择海域
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(3940);
            ::SetCursorPos(x3, y3);//选择远征的坐标
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(7490);
            ::SetCursorPos(681, 714);
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(2546);
            ::SetCursorPos(x4, y4);//选择远征后选择舰队的坐标
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(2052);
            ::SetCursorPos(615, 723);
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(5000);
            ::SetCursorPos(57, 323);//回到主界面
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            ::SetCursorPos(460, 517);
            Sleep(z1);
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        }
    }
    else
        cout << "error" << endl;

}
int Check1(string a)
{
    if (a == "1-3")
    {
        x3 = 488, y3 = 508;
        z1 = 1260000;
    }
    else if (a == "1-5")
    {
        x3 = 487, y3 = 569;
        z1 = 5460000;
    }
    return 0;
}
int Check2(string b)
{
    if (b == "2")
    {
        x2 = 177, y2 = 396;
        x4 = 393, y4 = 385;
    }
    else if (b == "3")
    {
        x2 = 208, y2 = 396;
        x4 = 425, y4 = 385;
    }
    return 0;
}
int Check3(string a)
{
    if (a[0] == '1')
    {
        x5 = 135, y5 = 713;
    }
    else if (a[0] == '2')
    {
        x5 = 194, y5 = 713;
    }
    else if (a[0] == '3')
    {
        x5 = 253, y5 = 713;
    }
    else if (a[0] == '4')
    {
        x5 = 307, y5 = 713;
    }
    else if (a[0] == '5')
    {
        x5 = 367, y5 = 713;
    }
    return 0;
}
https://www.ibm.com/developerworks/cn/linux/l-cn-socketftp/
