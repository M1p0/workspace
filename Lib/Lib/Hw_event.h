#pragma once


struct Pos
{
    int x = 0;
    int y = 0;
};

void SetMouse(Pos pos);
void SetMouse(int x,int y);
void LeftDown();
void LeftUp();
void RightDown();
void RightUp();
void LeftClick();
void RightClick();
void SetDelay(int time);

