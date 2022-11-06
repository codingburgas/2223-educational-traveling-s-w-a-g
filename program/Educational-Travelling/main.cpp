#include "raylib.h"
#include "map.h"
#include <string>
using namespace std;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

    Texture2D menu;
    menu = LoadTexture("../assets/menus/main_menu_light.png");

    menu.width *= 0.61;
    menu.height *= 0.61;


    while (!WindowShouldClose())
    {
        Vector2 mouse = GetMousePosition();

        if (mouse.x >= 122 and mouse.x <= 669 and mouse.y >= 330 and mouse.y <= 437)
            SetMouseCursor(4);

        else
            SetMouseCursor(0);
            
        if (mouse.x >= 122 and mouse.x <= 669 and mouse.y >= 330 and mouse.y <= 437 and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            DrawMap();
            
        BeginDrawing();

            ClearBackground(Color{ 124, 164, 200 });

            DrawTexture(menu, 0, (SCREEN_HEIGHT - menu.height) / 2, WHITE);

        EndDrawing();
    }

    CloseWindow();
}