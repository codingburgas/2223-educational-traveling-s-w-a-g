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

    bool isButtonPressed = 0;

    while (!WindowShouldClose())
    {
        Vector2 mouse = GetMousePosition();

        if (CheckCollisionPointRec(mouse, Rectangle{ 212, 308, 507, 96 }))
            SetMouseCursor(4);

        else
            SetMouseCursor(0);

        if (CheckCollisionPointRec(mouse, Rectangle{ 212, 308, 507, 96 }) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            isButtonPressed = 1;

        if (IsMouseButtonUp(MOUSE_BUTTON_LEFT) && isButtonPressed)
        {
            drawMap();
            break;
        }
            
        BeginDrawing();

            ClearBackground(Color{ 124, 164, 200 });
            DrawTexture(menu, 0, (SCREEN_HEIGHT - menu.height) / 2, WHITE);
           
        EndDrawing();
    }

    CloseWindow();
}