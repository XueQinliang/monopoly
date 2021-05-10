#ifndef BLOCK_H
#define BLOCK_H
#include "init.h"
using namespace std;

//Block定义
typedef struct Block
{
    bool house = 0;            //是否有建筑物
    string owner = "0";        //所有者
    Vector2 size = {100, 100}; //大小

    int price = 0; //土地价钱
    int rent = 0;  //土地租金

    int housePrice = 0; //房子价钱
    int houseRent = 0;  //房子租金
} Block;

void initblock(Block *block, bool house, string owner, int sizex, int sizey, int price, int rent, int housePrice, int houseRent);
bool judgein(int position, int x, int y);
/*void DrawBlock(Block block, Vector2 position); //画出图标

void DrawBlock(Block block, Vector2 position)
{
    BeginDrawing();
    ClearBackground(LIGHTGRAY);

    if (block.owner != 0)
    {
        DrawRectangleV(position, block.size, BLOCK_INIT);
    }
    else if (!block.house)
    {
        DrawRectangleV(position, block.size, BLOCK_OWNED);
    }
    else
    {
        DrawRectangleV(position, block.size, BLOCK_STRUCTED);
    }

    EndDrawing();
}*/

#endif