#include "raylib.h"

int bulgariaQuest()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("BULGARIA", 20, 20, 30, GRAY);

        EndDrawing();
    }
    return 1;
}