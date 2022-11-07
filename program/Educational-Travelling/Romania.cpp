#include "raylib.h"

void romaniaQuest()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("ROMANIA", 20, 20, 30, GRAY);

        EndDrawing();
    }
}