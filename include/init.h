#ifndef INIT_H
#define INIT_H

#include "raylib.h"
#include <stdlib.h>
#include <string>
#define BX 825
#define BY 650
#define XLEN 150
#define YLEN 75
#define BLOCK_INIT SKYBLUE
#define BLOCK_OWNED YELLOW
#define BLOCK_STRUCTED RED
#define totalrandnum 100
using namespace std;

extern Color bcolor;
extern int turn;
extern string message;
extern bool showmessage;
extern bool state;
//设计文字展示方式
void display(string showword);
//设计位置转换
Vector2 PositionTransfer(int i);
//以下四个为辅助作画函数

void DrawLineFloating(float x1, float y1, float x2, float y2);

void DrawLineFloatingthick(float x1, float y1, float x2, float y2);

void DrawBlockFloating(float x1, float y1, float x2, float y2);

void DrawBlockFloatingthick(float x1, float y1, float x2, float y2);
//游戏结束函数
void GameOver();

#endif