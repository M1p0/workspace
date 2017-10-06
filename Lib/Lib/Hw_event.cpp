#include <iostream>
#include <windows.h>
#include <string>
#include "Hw_event.h"
using namespace std;

void SetMouse(Pos pos)
{
    SetCursorPos(pos.x, pos.y);
}

void SetMouse(int x, int y)
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

void move(Pos start, Pos end)
{
    int xstep = end.x - start.x;
    int ystep = end.y - start.y;
    int step = xstep < ystep ? xstep : ystep;

}