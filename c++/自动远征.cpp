#include <afx.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
//x2,y2Ϊ����ʱѡ�񽢶ӵ����� x2,y2Ϊ�������ӵ�����
//x3,y3ΪԶ������  x4,y4Ϊѡ��Զ����ѡ�񽢶ӵ�����  zԶ��ʱ��(�ʵ��ӳ�)
//x5,y5Ϊѡ��������
//a,b�ֱ�ΪԶ������Լ����ӱ��
//Check1�����ж�Զ��
//Check2�����жϽ��� �������ӳ�ʱ��

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
    cout << "������Զ�������:1-1" << endl;
    cin >> a;
    cout << "�����뽢�ӱ����:2" << endl;
    cin >> b;
    Check1(a);
    Check2(b);
    Check3(a);
    cout << "��һ��ѭ����" << z1 / 60000 << "����" << endl;
    cout << "�����ӳ�������ʱ��:" << endl;
    cin >> z2;
    cout << "����start����������" << endl;
    cin >> str;
    if (str == "start")
    {
        cout << "������" << z2 << "���Ӻ�ʼ\n"
            << "����С������̨!" << endl;
        Sleep(z2*60000);
        for (int i = 0; i < 10000; i++)
        {
            Sleep(rand()%30000);//����� ���˯��0-30s
            ::SetCursorPos(191, 534);//����
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            ::SetCursorPos(41, 316);//ĸ��
            Sleep(2000);
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            for (int j = 1; j <= 3; j++)//��ֹ�����Դͬʱ�յ�
            {
                Sleep(2000);
                ::SetCursorPos(417, 519);//����Դ
                mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                Sleep(9000);
                mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                Sleep(3198);
                mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            }
            Sleep(60000);
            ::SetCursorPos(80, 499);//����
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(3082);
            ::SetCursorPos(x2, y2);//����ʱ���ӵ�����
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(3401);
            ::SetCursorPos(118, 395);//��������
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
            ::SetCursorPos(x5, y5);//ѡ����
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(3940);
            ::SetCursorPos(x3, y3);//ѡ��Զ��������
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(7490);
            ::SetCursorPos(681, 714);
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(2546);
            ::SetCursorPos(x4, y4);//ѡ��Զ����ѡ�񽢶ӵ�����
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(2052);
            ::SetCursorPos(615, 723);
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(5000);
            ::SetCursorPos(57, 323);//�ص�������
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
