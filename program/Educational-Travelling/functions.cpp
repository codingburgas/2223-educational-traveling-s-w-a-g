#include "raylib.h"
#include "map.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void drawLossPrompt(int* promptChoice)
{
    Font font = LoadFont("../assets/fonts/CONSOLA.ttf");

    bool backButtonPress = 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawTextEx(font, "You lost", { (SCREEN_WIDTH - MeasureTextEx(font, "You lost", 30, 5).x) / 2, 200 }, 30, 5, WHITE);
        DrawTextEx(font, "What would you like to do?", { (SCREEN_WIDTH - MeasureTextEx(font, "What would you like to do?", 30, 5).x) / 2, 230 }, 30, 5, WHITE);

        DrawRectangleLinesEx({ (SCREEN_WIDTH - 550) / 2, 350, 250, 75 }, 6, WHITE);
        DrawRectangleLinesEx({ (SCREEN_WIDTH - 550) / 2 + 300, 350, 250, 75 }, 6, WHITE);

        DrawTextEx(font, "Retry",
            { (250 - MeasureTextEx(font, "Retry", 25, 5).x) / 2 + (SCREEN_WIDTH - 550) / 2,
              (75 - MeasureTextEx(font, "Retry", 25, 5).y) / 2 + 350 },
            25, 5, WHITE);
        DrawTextEx(font, "Back to map",
            { (250 - MeasureTextEx(font, "Back to map", 25, 5).x) / 2 + (SCREEN_WIDTH - 550) / 2 + 300,
              (75 - MeasureTextEx(font, "Back to map", 25, 5).y) / 2 + 350 },
            25, 5, WHITE);

        if (CheckCollisionPointRec(GetMousePosition(), { (SCREEN_WIDTH - 550) / 2, 350, 250, 75 }))
        {
            DrawRectangleRec({ (SCREEN_WIDTH - 550) / 2, 350, 250, 75 }, WHITE);
            DrawTextEx(font, "Retry",
                { (250 - MeasureTextEx(font, "Retry", 25, 5).x) / 2 + (SCREEN_WIDTH - 550) / 2,
                  (75 - MeasureTextEx(font, "Retry", 25, 5).y) / 2 + 350 },
                25, 5, BLACK);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                *promptChoice = 1;
                break;
            }

        }

        if (CheckCollisionPointRec(GetMousePosition(), { (SCREEN_WIDTH - 550) / 2 + 300, 350, 250, 75 }))
        {
            DrawRectangleRec({ (SCREEN_WIDTH - 550) / 2 + 300, 350, 250, 75 }, WHITE);
            DrawTextEx(font, "Back to map",
                { (250 - MeasureTextEx(font, "Back to map", 25, 5).x) / 2 + (SCREEN_WIDTH - 550) / 2 + 300,
                  (75 - MeasureTextEx(font, "Back to map", 25, 5).y) / 2 + 350 },
                25, 5, BLACK);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                backButtonPress = 1;

            if (backButtonPress and IsMouseButtonUp(MOUSE_BUTTON_LEFT))
            {
                *promptChoice = 2;
                break;
            }

        }

        EndDrawing();
    }

}

void drawWinPrompt(const char* message[3])
{
    Font font = LoadFont("../assets/fonts/CONSOLA.ttf");

    bool isBackPressed = 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawTextEx(font, message[0], { (SCREEN_WIDTH - MeasureTextEx(font, message[0], 30, 5).x) / 2, 200 }, 30, 5, WHITE);
        DrawTextEx(font, message[1], { (SCREEN_WIDTH - MeasureTextEx(font, message[1], 30, 5).x) / 2, 235 }, 30, 5, WHITE);
        DrawTextEx(font, message[2], { (SCREEN_WIDTH - MeasureTextEx(font, message[2], 30, 5).x) / 2, 270 }, 30, 5, WHITE);

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
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                isBackPressed = 1;

            if (isBackPressed and IsMouseButtonUp(MOUSE_BUTTON_LEFT))
                break;
        }
        EndDrawing();
    }
}

void drawEnterPrompt(const char* message[3])
{
    Font font = LoadFont("../assets/fonts/CONSOLA.ttf");

    bool isBackPressed = 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawTextEx(font, message[0], { (SCREEN_WIDTH - MeasureTextEx(font, message[0], 30, 5).x) / 2, 200 }, 30, 5, WHITE);
        DrawTextEx(font, message[1], { (SCREEN_WIDTH - MeasureTextEx(font, message[1], 30, 5).x) / 2, 235 }, 30, 5, WHITE);
        DrawTextEx(font, message[2], { (SCREEN_WIDTH - MeasureTextEx(font, message[2], 30, 5).x) / 2, 270 }, 30, 5, WHITE);

        DrawRectangleLinesEx({ (SCREEN_WIDTH - 250) / 2, 350, 250, 75 }, 6, WHITE);
        DrawTextEx(font, "Proceed...",
            { (250 - MeasureTextEx(font, "Proceed...", 25, 5).x) / 2 + (SCREEN_WIDTH - 250) / 2,
              (75 - MeasureTextEx(font, "Proceed...", 25, 5).y) / 2 + 350 },
            25, 5, WHITE);

        if (CheckCollisionPointRec(GetMousePosition(), { (SCREEN_WIDTH - 250) / 2, 350, 250, 75 }))
        {
            DrawRectangleRec({ (SCREEN_WIDTH - 250) / 2, 350, 250, 75 }, WHITE);
            DrawTextEx(font, "Proceed...",
                { (250 - MeasureTextEx(font, "Proceed...", 25, 5).x) / 2 + (SCREEN_WIDTH - 250) / 2,
                  (75 - MeasureTextEx(font, "Proceed...", 25, 5).y) / 2 + 350 },
                25, 5, BLACK);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                isBackPressed = 1;

            if (isBackPressed and IsMouseButtonUp(MOUSE_BUTTON_LEFT))
                break;
        }
        EndDrawing();
    }
}

void markCountryAsVisited(int index)
{
    fstream progress;
    string visited;

    progress.open("../assets/data/progress.txt", ios::in);
    if (progress.is_open())
        getline(progress, visited);
    progress.close();
    visited[index] = '1';

    progress.open("../assets/data/progress.txt", ios::out);
    if (progress.is_open())
        progress << visited;
    progress.close();
}

string getCharacterFromSettings()
{
    fstream settings;
    string character;

    settings.open("../assets/data/settings.txt", ios::in);
    if (settings.is_open())
        getline(settings, character);
    settings.close();

    return character;
}

