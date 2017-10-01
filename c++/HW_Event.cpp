#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
            //mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            //::SetCursorPos(41, 316);

struct Pos
{
	int x=0;
	int y=0;
}


void move(Pos start,Pos end)
{
	int xstep=end.x-start.x;
	int ystep=end.y-start.y;
	int step=xstep<ystep?xstep:ystep;

}