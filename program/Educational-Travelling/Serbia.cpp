#include "raylib.h"
#include "map.h"
#include <iostream>
#include <fstream>

int serbiaQuest()
{
    Texture2D background = LoadTexture("../assets/quests/Serbia/Serbia_Background.png");
    Color color = BLACK;

    background.height *= 1.5;
    background.width *= 1.5;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        int promptChoice = 0;
        ComingSoonPrompt(background, &promptChoice, color);

        drawMap();

        break;

        EndDrawing();
    }
    return 1;
}