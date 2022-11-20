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
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
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
            {
                backButtonPress = 1;
            }

            if (backButtonPress and IsMouseButtonUp(MOUSE_BUTTON_LEFT))
            {
                *promptChoice = 2;
                break;
            }

        }

        EndDrawing();
    }

}

void drawWinPrompt(const char* message[3], int *promptChoice)
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
            {
                isBackPressed = 1;
            }

            if (isBackPressed and IsMouseButtonUp(MOUSE_BUTTON_LEFT))
            {
                *promptChoice = 1;
                break;
            }
                
        }
        EndDrawing();
    }
}

void drawComingSoonPrompt(Texture2D background, int* promptChoice, Color color, bool isBulgaria)
{
    Font font = LoadFont("../assets/fonts/CONSOLA.ttf");

    bool isBackPressed = 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);
        if (!isBulgaria)
            DrawTexture(background, 0, 0, WHITE);

        const char* message = "Coming soon...";

        DrawTextEx(font, message, { (SCREEN_WIDTH - MeasureTextEx(font, message, 30, 5).x) / 2, 200 }, 30, 5, color);

        DrawRectangleLinesEx({ (SCREEN_WIDTH - 250) / 2, 350, 250, 75 }, 6, color);
        DrawTextEx(font, "Back to map",
            { (250 - MeasureTextEx(font, "Back to map", 25, 5).x) / 2 + (SCREEN_WIDTH - 250) / 2,
              (75 - MeasureTextEx(font, "Back to map", 25, 5).y) / 2 + 350 },
            25, 5, color);

        if (CheckCollisionPointRec(GetMousePosition(), { (SCREEN_WIDTH - 250) / 2, 350, 250, 75 }))
        {
            DrawRectangleRec({ (SCREEN_WIDTH - 250) / 2, 350, 250, 75 }, WHITE);
            DrawTextEx(font, "Back to map",
                { (250 - MeasureTextEx(font, "Back to map", 25, 5).x) / 2 + (SCREEN_WIDTH - 250) / 2,
                  (75 - MeasureTextEx(font, "Back to map", 25, 5).y) / 2 + 350 },
                25, 5, BLACK);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                isBackPressed = 1;
            }

            if (isBackPressed and IsMouseButtonUp(MOUSE_BUTTON_LEFT))
            {
                *promptChoice = 1;
                break;
            }

        }
        EndDrawing();
    }
}

int drawEnterPrompt(const char* message[3], int *promptChoice)
{
    Font font = LoadFont("../assets/fonts/CONSOLA.ttf");

    bool isBackPressed = 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawRectangleLinesEx({ 50, 728, 200, 50 }, 3, WHITE);
        DrawTextEx(font, "Back to map", { 80, 745 }, 20, 2, WHITE);

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
            {
                isBackPressed = 1;
            }

            if (isBackPressed and IsMouseButtonUp(MOUSE_BUTTON_LEFT))
            {
                *promptChoice = 1;
                break;
            }
                
        }
        if (CheckCollisionPointRec(GetMousePosition(), { 50, 728, 200, 50 }))
        {
            DrawRectangle( 50, 728, 200, 50, WHITE);
            DrawTextEx(font, "Back to map", { 80, 745 }, 20, 2, BLACK);
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                *promptChoice = 2;
                break;
            }
        }

        EndDrawing();
    }
    return 1;
}

void lockOrUnlockCountry(int index, char lock_unlock)
{
    fstream progress;
    string visited;

    progress.open("../assets/data/progress.txt", ios::in);
    if (progress.is_open())
    {
        getline(progress, visited);
    }
    progress.close();
    visited[index] = lock_unlock;

    progress.open("../assets/data/progress.txt", ios::out);
    if (progress.is_open())
    {
        progress << visited;
    }
    progress.close();
}

string getCharacterFromSettings()
{
    fstream settings;
    string character;

    settings.open("../assets/data/settings.txt", ios::in);
    if (settings.is_open())
    {
        getline(settings, character);
    }
    settings.close();

    return character;
}