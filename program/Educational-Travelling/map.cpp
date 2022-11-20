#include "raylib.h"
#include "map.h"
#include "quests.h"
#include "checkpoints.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct COUNTRY_DATA {
    string code;
    int rectCount;
    int (*quest)();
};

Rectangle convertStringToRect(string str)
{
    float arr[4];
    for (size_t i = 0; i < 4; i++)
    {
        arr[i] = stof(str.substr(0, str.find(' ')));
        str.erase(0, str.find(" ") + 1);
    }
    return Rectangle{ arr[0], arr[1], arr[2], arr[3] };
}

int drawEndScreen()
{
    Texture2D endscreen = LoadTexture("../assets/menus/endscreen.png");

    endscreen.height *= 1.21;
    endscreen.width *= 1.21;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground({ 124, 164, 200 });
        DrawTexture(endscreen, 0, (SCREEN_HEIGHT - endscreen.height) / 2, WHITE);
        EndDrawing();
    }
    return 1;
}

int drawMap()
{
    SetMouseCursor(0);

    SetTargetFPS(60);

    COUNTRY_DATA countries[8] = { {"rs", 57, serbiaQuest}, {"bg", 28, bulgariaQuest},
                                  {"ro", 64, romaniaQuest}, {"hu", 40, hungaryCheckpoint},
                                  {"tr", 25, turkeyQuest}, {"gr", 60, greeceQuest},
                                  {"al", 27, albaniaQuest}, {"md", 36, moldovaCheckpoint} };

    Texture2D mapFrames[4] = { LoadTexture("../assets/maps/frame_1.png"), LoadTexture("../assets/maps/frame_2.png"),
                               LoadTexture("../assets/maps/frame_3.png"), LoadTexture("../assets/maps/frame_4.png") };

    for (int i = 0; i < 4; i++)
    {
        mapFrames[i].height *= 1.5;
        mapFrames[i].width *= 1.5;
    }

    Font font = LoadFont("../assets/fonts/CONSOLA.ttf");

    fstream mask;
    fstream progress;

    string visited;

    progress.open("../assets/data/progress.txt", ios::in);
   
    if (progress.is_open())
        getline(progress, visited);

    if (visited == "00111101")
    {
        if (drawEndScreen() == 1)
            return 1;
    }

    int frameCounter = 0;
    float timer = 0.0f;

    bool breakInner = 0;
    bool breakOuter = 0;

    while (!WindowShouldClose())
    {
        bool hover = 0;
        Vector2 mouse = GetMousePosition();

        timer += GetFrameTime();

        if (timer >= 0.3f)
        {
            timer = 0.0f;
            frameCounter += 1;
        }

        frameCounter = frameCounter % 3;

        for (int i = 0; i < 8; i++)
        {
            mask.open("../assets/data/country masks/" + countries[i].code + "_mask.txt", ios::in);

            if (mask.is_open())
            {
                for (int j = 1; j < countries[i].rectCount + 1; j++)
                {
                    string rectStr;
                    getline(mask, rectStr);
                    if (CheckCollisionPointRec(mouse, convertStringToRect(rectStr)) and visited[i] == '0')
                    {
                        hover = 1;
                        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                        {
                            if (countries[i].quest() == 1)
                            {
                                breakInner = 1;
                            }
                        }   
                        break;
                    }
                }
            }
            mask.close();
            if (breakInner)
            {
                breakOuter = 1;
                break;
            }
        }
        if (breakOuter)
            break;

        if (hover)
            SetMouseCursor(4);
        else
            SetMouseCursor(0);

        BeginDrawing();

            ClearBackground(Color{ 23, 21, 21 });
            DrawTexture(mapFrames[frameCounter], 0, 0, WHITE);
            DrawRectangle(50, 728, 200, 50, WHITE);
            DrawRectangleLinesEx({ 50, 728, 200, 50 }, 3, BLACK);
            DrawTextEx(font, "Back to menu", { 75, 745 }, 20, 2, BLACK);

            if (CheckCollisionPointRec(GetMousePosition(), { 50, 728, 200, 50 }))
            {
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                {
                    startProgram();
                    break;
                }
            }

        EndDrawing();
    }
    return 1;
}