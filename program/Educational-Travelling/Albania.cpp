#include "raylib.h"

void albaniaQuest()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("ALBANIA", 20, 20, 30, GRAY);

        EndDrawing();
    }
}