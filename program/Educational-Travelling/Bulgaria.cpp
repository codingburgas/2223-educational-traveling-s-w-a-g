#include "raylib.h"

void bulgariaQuest()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("BULGARIA", 20, 20, 30, GRAY);

        EndDrawing();
    }
}