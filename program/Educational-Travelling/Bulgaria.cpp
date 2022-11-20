#include "raylib.h"
#include "map.h"

int bulgariaQuest()
{
    Font font = LoadFont("../assets/fonts/CONSOLA.ttf");
    Texture2D background = LoadTexture("");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        int promptChoice = 0;

        ClearBackground(BLACK);
        drawComingSoonPrompt(background, &promptChoice, WHITE, 1);

        if (promptChoice == 1)
            drawMap();
        break;

        EndDrawing();
    }
    return 1;
}