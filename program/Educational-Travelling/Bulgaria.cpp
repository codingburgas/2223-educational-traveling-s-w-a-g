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
            200 },
            30, 5, WHITE);

        DrawRectangleLinesEx({ (SCREEN_WIDTH - 250) / 2, 350, 250, 75 }, 6, WHITE);
        DrawTextEx(font, "Back to map",
            { (250 - MeasureTextEx(font, "Back to map", 25, 5).x) / 2 + (SCREEN_WIDTH - 250) / 2,
              (75 - MeasureTextEx(font, "Back to map", 25, 5).y) / 2 + 350 },
            25, 5, WHITE);

        if (CheckCollisionPointRec(GetMousePosition(), { (SCREEN_WIDTH - 250) / 2, 350, 250, 75 }))
        {
            DrawRectangleRec({ (SCREEN_WIDTH - 250) / 2, 350, 250, 75 }, WHITE);
            DrawTextEx(font, "Back to map",
                { (250 - MeasureTextEx(font, "Back to map", 25, 5).x) / 2 + (SCREEN_WIDTH - 250) / 2,
                  (75 - MeasureTextEx(font, "Back to map", 25, 5).y) / 2 + 350 },
                25, 5, BLACK);
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                drawMap();
        }

        EndDrawing();
    }
    return 1;
}