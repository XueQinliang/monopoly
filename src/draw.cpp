#include "../include/draw.h"
#include "iostream"
//为地图画线
int offset[4][2] = {0, 0, 0, 1, 1, 0, 1, 1};
int choosebutton = -1;
void mapdrawline()
{
    for (int i = 0; i < 4; i++)
    {
        Rectangle pr = {25 + i * 200, 650, 75, 75};
        if (i == turn)
            DrawRectangleRoundedLines(pr, 0.2, 0, 4, RED);
        else
            DrawRectangleRoundedLines(pr, 0.2, 0, 4, LIGHTGRAY);

        DrawLineFloating(150, 225 + i * 100, 250, 225 + i * 100);
        DrawLineFloating(750, 225 + i * 100, 850, 225 + i * 100);
    }
    for (int i = 0; i < 6; i++)
    {
        DrawLineFloating(250 + i * 100, 125, 250 + i * 100, 225);
        DrawLineFloating(250 + i * 100, 525, 250 + i * 100, 625);
    }
    Rectangle dicer = {440, 315, 120, 120};
    DrawRectangleRoundedLines(dicer, 0.2, 0, 4, LIGHTGRAY);
    //DrawBlockFloatingthick(440, 315, 560, 435);
    DrawBlockFloating(150, 125, 850, 625);
    DrawBlockFloating(250, 225, 750, 525);
    Rectangle br = {BX, BY, XLEN, YLEN};
    DrawRectangleRounded(br, 0.2, 0, bcolor);
    DrawText("action", 855, 675, 30, WHITE); //650 100
}
void mapdrawpeopleinfo()
{
    for (int i = 0; i < 4; i++)
    {
        DrawText(player[i].name.c_str(), 110 + i * 200, 655, 20, BLACK);
        DrawText((string("$") + to_string(player[i].money)).c_str(), 110 + i * 200, 690, 20, BLACK);
    }
}
//画出地图里的格子
void mapdrawblocks(Block blocks[20])
{
    for (int i = 0; i < 20; i++)
    {
        DrawBlock(blocks[i], PositionTransfer(i));
    }
}
//画出骰子
void mapdrawdice(int value)
{

    int c1 = 450;
    int c2 = 325;
    if (value == 1)
    {
        Vector2 v = {50 + c1, 50 + c2};
        DrawCircleV(v, 20, RED);
    }
    else if (value == 2)
    {
        Vector2 v1 = {15 + c1, 15 + c2};
        Vector2 v2 = {85 + c1, 85 + c2};
        DrawCircleV(v1, 15, BLUE);
        DrawCircleV(v2, 15, BLUE);
    }
    else if (value == 3)
    {
        Vector2 v1 = {50 + c1, 50 + c2};
        Vector2 v2 = {15 + c1, 15 + c2};
        Vector2 v3 = {85 + c1, 85 + c2};
        DrawCircleV(v1, 15, BLUE);
        DrawCircleV(v2, 15, BLUE);
        DrawCircleV(v3, 15, BLUE);
    }
    else if (value == 4)
    {
        Vector2 v1 = {15 + c1, 15 + c2};
        Vector2 v2 = {85 + c1, 15 + c2};
        Vector2 v3 = {15 + c1, 85 + c2};
        Vector2 v4 = {85 + c1, 85 + c2};
        DrawCircleV(v1, 15, RED);
        DrawCircleV(v2, 15, RED);
        DrawCircleV(v3, 15, RED);
        DrawCircleV(v4, 15, RED);
    }
    else if (value == 5)
    {
        Vector2 v1 = {15 + c1, 15 + c2};
        Vector2 v2 = {85 + c1, 15 + c2};
        Vector2 v3 = {15 + c1, 85 + c2};
        Vector2 v4 = {85 + c1, 85 + c2};
        Vector2 v5 = {50 + c1, 50 + c2};
        DrawCircleV(v1, 15, BLUE);
        DrawCircleV(v2, 15, BLUE);
        DrawCircleV(v3, 15, BLUE);
        DrawCircleV(v4, 15, BLUE);
        DrawCircleV(v5, 15, BLUE);
    }
    else if (value == 6)
    {
        Vector2 v1 = {15 + c1, 15 + c2};
        Vector2 v2 = {15 + c1, 85 + c2};
        Vector2 v3 = {85 + c1, 15 + c2};
        Vector2 v4 = {85 + c1, 85 + c2};
        Vector2 v5 = {50 + c1, 15 + c2};
        Vector2 v6 = {50 + c1, 85 + c2};
        DrawCircleV(v1, 15, BLUE);
        DrawCircleV(v2, 15, BLUE);
        DrawCircleV(v3, 15, BLUE);
        DrawCircleV(v4, 15, BLUE);
        DrawCircleV(v5, 15, BLUE);
        DrawCircleV(v6, 15, BLUE);
    }
    else
    {
        display("程序错误");
    }
}
void mapdrawblockinfo(int x, int y)
{
    for (int i = 0; i < 20; i++)
    {
        if (!judgein(i, x, y))
        {
            continue;
        }
        Vector2 p = PositionTransfer(i);
        Vector2 newp;
        newp.x = p.x + 10;
        newp.y = p.y + 10;
        DrawText((string("Price: ") + to_string(blocks[i].price)).c_str(), newp.x, newp.y, 14, BLACK);
        DrawText((string("Rent: ") + to_string(blocks[i].rent)).c_str(), newp.x, newp.y + 16, 14, BLACK);
        DrawText((string("HousePrice: ") + to_string(blocks[i].housePrice)).c_str(), newp.x, newp.y + 32, 14, BLACK);
        DrawText((string("HouseRent: ") + to_string(blocks[i].houseRent)).c_str(), newp.x, newp.y + 48, 14, BLACK);
        if (blocks[i].owner == "0")
            DrawText(string("Onwer: None").c_str(), newp.x, newp.y + 64, 14, BLACK);
        else
            DrawText((string("Onwer: ") + blocks[i].owner).c_str(), newp.x, newp.y + 64, 14, BLACK);
        // if (i < 7){
        //     newp.x = p.x;
        //     newp.y =
        // }else if(i < 11){

        // }else if(i < 17){

        // }else if(i < 20){

        // }
    }
}
//画出头像
void mapdrawpeoplepicture(Person player[])
{
    for (int i = 0; i < 4; i++)
    {
        //ImageCrop(&p1, (Rectangle){25 + i * 200, 650, 100, 75}); // Crop an image piece

        //ImageDrawRectangle(&player[i].pic, 25 + i * 200, 650, 100, 75, WHITE);
        DrawTexture(player[i].tex, 25 + i * 200, 650, WHITE);
    }
}

void mapdrawpeople(Person player[])
{

    for (int i = 0; i < 4; i++)
    {
        Vector2 pv = PositionTransfer(player[i].position);
        DrawTexture(player[i].maptex, pv.x + 5 + 50 * offset[i][0], pv.y + 5 + 50 * offset[i][1], WHITE);
    }
}
void mapdrawmessageblock()
{
    DrawRectangle(325, 275, 350, 200, SKYBLUE);
    DrawText("Do you buy Block?", 360, 325, 20, BLACK);
    DrawText("A. Yes", 370, 400, 20, BLACK);
    DrawText("B. No", 480, 400, 20, BLACK);
    Color c[2];
    for (int i = 0; i < 2; i++)
    {
        if (i == choosebutton)
            c[i] = GOLD;
        else
            c[i] = WHITE;
    }
    DrawRectangleLines(360, 400, 100, 20, c[0]);
    DrawRectangleLines(470, 400, 100, 20, c[1]);
}
void mapdrawmessagehouse()
{
    DrawRectangle(325, 275, 350, 200, SKYBLUE);
    DrawText("Do you buy House?", 360, 325, 20, BLACK);
    DrawText("A. Yes", 370, 400, 20, BLACK);
    DrawText("B. No", 480, 400, 20, BLACK);
    Color c[2];
    for (int i = 0; i < 2; i++)
    {
        if (i == choosebutton)
            c[i] = GOLD;
        else
            c[i] = WHITE;
    }
    DrawRectangleLines(360, 400, 100, 20, c[0]);
    DrawRectangleLines(470, 400, 100, 20, c[1]);
}
void mapdrawmessagegivemoney()
{
    DrawRectangle(325, 275, 350, 200, SKYBLUE);
    DrawText("You are forced to give money!", 360, 325, 20, BLACK);
    DrawText("OK", 370, 400, 20, BLACK);
    Color c[1];
    for (int i = 0; i < 1; i++)
    {
        if (i == choosebutton)
            c[i] = GOLD;
        else
            c[i] = WHITE;
    }
    DrawRectangleLines(360, 400, 100, 20, c[0]);
}
void mapdrawturn()
{
    Vector2 pv = PositionTransfer(player[turn].position);
    Rectangle r = {pv.x + 5 + 50 * offset[turn][0], pv.y + 5 + 50 * offset[turn][1], 40, 40};
    DrawRectangleRoundedLines(r, 0.1, 0, 4, RED);
}
void mapdrawtitle() { DrawText("Monopoly", 350, 25, 65, DARKGRAY); }
//画一个格子
void DrawBlock(Block block, Vector2 position)
{
    BeginDrawing();
    ClearBackground(LIGHTGRAY);

    if (block.owner != "0")
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
}

void mapdrawdisplay()
{
    DrawRectangle(325, 275, 350, 200, SKYBLUE);
    DrawText(message.c_str(), 360, 325, 20, BLACK);
    DrawText("OK", 370, 400, 20, BLACK);
    Color c[1];
    for (int i = 0; i < 1; i++)
    {
        if (i == choosebutton)
            c[i] = GOLD;
        else
            c[i] = WHITE;
    }
    DrawRectangleLines(360, 400, 100, 20, c[0]);
}

void mapdrawover(Color c)
{
    DrawRectangle(325, 275, 350, 230, SKYBLUE);
    string name[4];
    int score[4];
    for (int i = 0; i < 4; i++)
    {
        name[i] = player[i].name;
        score[i] = player[i].money;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3 - i; j++)
        {
            if (score[j + 1] <= score[j])
            {
                int t = score[j];
                score[j] = score[j + 1];
                score[j + 1] = t;
                string temp = name[j];
                name[j] = name[j + 1];
                name[j + 1] = temp;
            }
        }
    }
    DrawText("Rankings", 450, 300, 20, BLACK);
    for (int i = 3; i >= 0; i--)
    {
        DrawText(name[i].c_str(), 430, 430 - i * 30, 20, BLACK);
        DrawText(to_string(score[i]).c_str(), 520, 430 - i * 30, 20, BLACK);
    }
    DrawRectangleLines(450, 460, 100, 30, c);
    DrawText("Restart", 460, 465, 20, BLACK);
}