#include "raylib.h"

void moldovaQuest()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("MOLDOVA", 20, 20, 30, GRAY);

        EndDrawing();
    }
}