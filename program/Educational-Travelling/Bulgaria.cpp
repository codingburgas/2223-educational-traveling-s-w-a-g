#include "raylib.h"
#include "map.h"
int bulgariaQuest()
{
    Font font = LoadFont("../assets/fonts/CONSOLA.ttf");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);
        DrawTextEx(font, "Coming soon...", 
            { (SCREEN_WIDTH - MeasureTextEx(font, "Coming soon...", 30, 5).x) / 2, 
            (SCREEN_HEIGHT - MeasureTextEx(font, "Coming soon...", 30, 5).y) / 2 },
            30, 5, WHITE);

        EndDrawing();
    }
    return 1;
}