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

void funkciq()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("pojrepojre", 20, 20, 30, GRAY);

        EndDrawing();
    }
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

    float coords[8][4] = { {250, 350, 150, 100}, {450, 410, 310, 120}, {450, 100, 250, 260}, {70, 85, 250, 110}, 
                        {700, 550, 90, 65}, {345, 630, 95, 150}, {240, 630, 73, 60}, {740, 90, 90, 60} };

    void (*quests[8])() = { serbiaQuest, bulgariaQuest, romaniaQuest, hungaryQuest, 
                            turkeyQuest, greeceQuest, albaniaQuest, moldovaQuest };

    while (!WindowShouldClose())
    {
        SetMouseCursor(0);

        Vector2 mouse = GetMousePosition();

        timer += GetFrameTime();

        if (timer >= 0.3f)
        {
            timer = 0.0f;
            frameCounter += 1;
        }

        frameCounter = frameCounter % 3;

        BeginDrawing();

        ClearBackground(Color{ 23, 21, 21 });
        DrawTextureRec(map, 
                       Rectangle{ frameWidth * frameCounter, 0, frameWidth, float(map.height) },
                       Vector2{0, 0}, RAYWHITE);

        for (int i = 0; i < 8; i++)
        {
            if (CheckCollisionPointRec(mouse, { coords[i][0], coords[i][1], coords[i][2], coords[i][3] }))
            {
                SetMouseCursor(4);
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    (*quests[i])();
                break;
            }
        }

        //DrawText(std::to_string(mouse.x).c_str(), 50, 650, 20, RED);
        //DrawText(std::to_string(mouse.y).c_str(), 50, 700, 20, RED);
        

        EndDrawing();
    }
}