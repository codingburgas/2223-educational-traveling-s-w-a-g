#include "raylib.h"
#include "map.h"

void DrawMap()
{
    Texture2D map = LoadTexture("../assets/maps/animated_map.gif");

    map.height *= 1.35;
    map.width *= 1.35;

    SetMouseCursor(0);

    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(Color{ 23, 21, 21 });
            DrawTexture(map, 0, 0, WHITE);

        EndDrawing();
    }
}