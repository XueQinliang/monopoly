#ifndef DRAW_H
#define DRAW_H

#include "person.h"
using namespace std;
Vector2 PositionTransfer(int i);
void mapdrawblocks(Block blocksi[20]);
void mapdrawline();
void mapdrawdice(int value);
void mapdrawpeoplepicture(Person player[]);
void mapdrawpeoplecare();
void mapdrawpeople(Person player[]);
void mapdrawpeopleinfo();
void mapdrawblockinfo(int x, int y);
void mapdrawmessagegivemoney();
void mapdrawmessagehouse();
void mapdrawmessageblock();
void mapdrawturn();
void mapdrawtitle();
void DrawBlock(Block block, Vector2 position);
void mapdrawdisplay();
void mapdrawover(Color c = BLACK);
extern int choosebutton;
#endif