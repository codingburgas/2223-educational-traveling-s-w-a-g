#include "raylib.h"
#include "map.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void greeceQuest()
{
    fstream file;
    string character;

    file.open("../assets/data/settings.txt", ios::in);
    if (file.is_open())
        getline(file, character);
    file.close();

    Texture2D background = LoadTexture("../assets/quests/Greece/bar.png");

    Texture2D player = LoadTexture(("../assets/characters/" + character + ".png").c_str());
    Texture2D walkR = LoadTexture(("../assets/characters/" + character + "_walk_right.png").c_str());
    Texture2D walkL = LoadTexture(("../assets/characters/" + character + "_walk_left.png").c_str());

    Texture2D plate = LoadTexture("../assets/quests/Greece/plate.png");

    background.width *= 1.00;
    background.height *= 1.22;

    player.width *= 0.5;
    player.height *= 0.5;

    walkR.width *= 0.5;
    walkR.height *= 0.5;
    walkL.width *= 0.5;
    walkL.height *= 0.5;

    plate.width *= 0.2;
    plate.height *= 0.2;

    float timer = 0.0f;
    float gameTime = 0.0f;

    float playerXPos = 770;
    float plateXPos = GetRandomValue(playerXPos - 150, playerXPos + 150);;
    float plateYPos = plate.height;

    bool walkRight = 0;
    bool loss = 0;

    while (!WindowShouldClose())
    {
        timer += GetFrameTime();
        gameTime += GetFrameTime();

        if (!loss)
        {
            plateYPos += 10;
            if (plateYPos >= 828)
            {
                plateYPos = plate.height;
                while (true)
                {
                    plateXPos = GetRandomValue(playerXPos + 150, playerXPos - 150);
                    if (plateXPos + plate.width <= 900 and plateXPos - plate.width >= 0)
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

            BeginDrawing();

            if (loss == 0)
            {
                ClearBackground(RAYWHITE);

                DrawTexture(background, 0, 0, WHITE);
            }

            if (timer < 1.0f)
                DrawTexture(plate, plateXPos, plateYPos, WHITE);
            else if (plateYPos <= 828)
            {
                if (CheckCollisionRecs({ playerXPos, 650, float(player.width),float(player.height) },
                    { plateXPos + 35, plateYPos, float(plate.width) - 60, float(plate.height) }))
                {
                    loss = 1;
                    timer = 1.0f;
                }
                else
                    DrawTexture(plate, plateXPos, plateYPos, WHITE);
            }

            if (loss == 0)
            {
                if (IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_RIGHT))
                    DrawTexture(walkRight ? walkR : walkL, playerXPos, 650, WHITE);
                else
                    DrawTexture(player, playerXPos, 650, WHITE);
            }

            if (loss == 1)
            {
                int promptChoice = 0;
                drawLossPrompt(&promptChoice);
                if (promptChoice == 1)
                {
                    greeceQuest();
                    break;
                }
                else if (promptChoice == 2)
                {
                    drawMap();
                    break;
                }
            }

            if (gameTime >= 5.0f and loss == 0)
            {
                const char* message[3] = { "You've successfully survived", "the sirtaki event.", "You've returned to Athens." };
                drawWinPrompt(message);
                markCountryAsVisited(5);
                drawMap();
                break;
            }

            EndDrawing();
        }
    }
}