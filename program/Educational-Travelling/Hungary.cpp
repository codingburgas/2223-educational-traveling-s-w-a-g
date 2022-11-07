#include "raylib.h"

void hungaryQuest()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("HUNGARY", 20, 20, 30, GRAY);

        EndDrawing();
    }
}