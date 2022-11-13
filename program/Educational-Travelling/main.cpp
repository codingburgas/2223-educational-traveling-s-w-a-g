#include "raylib.h"
#include "map.h"
#include <string>

using namespace std;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

    Texture2D menu;
    menu = LoadTexture("../assets/menus/main_menu_light.png");

    menu.width *= 1.21;
    menu.height *= 1.21;

    float yPos[3] = {308, 445, 577};
    bool isButtonPressed = 0; 

    //212 308 x 96
    while (!WindowShouldClose())
    {
        Vector2 mouse = GetMousePosition();
        bool hover = 0;

        for (int i = 0; i < 3; i++)
        {
            if (CheckCollisionPointRec(mouse, {212, yPos[i], 507, 96}))
                hover = 1;  
        }
        if (hover)
            SetMouseCursor(4);
        else
            SetMouseCursor(0);


        if (CheckCollisionPointRec(mouse, { 212, yPos[0], 507, 96 }) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            isButtonPressed = 1;

        if (IsMouseButtonUp(MOUSE_BUTTON_LEFT) && isButtonPressed)
        {
            drawMap();
            break;
        }

        if(CheckCollisionPointRec(mouse, { 212, yPos[2], 507, 96 }) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            break;

        BeginDrawing();

            ClearBackground(Color{ 124, 164, 200 });
            DrawTexture(menu, 0, (SCREEN_HEIGHT - menu.height) / 2, WHITE);
           
        EndDrawing();
    }

    CloseWindow();
}