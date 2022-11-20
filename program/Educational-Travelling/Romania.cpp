#include "raylib.h"
#include "map.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// displays Romania quest
int drawRomaniaQuest()
{
    Font font = LoadFont("../assets/fonts/CONSOLA.ttf");

    string character = getCharacterFromSettings();

    Texture2D background = LoadTexture("../assets/quests/Romania/ro_bg.png");

    Texture2D player = LoadTexture(("../assets/characters/" + character + ".png").c_str());
    Texture2D walkR = LoadTexture(("../assets/characters/" + character + "_walk_right.png").c_str());
    Texture2D walkL = LoadTexture(("../assets/characters/" + character + "_walk_left.png").c_str());

    Texture2D vampire = LoadTexture("../assets/quests/Romania/vampire.png");
    Texture2D shadow = LoadTexture("../assets/quests/Romania/shadow.png");

    background.width *= 1.68;
    background.height *= 1.68;

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

    bool started = false;

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
                    {
                        break;
                    }
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
            {
                playerXPos = 924 - player.width;
            }
            else if (playerXPos < 0)
            {
                playerXPos = 0.0f;
            }
        }

        BeginDrawing();

        if (started == false)
        {
            int promptChoice = 0;
            const char* message[3] = { "You get lost in a forest", "during a full moon...", "Something is moving in the shadows..." };
            drawEnterPrompt(message, &promptChoice);
            if (promptChoice == 1)
            {
                started = true;
            }
            else if (promptChoice == 2)
            {
                drawMap();
                break;
            }
            else if (promptChoice == 0)
            {
                break;
            }
        }

        if (loss == 0)
        {
            ClearBackground(RAYWHITE);

            DrawTexture(background, -620, 0, WHITE);
        }

        if (timer < 1.0f)
        {
            DrawTexture(shadow, vampireXPos, 500, GRAY);
        } // BLACK?
        else if (timer < 2.0f)
        {
            if (CheckCollisionRecs({ playerXPos, 600, float(player.width),float(player.height) },
                { vampireXPos + 35, 500, float(vampire.width) - 60, float(vampire.height) }))   
            {
                loss = 1;
                timer = 1.0f;
            }
            else
            {
                DrawTexture(vampire, vampireXPos, 500, GRAY);
            }
        }

        if (loss == 0)
        {
            if (IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_RIGHT))
            {
                DrawTexture(walkRight ? walkR : walkL, playerXPos, 600, GRAY);
            }
            else
            {
                DrawTexture(player, playerXPos, 600, GRAY);
            }
        } 

        if (loss == 1)
        {
            int promptChoice = 0;
            drawLossPrompt(&promptChoice);

            if (promptChoice == 1)
            {
                drawRomaniaQuest();
            }
            else if (promptChoice == 2)
            {
                drawMap();
            }
            break;
        }   

        if (gameTime >= 30.0f and loss == 0)
        {
            lockOrUnlockCountry(2, '1');
            int promptChoice = 0;
            const char* message[3] = { "You've successfully escaped from", "the vampires in the woods.", "You've returned to Bucharest." };
            drawWinPrompt(message, &promptChoice);

            if (promptChoice == 1)
            {
                drawMap();
            }
            break;
        }

        EndDrawing();
    }
    return 1;
}