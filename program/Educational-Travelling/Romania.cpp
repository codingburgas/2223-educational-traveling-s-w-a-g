#include "raylib.h"
#include "map.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void drawLossPrompt(int *promptChoice)
{
    Font font = LoadFont("../assets/fonts/pixelplay.tff");

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
    Font font = LoadFont("../assets/fonts/pixelplay.tff");

    bool isBackPressed = 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawTextEx(font, message[0], {(SCREEN_WIDTH - MeasureTextEx(font, message[0], 30, 5).x) / 2, 200}, 30, 5, WHITE);
        DrawTextEx(font, message[1], {(SCREEN_WIDTH - MeasureTextEx(font, message[1], 30, 5).x) / 2, 235}, 30, 5, WHITE);
        DrawTextEx(font, message[2], {(SCREEN_WIDTH - MeasureTextEx(font, message[2], 30, 5).x) / 2, 270}, 30, 5, WHITE);

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

void romaniaQuest()
{
    fstream file;
    string character;

    file.open("../assets/data/settings.txt", ios::in);
    if (file.is_open())
        getline(file, character);
    file.close();

    Texture2D roBg = LoadTexture("../assets/quests/Romania/ro_bg.png");

    Texture2D player = LoadTexture(("../assets/characters/" + character + ".png").c_str());
    Texture2D walkR = LoadTexture(("../assets/characters/" + character + "_walk_right.png").c_str());
    Texture2D walkL = LoadTexture(("../assets/characters/" + character + "_walk_left.png").c_str());

    Texture2D vampire = LoadTexture("../assets/quests/Romania/vampire.png");
    Texture2D shadow = LoadTexture("../assets/quests/Romania/shadow.png");

    roBg.width *= 1.68;
    roBg.height *= 1.68;

    player.width *= 0.5;
    player.height *= 0.5;

    walkR.width *= 0.5;
    walkR.height *= 0.5;
    walkL.width *= 0.5;
    walkL.height *= 0.5;

    vampire.width *= 0.6;
    vampire.height *= 0.6;
    shadow.width *= 0.6;
    shadow.height *= 0.6;

    float timer = 0.0f;
    float gameTime = 0.0f;

    float playerXPos = 770;
    float vampireXPos = 0;

    bool walkRight = 0;
    bool loss = 0;
    //bool isWindowClosed = 0;

    while (!WindowShouldClose())
    {
        timer += GetFrameTime();
        gameTime += GetFrameTime();

        if (!loss)
        {
            if (timer >= 2.0f)
            {
                while (true)
                {
                    vampireXPos = GetRandomValue(playerXPos - 150, playerXPos + 150);
                    if (vampireXPos + vampire.width <= 924 and vampireXPos >= 0)
                        break;
                }
                timer = 0.0f;
            }

            if (IsKeyDown(KEY_LEFT))
            {
                walkRight = 0;
                playerXPos -= 5.0f;
            }
            if (IsKeyDown(KEY_RIGHT))
            {
                walkRight = 1;
                playerXPos += 5.0f;
            }

            if (playerXPos > 924 - player.width)
                playerXPos = 924 - player.width;
            else if (playerXPos < 0)
                playerXPos = 0.0f;
        }

        BeginDrawing();

        if (loss == 0)
        {
            ClearBackground(RAYWHITE);

            DrawTexture(roBg, -620, 0, WHITE);
        }

        if (timer < 1.0f)
            DrawTexture(shadow, vampireXPos, 500, GRAY); // BLACK?
        else if (timer < 2.0f)
        {
            if (CheckCollisionRecs({ playerXPos, 600, float(player.width),float(player.height) },
                { vampireXPos + 35, 500, float(vampire.width) - 60, float(vampire.height) }))   
            {
                loss = 1;
                timer = 1.0f;
            }
            else
                DrawTexture(vampire, vampireXPos, 500, GRAY);
        }

        if (loss == 0)
        {
            if (IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_RIGHT))
              DrawTexture(walkRight ? walkR : walkL, playerXPos, 600, GRAY);
            else
                DrawTexture(player, playerXPos, 600, GRAY);
        } 

        if (loss == 1)
        {
            int promptChoice = 0;
            drawLossPrompt(&promptChoice);
            if (promptChoice == 1)
            {
                romaniaQuest();
                break;
            }
            else if (promptChoice == 2)
            {
                drawMap();
                break;
            }
        }   

        if (gameTime >= 30.0f and loss == 0)
        {
            const char* message[3] = { "You've successfully escaped from", "the vampires in the woods.", "You've returned to Bucharest." };
            drawWinPrompt(message);
            drawMap();
            break;
        }

        DrawText(to_string(gameTime).c_str(), 20, 20, 20, WHITE);

        EndDrawing();
    }
}