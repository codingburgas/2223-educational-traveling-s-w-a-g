#include "raylib.h"

void greeceQuest()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("GREECE", 20, 20, 30, GRAY);

        EndDrawing();
    }
}