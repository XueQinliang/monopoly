#include "../include/raylib.h"
#include "../include/draw.h"
#include <time.h>
using namespace std;

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 750;
    int value = 1;
    int randnum = totalrandnum;
    bool randing = false;
    bool choose = false;
    srand(time(0));
    InitWindow(screenWidth, screenHeight, "Monopoly");
    InitAudioDevice();

    initmap(blocks);
    initplayer(player);

    //提供头像资源
    Music music = LoadMusicStream("resources/music.mp3");
    PlayMusicStream(music);
    Music dicering = LoadMusicStream("resources/dice.mp3");
    PlayMusicStream(dicering);
    //设置游戏帧率
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    //主游戏循环
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateMusicStream(music);
        //----------------------------------------------------------------------------------
        if (GetMouseX() > BX && GetMouseX() < BX + XLEN && GetMouseY() > BY && GetMouseY() < BY + YLEN && choose == false)
        {
            bcolor = BLUE;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && randing == false)
            {
                randing = true;
            }
        }
        else
        {
            bcolor = DARKBLUE;
        }
        if (IsKeyPressed(KEY_ENTER) || (IsKeyPressed(KEY_KP_ENTER)) && randing == false)
        {
            randing == true;
        }
        if (randing && randnum-- > 0)
        {
            UpdateMusicStream(dicering);
            if (randnum % 4 == 0)
                value = rand() % 6 + 1;
        }
        else
        {
            if (randnum <= 0)
            {
                int nowstep = value;
                move(player[turn], value);
                choose = true;
                //先交钱
                giveMoney(player[turn]);
            }
            randing = false;
            randnum = totalrandnum;
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(WHITE);

        mapdrawtitle();
        mapdrawdice(value);
        // DrawCircleV(ballPosition, 50, GOLD);
        mapdrawline();
        mapdrawpeoplepicture(player);
        mapdrawpeople(player);
        mapdrawpeopleinfo();
        mapdrawturn();
        mapdrawblockinfo(GetMouseX(), GetMouseY());
        if (!state)
        {
            Color cstart = WHITE;
            if (GetMouseX() > 450 && GetMouseX() < 550 && GetMouseY() > 460 && GetMouseY() < 490)
            {
                cstart = GOLD;
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    state = true;
                    choose = false;
                    showmessage = false;
                    initmap(blocks);
                    for (int i = 0; i < 4; i++)
                    {
                        player[i].position = 0;
                        player[i].money = 10000;
                    }
                }
            }
            mapdrawover(cstart);
        }
        else
        {
            if (choose && showmessage == false)
            {
                //画个弹框
                if (blocks[player[turn].position].house || (blocks[player[turn].position].owner != "0" && blocks[player[turn].position].owner != player[turn].name))
                {
                    mapdrawmessagegivemoney();
                    if (GetMouseX() > 360 && GetMouseX() < 460 && GetMouseY() > 400 && GetMouseY() < 420)
                    {
                        choosebutton = 0;
                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                        {
                            //showmessage = false;
                            choose = false;
                            choosebutton = -1;
                            turn = (turn + 1) % 4;
                        }
                    }
                    if (IsKeyPressed(KEY_A))
                    {
                        //showmessage = false;
                        choose = false;
                        choosebutton = -1;
                        turn = (turn + 1) % 4;
                    }
                }
                if (blocks[player[turn].position].owner == "0")
                {
                    mapdrawmessageblock();
                    if (GetMouseX() > 360 && GetMouseX() < 460 && GetMouseY() > 400 && GetMouseY() < 420)
                    {
                        choosebutton = 0;
                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                        {
                            bool suc = buyLand(player[turn]);
                            if (suc)
                                goto end;
                            else
                            {
                                choose = false;
                                choosebutton = -1;
                                turn = (turn + 1) % 4;
                                showmessage = true;
                                goto end;
                            }
                        }
                    }
                    if (GetMouseX() > 470 && GetMouseX() < 570 && GetMouseY() > 400 && GetMouseY() < 420)
                    {
                        choosebutton = 1;
                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                        {
                            choose = false;
                            choosebutton = -1;
                            turn = (turn + 1) % 4;
                        }
                    }
                    if (IsKeyPressed(KEY_A))
                    {
                        bool suc = buyLand(player[turn]);
                        if (suc)
                            goto end;
                        else
                        {
                            choose = false;
                            choosebutton = -1;
                            turn = (turn + 1) % 4;
                            showmessage = true;
                            goto end;
                        }
                    }
                    if (IsKeyPressed(KEY_B))
                    {
                        choose = false;
                        choosebutton = -1;
                        turn = (turn + 1) % 4;
                    }
                }
                if (blocks[player[turn].position].owner == player[turn].name && !blocks[player[turn].position].house)
                {
                    mapdrawmessagehouse();
                    if (GetMouseX() > 360 && GetMouseX() < 460 && GetMouseY() > 400 && GetMouseY() < 420)
                    {
                        choosebutton = 0;
                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                        {
                            bool suc = buyHouse(player[turn]);
                            choose = false;
                            choosebutton = -1;
                            turn = (turn + 1) % 4;
                            if (!suc)
                            {
                                showmessage = true;
                                goto end;
                            }
                        }
                    }
                    if (GetMouseX() > 470 && GetMouseX() < 570 && GetMouseY() > 400 && GetMouseY() < 420)
                    {
                        choosebutton = 1;
                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                        {
                            choose = false;
                            choosebutton = -1;
                            turn = (turn + 1) % 4;
                        }
                    }
                    if (IsKeyPressed(KEY_A))
                    {
                        bool suc = buyHouse(player[turn]);
                        choose = false;
                        choosebutton = -1;
                        turn = (turn + 1) % 4;
                        if (!suc)
                        {
                            showmessage = true;
                            goto end;
                        }
                    }
                    if (IsKeyPressed(KEY_B))
                    {
                        choose = false;
                        choosebutton = -1;
                        turn = (turn + 1) % 4;
                    }
                }

                // //判断选择
                // if (IsKeyPressed(KEY_A))
                // {
                //     buyHouse(player[turn]);
                //     choose = false;
                //     choosebutton = -1;
                //     turn = (turn + 1) % 4;
                // }
                // if (IsKeyPressed(KEY_B))
                // {
                //     buyLand(player[turn]);
                //     choose = false;
                //     choosebutton = -1;
                //     turn = (turn + 1) % 4;
                // }
                // if (IsKeyPressed(KEY_C))
                // {
                //     choose = false;
                //     choosebutton = -1;
                //     turn = (turn + 1) % 4;
                // }
                // if (GetMouseX() > 360 && GetMouseX() < 460 && GetMouseY() > 400 && GetMouseY() < 420)
                // {
                //     choosebutton = 0;
                //     if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                //     {
                //         buyHouse(player[turn]);
                //         choose = false;
                //         choosebutton = -1;
                //         turn = (turn + 1) % 4;
                //     }
                // }
                // if (GetMouseX() > 470 && GetMouseX() < 570 && GetMouseY() > 400 && GetMouseY() < 420)
                // {
                //     choosebutton = 1;
                //     if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                //     {
                //         buyLand(player[turn]);
                //         choose = false;
                //         choosebutton = -1;
                //         turn = (turn + 1) % 4;
                //     }
                // }
                // if (GetMouseX() > 580 && GetMouseX() < 680 && GetMouseY() > 400 && GetMouseY() < 420)
                // {
                //     choosebutton = 2;
                //     if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                //     {
                //         choose = false;
                //         choosebutton = -1;
                //         turn = (turn + 1) % 4;
                //     }
                // }
            }
            if (showmessage)
            {
                mapdrawdisplay();
                if (GetMouseX() > 360 && GetMouseX() < 460 && GetMouseY() > 400 && GetMouseY() < 420)
                {
                    choosebutton = 0;
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        //showmessage = false;
                        choosebutton = -1;
                        showmessage = false;
                    }
                }
                if (IsKeyPressed(KEY_A))
                {
                    //showmessage = false;
                    choosebutton = -1;
                    showmessage = false;
                }
            }
        }
    end:
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    for (int i = 0; i < 4; i++)
    {
        UnloadImage(player[i].pic);
        UnloadTexture(player[i].tex);
        UnloadTexture(player[i].maptex);
    }

    UnloadMusicStream(dicering);
    UnloadMusicStream(music);
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
// int main(void)
// {
//     // Initialization
//     //--------------------------------------------------------------------------------------
//     const int screenWidth = 1000;
//     const int screenHeight = 750;
//     Vector2 ballPosition = {(float)screenWidth / 2, (float)screenHeight / 2};
//     InitWindow(screenWidth, screenHeight, "raylib [textures] example - background scrolling");
//     Game g = init(screenWidth, screenHeight);

//     // NOTE: Be careful, background width must be equal or bigger than screen width
//     // if not, texture should be draw more than two times for scrolling effect

//     SetTargetFPS(60); // Set our game to run at 60 frames-per-second
//     //--------------------------------------------------------------------------------------

//     // Main game loop
//     while (!WindowShouldClose()) // Detect window close button or ESC key
//     {
//         // Update
//         //----------------------------------------------------------------------------------

//         //----------------------------------------------------------------------------------

//         // Draw
//         //----------------------------------------------------------------------------------
//         BeginDrawing();

//         ClearBackground(GetColor(0x052c46ff));

//         DrawText("Monopoly", 350, 25, 20, RAYWHITE); //650 100
//         DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);
//         DrawCircleV(ballPosition, 50, MAROON);

//         EndDrawing();
//         //----------------------------------------------------------------------------------
//     }

//     // De-Initialization
//     //--------------------------------------------------------------------------------------
//     CloseWindow(); // Close window and OpenGL context
//     //--------------------------------------------------------------------------------------

//     return 0;
// }