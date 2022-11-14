#include "raylib.h"
#include "map.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void romaniaQuest()
{
    fstream file;
    string character;

    file.open("../assets/data/settings.txt", ios::in);
    if (file.is_open())
        getline(file, character);

    Texture2D roBg = LoadTexture("../assets/quests/Romania/ro_bg.png");

    Texture2D player, walkR, walkL;

    player = LoadTexture(("../assets/characters/" + character + ".png").c_str());
    walkR = LoadTexture(("../assets/characters/" + character + "_walk_right.png").c_str());
    walkL = LoadTexture(("../assets/characters/" + character + "_walk_left.png").c_str());

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

    float playerXPos = 770;

    float vampireXPos = GetRandomValue(0, 770);

    bool walkRight = 0;

    //int lives = 3;

    while (!WindowShouldClose())
    {
        timer += GetFrameTime();

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


        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(roBg, -620, 0, WHITE);

        //DrawRectangleLines(vampireXPos + 35, 500, vampire.width - 60, vampire.height, WHITE);

        if (timer < 1.0f)
            DrawTexture(shadow, vampireXPos, 500, GRAY); //BLACK?
        else if (timer < 2.0f)
            DrawTexture(vampire, vampireXPos, 500, GRAY);

        if (IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_RIGHT))
            DrawTexture(walkRight ? walkR : walkL, playerXPos, 600, GRAY);
        else
            DrawTexture(player, playerXPos, 600, GRAY);

        EndDrawing();
    }
}