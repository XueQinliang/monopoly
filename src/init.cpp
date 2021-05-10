#include "../include/init.h"

int turn = 0;
Color bcolor = BLUE;
string message;
bool showmessage = false;
bool state = true;
void display(string showword)
{
    message = showword;
    showmessage = true;
}

Vector2 PositionTransfer(int i)
{
    Vector2 position;
    int t = i % 20;
    if (t < 7)
    {
        position = {(float)(150 + 100 * i), 125};
    }
    else if (t < 11)
    {
        position = {750, (float)(125 + (t - 6) * 100)};
    }
    else if (t < 17)
    {
        position = {(float)(750 - (t - 10) * 100), 525};
    }
    else if (t < 20)
    {
        position = {150, (float)(525 - (t - 16) * 100)};
    }
    return position;
}

//以下四个为辅助作画函数

void DrawLineFloating(float x1, float y1, float x2, float y2)
{
    Vector2 p1 = {x1, y1};
    Vector2 p2 = {x2, y2};
    DrawLineV(p1, p2, LIGHTGRAY);
}
void DrawLineFloatingthick(float x1, float y1, float x2, float y2)
{
    Vector2 p1 = {x1, y1};
    Vector2 p2 = {x2, y2};
    DrawLineEx(p1, p2, 5, LIGHTGRAY);
}
void DrawBlockFloating(float x1, float y1, float x2, float y2)
{
    DrawLineFloating(x1, y1, x2, y1);
    DrawLineFloating(x1, y2, x2, y2);
    DrawLineFloating(x1, y1, x1, y2);
    DrawLineFloating(x2, y1, x2, y2);
}
void DrawBlockFloatingthick(float x1, float y1, float x2, float y2)
{
    DrawLineFloatingthick(x1, y1, x2, y1);
    DrawLineFloatingthick(x1, y2, x2, y2);
    DrawLineFloatingthick(x1, y1, x1, y2);
    DrawLineFloatingthick(x2, y1, x2, y2);
}
//游戏结束函数
void GameOver()
{
    //待补充
    state = false;
}