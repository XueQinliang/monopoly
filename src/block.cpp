#include "../include/block.h"
void initblock(Block *block, bool house, string owner, int sizex, int sizey, int price, int rent, int housePrice, int houseRent)
{
    block->house = house; //是否有建筑物
    block->owner = owner; //所有者
    Vector2 v = {sizex, sizey};
    block->size = v; //大小

    block->price = price; //土地价钱
    block->rent = rent;   //土地租金

    block->housePrice = housePrice; //房子价钱
    block->houseRent = houseRent;   //房子租金
}
bool judgein(int position, int x, int y)
{
    Vector2 v = PositionTransfer(position);
    if (x > v.x && x < v.x + 100 && y > v.y && y < v.y + 100)
    {
        return true;
    }
    return false;
}