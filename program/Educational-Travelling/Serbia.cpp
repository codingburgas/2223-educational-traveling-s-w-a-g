#include "raylib.h"
#include "map.h"
#include <iostream>
#include <fstream>

// displays Serbia quest
int drawSerbiaQuest()
{
    Texture2D background = LoadTexture("../assets/quests/Serbia/Serbia_Background.png");

    background.height *= 1.5;
    background.width *= 1.5;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        int promptChoice = 0;
        drawComingSoonPrompt(background, &promptChoice, BLACK, 0);

        if (promptChoice == 1)
        {
            drawMap();
        }
        break;

        EndDrawing();
    }
    return 1;
}