#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "map.h"

using namespace std;
//人定义
typedef struct Person
{
    string name;
    int money = 10000;
    int position = 0;
    Image pic;
    Texture2D tex;
    Texture2D maptex;
} Person;
extern Person player[4];
void initplayer(Person plist[]);
//行动
void move(Person &person, int step);
//交易
bool buyLand(Person &person);
bool buyHouse(Person &person);
//交钱
void giveMoney(Person &person);

#endif