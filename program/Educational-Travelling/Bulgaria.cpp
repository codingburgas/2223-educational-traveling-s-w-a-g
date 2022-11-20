#include "raylib.h"
#include "map.h"

// displays assets and text for Bulgaria
int drawMentorText(Texture2D background, Texture2D mentor, const char* message[], const char* newLines[], int size)
{
    Font font = LoadFont("../assets/fonts/CONSOLA.ttf");

    float xPos;

    int letter = 0;
    int index = 0;
    string text = "";

    float newXPos;
    int newLineLetter = 0;
    string newLine = "";

    SetTargetFPS(30);

    int press = 0;
    bool buttonPress = 0;
    //int fontSize;

    while (!WindowShouldClose())
    {
        //fontSize = index == size - 1 ? 50 : 30;
        xPos = (SCREEN_WIDTH - MeasureTextEx(font, message[index], 25, 2).x) / 2;
        text += message[index][letter];

        if (letter >= strlen(message[index]))
        {
            newLine += newLines[index][newLineLetter];
            newLineLetter++;
        }

        BeginDrawing();

        ClearBackground(BLACK);

        DrawTexture(background, 0, 0, WHITE);
        DrawTexture(mentor, (SCREEN_WIDTH - mentor.width) / 2, -75, WHITE);

        DrawTextEx(font, text.c_str(), { xPos, 650 }, 25, 2, WHITE);

        if (letter >= strlen(message[index]))
        {
            newXPos = (SCREEN_WIDTH - MeasureTextEx(font, newLines[index], 25, 2).x) / 2;
            DrawTextEx(font, newLine.c_str(), { newXPos, 680 }, 25, 2, WHITE);
        }

        if (index < size - 1)
        {
            DrawTextEx(font, "Next >>", { 530, 750 }, 25, 2, WHITE);
        }

        DrawRectangle(50, 728, 200, 50, WHITE);
        DrawRectangleLinesEx({ 50, 728, 200, 50 }, 3, BLACK);
        DrawTextEx(font, "Back to map", { 75, 745 }, 20, 2, BLACK);

        if (CheckCollisionPointRec(GetMousePosition(), { 50, 728, 200, 50 }))
        {
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                drawMap();
                break;
            }
        }

        EndDrawing();

        letter++;

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) and index < size - 1 and CheckCollisionPointRec(GetMousePosition(), { 521, 739, 124, 42 }))
        {
            index++;
            newLineLetter = 0;
            letter = 0;
            text = "";
            newLine = "";
        }
    }
    return 1;
}

// loads Bulgaria quest
int drawBulgariaQuest()
{
    Texture2D background = LoadTexture("../assets/quests/Bulgaria/bulgaria_background.png");
    Texture2D mentor = LoadTexture("../assets/quests/Bulgaria/mentor.png");

    background.height *= 1.92;
    background.width *= 1.92;

    mentor.height *= 1.9;
    mentor.width *= 1.9;

    const char* message[8] = { "Greetings!", "Welcome to", "In this game", "to 7 countries", "In order to win", "Romania, Serbia", "and Albania.", "Have fun"};
    const char* newLines[8] = { "", "Balkan.X", "you can travel", "in the Balkans", "you must win in", "Turkey, Greece", "", "on your journey!"};

    if (drawMentorText(background, mentor, message, newLines, 8) == 1)

    return 1;
}