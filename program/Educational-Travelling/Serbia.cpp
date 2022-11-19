#include "raylib.h"

int serbiaQuest()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("SERBIA", 20, 20, 30, GRAY);

        EndDrawing();
    }
    return 1;
}