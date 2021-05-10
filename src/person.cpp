#include "../include/person.h"
#include <iostream>

Person player[4];
void initplayer(Person plist[])
{
    plist[0].name = "PlayerA";
    plist[0].pic = LoadImage("resources/p1.png");
    plist[1].name = "PlayerB";
    plist[1].pic = LoadImage("resources/p2.png");
    plist[2].name = "PlayerC";
    plist[2].pic = LoadImage("resources/p3.png");
    plist[3].name = "PlayerD";
    plist[3].pic = LoadImage("resources/p4.png");
    for (int i = 0; i < 4; i++)
    {
        ImageFlipHorizontal(&(plist[i].pic)); // Flip cropped image horizontally
        ImageResize(&(plist[i].pic), 75, 75); // Resize flipped-cropped image
        plist[i].tex = LoadTextureFromImage(plist[i].pic);
        ImageFlipHorizontal(&plist[i].pic); // Flip cropped image horizontally
        ImageResize(&plist[i].pic, 40, 40); // Resize flipped-cropped image
        plist[i].maptex = LoadTextureFromImage(plist[i].pic);
    }
}

//人的运动函数
void move(Person &person, int step)
{
    person.position = (person.position + step) % 20;
}
//人的购买土地函数
bool buyLand(Person &person)
{
    int index = person.position;
    if (person.money >= blocks[index].price)
    {
        person.money -= blocks[index].price;
        blocks[index].owner = person.name;
        return true;
    }
    else
    {
        display("Money not cover!");
        return false;
    }
    std::cout << "end buyland!" << std::endl;
}
//人的购买房屋函数
bool buyHouse(Person &person)
{
    int index = person.position;
    if (person.name == blocks[index].owner && (!blocks[index].house))
    {
        if (person.money >= blocks[index].housePrice)
        {
            person.money -= blocks[index].housePrice;
            blocks[index].house = true;
            return true;
        }
        else
        {
            display("Money not cover!");
            return false;
        }
    }
    else
    {
        display("Can't deal!");
        return false;
    }
    std::cout << "end buyhouse!" << std::endl;
}
//人的给钱函数
void giveMoney(Person &person)
{
    int index = person.position;
    int number = 0;
    if (blocks[index].owner == person.name)
    {
        return;
    }
    if (blocks[index].house) //双份租金
    {
        int initmoney = person.money;
        person.money = person.money - blocks[index].rent - blocks[index].houseRent;
        if (person.money < 0)
        {
            person.money = 0;
            for (int i = 0; i < 4; i++)
            {
                if (player[i].name == blocks[index].owner)
                {
                    number = i;
                    break;
                }
            }
            player[number].money = player[number].money + initmoney;
            display("You Lose!");
            GameOver();
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            if (player[i].name == blocks[index].owner)
            {
                number = i;
                break;
            }
        }
        player[number].money = player[number].money + blocks[index].rent + blocks[index].houseRent;
    }
    else if (blocks[index].owner != "0") //单份租金
    {
        person.money -= blocks[index].rent;
        if (person.money < 0)
        {
            display("Game Over!");
            GameOver();
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            if (player[i].name == blocks[index].owner)
            {
                number = i;
                break;
            }
        }
        player[number].money += blocks[index].rent;
    }
}