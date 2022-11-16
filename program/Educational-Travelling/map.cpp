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
    string fileName;
    int rectCount;
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

    fstream file;

    COUNTRY_DATA countries[8] = { {"rs_mask.txt", 57}, {"bg_mask.txt", 28}, {"ro_mask.txt", 64}, {"hu_mask.txt", 40}, 
                                  {"tr_mask.txt", 25}, {"gr_mask.txt", 60}, {"al_mask.txt", 27}, {"md_mask.txt", 36} };

    void (*quests[8])() = { serbiaQuest, bulgariaQuest, romaniaQuest, hungaryQuest, 
                            turkeyQuest, greeceQuest, albaniaQuest, moldovaQuest };

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
            file.open("../assets/data/country masks/" + countries[i].fileName, ios::in);

            if (file.is_open())
            {
                for (int j = 1; j < countries[i].rectCount + 1; j++)
                {
                    string rectStr;
                    getline(file, rectStr);
                    if (CheckCollisionPointRec(mouse, convertStringToRect(rectStr)))
                    {
                        hover = 1;
                        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                            (*quests[i])();
                        break;
                    }
                }
            }
            file.close();
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