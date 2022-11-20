#include "raylib.h"
#include "map.h"
#include <iostream>
#include <fstream>

// loads Albania quest
int drawAlbaniaQuest()
{
    Texture2D background = LoadTexture("../assets/quests/Albania/Albania_Background.png");

    background.height *= 1.5;
    background.width *= 1.5;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        int promptChoice = 0;
        drawComingSoonPrompt(background, &promptChoice, WHITE, 0);

        if (promptChoice == 1)
        {
            drawMap();
        }   
        break;

        EndDrawing();
    }
    return 1;
}