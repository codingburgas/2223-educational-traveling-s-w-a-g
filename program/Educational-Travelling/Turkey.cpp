#include "raylib.h"
#include "map.h"
#include <iostream>
#include <fstream>

using namespace std;

// displays Turkey quest
int drawTurkeyQuest(bool returned)
{
    string character = getCharacterFromSettings();

    Texture2D background = LoadTexture("../assets/quests/Turkey/arabian_nights_background.png");

    Texture2D player = LoadTexture(("../assets/characters/" + character + ".png").c_str());
    Texture2D walkR = LoadTexture(("../assets/characters/" + character + "_walk_right.png").c_str());
    Texture2D walkL = LoadTexture(("../assets/characters/" + character + "_walk_left.png").c_str());

    Texture2D sand = LoadTexture("../assets/quests/Turkey/Sand.png");
    //Texture2D cloud1 = LoadTexture("../assets/placeholder/cloud_placeholder.png");
    Texture2D cloud = LoadTexture("../assets/quests/Turkey/cloud.png");
    Texture2D bed = LoadTexture("../assets/quests/Turkey/bed.png");
    
    cloud.width *= 0.33;
    cloud.height *= 0.33;

    //cloud1.width *= 0.33;
    //cloud1.height *= 0.33;

    bed.width *= 0.75;
    bed.height *= 0.75;

    background.width *= 1.00;
    background.height *= 1.00;

    sand.width *= 2.8;
    sand.height *= 1;

    player.width *= 0.5;
    player.height *= 0.5;

    walkR.width *= 0.5;
    walkR.height *= 0.5;
    walkL.width *= 0.5;
    walkL.height *= 0.5;

    float timer = 0.0f;
    float gameTime = 0.0f;

    float playerXPos = 770;
    float playerYPos = 550;

    float sandY = 828;

    bool jump = false;
    float jumptimer = 0;
    float jumpLimit = 0;
    float cooldown = 0;

    bool walkRight = 0;
    bool loss = 0;

    bool started = false;

    while (!WindowShouldClose())
    {
        timer += GetFrameTime();
        gameTime += GetFrameTime();

        if (!loss)
        {
            sandY -= 0.7f;

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

            if (IsKeyPressed(KEY_SPACE) and jumpLimit <= 32)
            {
                jump = true;
            }
            if (jump and jumptimer <= 32) 
            {
                playerYPos -= 5.0f;
                jumpLimit++;
                jumptimer++;
            }
            if (jumpLimit >= 32) 
            {
                cooldown++;
                jump = false;
                jumptimer = 0;
            }
            if (cooldown >= 32) 
            {
                jumpLimit = 0;
                cooldown = 0;
            }
            if (playerYPos <= 924 - player.height and !(playerXPos <= 520 + cloud.width - player.width and playerXPos >= 520 and playerYPos == 615 - (cloud.height / 2 - 50)) and!(playerXPos <= 180 + cloud.width - player.width and playerXPos >= 180 and playerYPos == 455 - (cloud.height/2 - 50)) and !(playerXPos <= 520 + cloud.width - player.width and playerXPos >= 520 and playerYPos == 295 - (cloud.height / 2 - 50)) and !(playerXPos <= 180 + cloud.width - player.width and playerXPos >= 180 and playerYPos == 135 - (cloud.height / 2 - 50)) and jump == false)
            {
                playerYPos += 5.0f;
            }

            if (playerXPos > 924 - player.width)
            {
                playerXPos = 924 - player.width;
            }
            else if (playerXPos < 0)
            {
                playerXPos = 0.0f;
            }

            if (sandY <= playerYPos)
            {
                loss = 1;
            }

            BeginDrawing();

            if (!started and !returned)
            {
                int promptChoice = 0;
                const char* message[3] = { "You smoke nargile in a club...", "You end up smoking too much...", "You end up passing out..." };
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

                DrawTexture(background, 0, 0, WHITE);
                DrawTexture(cloud, 520, 615, WHITE);
                DrawTexture(cloud, 180, 455, WHITE);
                DrawTexture(cloud, 520, 290, WHITE);
                DrawTexture(cloud, 180, 130, WHITE);
                DrawTexture(bed, 250, 120, WHITE);
                DrawTexture(sand, 0, sandY, WHITE);
            }

            if (loss == 0)
            {
                if (IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_RIGHT))
                {
                    DrawTexture(walkRight ? walkR : walkL, playerXPos, playerYPos, WHITE);
                }
                else
                {
                    DrawTexture(player, playerXPos, playerYPos, WHITE);
                }
            }

            if (loss == 1)
            {
                int promptChoice = 0;
                drawLossPrompt(&promptChoice);

                if (promptChoice == 1)
                {
                    drawTurkeyQuest(1);
                    break;
                }
                else if (promptChoice == 2)
                {
                    drawMap();
                    break;
                }
                if (promptChoice == 0)
                {
                    break;
                }
            }

            if (playerYPos <= 120 and playerXPos >= 250 and playerXPos <= 250 + bed.width * 0.75 and loss == 0)
            {
                lockOrUnlockCountry(4, '1');
                int promptChoice = 0;
                const char* message[3] = { "You've successfully survived", "the arabian nights event.", "You have woken up in your room in Istanbul." };
                drawWinPrompt(message, &promptChoice);

                if (promptChoice == 1)
                {
                    drawMap();
                    break;
                }
                else if (promptChoice == 0)
                {
                    break;
                }
            }
            EndDrawing();
        }
    }
    return 1;
}