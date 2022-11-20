#include "raylib.h"
#include "map.h"
#include "checkpoints.h"
#include <iostream>
#include <string>

using namespace std;

int drawCheckPoint(const char* message[], const char* newLines[], int size, int countryIndex)
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
    int fontSize;

    while (!WindowShouldClose())
    {
        fontSize = index == size - 1 ? 50 : 30;
        xPos = (SCREEN_WIDTH - MeasureTextEx(font, message[index], fontSize, 5).x) / 2;
        text += message[index][letter];

        if (letter >= strlen(message[index]) and index > 0)
        {
            newLine += newLines[index][newLineLetter];
            newLineLetter++;
        }

        BeginDrawing();

        ClearBackground(BLACK);

        DrawTextEx(font, "Story quest", { 50, 50 }, 30, 5, WHITE);
        DrawTextEx(font, text.c_str(), { xPos, 400 }, fontSize, 5, WHITE);

        if (letter >= strlen(message[index]) and index > 0)
        {
            newXPos = (SCREEN_WIDTH - MeasureTextEx(font, newLines[index], 30, 5).x) / 2;
            DrawTextEx(font, newLine.c_str(), { newXPos, 430 }, 30, 5, WHITE);
        }

        if (index < size - 1)
        {
            DrawRectangleLinesEx({ 628, 624, 175, 75 }, 5, WHITE);
            DrawTextEx(font, "Next >>", { 650, 650 }, 25, 5, WHITE);
            if (CheckCollisionPointRec(GetMousePosition(), { 628, 624, 175, 75 }))
            {
                DrawRectangleRec({ 628, 624, 175, 75 }, WHITE);
                DrawTextEx(font, "Next >>", { 650, 650 }, 25, 5, BLACK);
            }
        }

        if (index == size - 1)
        {
            DrawRectangleLinesEx({ (SCREEN_WIDTH - 250) / 2, 500, 250, 75 }, 6, WHITE);
            DrawTextEx(font, "Back to map",
                { (250 - MeasureTextEx(font, "Back to map", 25, 5).x) / 2 + (SCREEN_WIDTH - 250) / 2,
                  (75 - MeasureTextEx(font, "Back to map", 25, 5).y) / 2 + 500 },
                25, 5, WHITE);

            if (CheckCollisionPointRec(GetMousePosition(), { (SCREEN_WIDTH - 250) / 2, 500, 250, 75 }))
            {
                DrawRectangleRec({ (SCREEN_WIDTH - 250) / 2, 500, 250, 75 }, WHITE);
                DrawTextEx(font, "Back to map",
                    { (250 - MeasureTextEx(font, "Back to map", 25, 5).x) / 2 + (SCREEN_WIDTH - 250) / 2,
                      (75 - MeasureTextEx(font, "Back to map", 25, 5).y) / 2 + 500 },
                    25, 5, BLACK);

                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                {
                    lockOrUnlockCountry(countryIndex, '1');
                    drawMap();
                    break;
                }

            }
        }

        EndDrawing();

        letter++;

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) and index < size - 1 and CheckCollisionPointRec(GetMousePosition(), { 628, 624, 175, 75 }))
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

int hungaryCheckpoint()
{
	const char* message[6] = { "You go to Budapest...", "You visit 3 of the", "You try Rudas Baths...", "Next you go to Gellert Thermal Bath...", "Finally you go to Szechenyi Thermal Bath...", "CHECKPOINT UNLOCKED !!!" };
	const char* newLines[6] = { "", "most popular thermal baths...", "It feels great, so you give it 4 stars.", "It feels alright, so you give it 3 stars.", "it feels amazing! You give it 5 stars!", "" };
	drawCheckPoint(message, newLines, 6, 3);

    return 1;
}

int moldovaCheckpoint()
{
	const char* message[8] = { "You enter a bar in Moldova...", "You get to rate 3 of their", "You try Circova...", "Now you try Vineria Din Vale from", "It's time for Tomai from 2016...Oh my,", "After you rate all the wines the barman", "He gives you a place to stay the night.", "CHECKPOINT UNLOCKED !!!" };
	const char* newLines[8] = { "", "most popular wines...", "It tastes so good you give it a 9 !!", "2019... It's pretty fine - '8' you say.", "it tastes amazing!!You give it a 10!!", "wants to thank you for your kindness.", "", "" };
	drawCheckPoint(message, newLines, 8, 7);

    return 1;
}