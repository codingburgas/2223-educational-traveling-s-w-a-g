#include "raylib.h"
#include "map.h"

void DrawMap()
{
    Texture2D map = LoadTexture("../assets/maps/map_frames.png");
    SetTargetFPS(60);

    map.height *= 1.5;
    map.width *= 1.5;

    int frameCounter = 0;
    float timer = 0.0f;
    float frameWidth = float(map.width / 4);

    SetMouseCursor(0);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(Color{ 23, 21, 21 });

        timer += GetFrameTime();

        if (timer >= 0.3f)
        {
            timer = 0.0f;
            frameCounter += 1;
        }

        frameCounter = frameCounter % 3;

        DrawTextureRec(map, 
                        Rectangle{ frameWidth * frameCounter, 0, frameWidth, float(map.height) },
                        Vector2{0, 0},
                        WHITE);

        EndDrawing();
    }
}