#include "raylib.h"

void turkeyQuest()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("TURKEY", 20, 20, 30, GRAY);

        EndDrawing();
    }
}