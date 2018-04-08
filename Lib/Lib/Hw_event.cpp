#include "Hw_event.h"
#include "Public.h"
using namespace std;




void SetMouse(POINT pos)
{
    SetCursorPos(pos.x, pos.y);
}

void SetMouse(long x, long y)
{
    SetCursorPos(x, y);
}

void LeftDown()
{
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
}

void LeftUp()
{
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}


void RightDown()
{
    mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
}

void RightUp()
{
    mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
}


void LeftClick()
{
    mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void RightClick()
{
    mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
}


void SetDelay(int time)
{
    Sleep(time);
}

void Mouse_MoveTo(POINT start, POINT end)
{
    POINT point1, point2, temp;
    long x, y;
    point1 = start;
    temp = point1;
    point2 = end;
    SetMouse(point1);
    if (point1.x == point2.x)
    {
        x = point1.x;
        for (int i = MIN(point1.y, point2.y); i <= MAX(point1.y, point2.y); i++)
        {
            y = temp.y;
            if (point1.y < point2.y)
            {
                temp.y++;
            }
            else
            {
                temp.y--;
            }
            SetMouse(x, y);
            Sleep(100);
        }
    }

    else if (point1.y == point2.y)
    {
        y = point1.y;
        for (int i = MIN(point1.x, point2.x); i <= MAX(point1.x, point2.x); i++)
        {
            x = temp.x;
            if (point1.x < point2.x)
            {
                temp.x++;
            }
            else
            {
                temp.x--;
            }
            SetMouse(x, y);
            Sleep(100);
        }
    }

    else
    {
        for (int i = MIN(point1.x, point2.x); i <= MAX(point1.x, point2.x); i++)
        {
            x = temp.x;
            y = (x - point1.x)*(point2.y - point1.y) / (point2.x - point1.x) + point1.y;
            if (point1.x < point2.x)
            {
                temp.x++;
            }
            else
            {
                temp.x--;
            }
            SetMouse(x, y);
            Sleep(1);
        }
    }

}

void Drag(POINT start, POINT end)
{
    SetMouse(start);
    LeftDown();
    Mouse_MoveTo(start, end);
    LeftUp();
}
