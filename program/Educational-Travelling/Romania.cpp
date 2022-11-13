#include "raylib.h"
#include "map.h"
#include <iostream>
#include <string>

void romaniaQuest()
{
    Texture2D roBg = LoadTexture("../assets/quests/Romania/ro_bg.png");
    Texture2D player = LoadTexture("../assets/characters/character_default.png");
    Texture2D walk = LoadTexture("../assets/characters/character_walk.png");
    Texture2D vampire = LoadTexture("../assets/quests/Romania/vampire.png");
    Texture2D shadow = LoadTexture("../assets/quests/Romania/shadow.png");

    roBg.width *= 1.68;
    roBg.height *= 1.68;

    player.width *= 0.5;
    player.height *= 0.5;

    walk.width *= 0.5;
    walk.height *= 0.5;

    vampire.width *= 0.4;
    vampire.height *= 0.4;
    shadow.width *= 0.4;
    shadow.height *= 0.4;

    float timer = 0.0f;

    float playerXPos = 770;

    float vampireXPos = GetRandomValue(0, 770);

    while (!WindowShouldClose())
    {
        timer += GetFrameTime();

        if (timer >= 2.0f)
        {
            vampireXPos = GetRandomValue(playerXPos - 150, playerXPos + 150);
            timer = 0.0f;
        }

        if (IsKeyDown(KEY_LEFT))
        {
            playerXPos -= 5.0f;
        }
        if (IsKeyDown(KEY_RIGHT))
        {
            playerXPos += 5.0f;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(roBg, -620, 0, WHITE);

        if (timer < 1.0f)
            DrawTexture(shadow, vampireXPos, 623, GRAY);
        else if (timer < 2.0f)
            DrawTexture(vampire, vampireXPos, 623, GRAY);
        else if (timer == 2.0f)
            UnloadTexture(vampire);

        if (IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_RIGHT))
        {
            DrawTexture(walk, playerXPos, 623, GRAY);
        }
        else
        {
            DrawTexture(player, playerXPos, 623, GRAY);
        }

        EndDrawing();
    }
}