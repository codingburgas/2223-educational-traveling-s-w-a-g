#include "raylib.h"
#include "map.h"
#include "Albania.h"
#include "Bulgaria.h"
#include "Greece.h"
#include "Hungary.h"
#include "Moldova.h"
#include "Romania.h"
#include "Serbia.h"
#include "Turkey.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct COUNTRY_DATA {
    string code;
    int rectCount;
    void (*quest)();
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

void drawMap()
{
    SetMouseCursor(0);

    Texture2D map = LoadTexture("../assets/maps/map_frames.png");

    SetTargetFPS(60);

    map.height *= 1.5;
    map.width *= 1.5;

    int frameCounter = 0;
    float timer = 0.0f;
    float frameWidth = float(map.width / 4);

    fstream mask;
    fstream progress;

    COUNTRY_DATA countries[8] = { {"rs", 57, serbiaQuest}, {"bg", 28, bulgariaQuest},
                                  {"ro", 64, romaniaQuest}, {"hu", 40, hungaryQuest},
                                  {"tr", 25, turkeyQuest}, {"gr", 60, greeceQuest},
                                  {"al", 27, albaniaQuest}, {"md", 36, moldovaQuest} };

    progress.open("../assets/data/progress.txt", ios::in);
    string visited;
    if (progress.is_open())
        getline(progress, visited);

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
                            countries[i].quest();
                        break;
                    }
                }
            }
            mask.close();
        }

        if (hover)
            SetMouseCursor(4);
        else
            SetMouseCursor(0);

        BeginDrawing();

            ClearBackground(Color{ 23, 21, 21 });
            DrawTextureRec(map, 
                           Rectangle{ float(map.width / 4) * frameCounter, 0, float(map.width / 4), float(map.height) },
                           Vector2{0, 0}, RAYWHITE);

        EndDrawing();
    }
}