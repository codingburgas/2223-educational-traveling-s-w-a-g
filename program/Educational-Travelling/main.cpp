#include "raylib.h"
#include "map.h"
#include <string>
#include <fstream>

using namespace std;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

    Texture2D menuLight = LoadTexture("../assets/menus/main_menu_light.png");
    Texture2D menuDark = LoadTexture("../assets/menus/main_menu_dark.png");

    menuLight.width *= 1.21;
    menuLight.height *= 1.21;
    menuDark.width *= 1.21;
    menuDark.height *= 1.21;

    float yPos[3] = {308, 445, 577};
    bool isStartPressed = 0; 

    fstream settings;
    string theme;

    //bool isWindowClosed = 0;

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
            isStartPressed = 1;

        if (IsMouseButtonUp(MOUSE_BUTTON_LEFT) && isStartPressed)
        {
            if (drawMap() == 1) 
            {
                for (int i = 0; i < 8; i++)
                {
                    markCountryAsVisited(i, '0');
                }
                break;
                isStartPressed = 0;
            }
        }
            
        if (CheckCollisionPointRec(mouse, { 212, yPos[1], 507, 96 }) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if (drawSettingsMenu() == 1)
                break;
        }

        settings.open("../assets/data/settings.txt", ios::in);
        if (settings.is_open())
        {
            int i = 0;
            while (i < 2)
            {
                getline(settings, theme);
                i++;
            }
        }
        settings.close();

        if(CheckCollisionPointRec(mouse, { 212, yPos[2], 507, 96 }) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            break;

        BeginDrawing();

        ClearBackground(theme == "light" ? Color{124, 164, 200} : Color{ 103, 89, 113 });
            DrawTexture(theme == "light" ? menuLight : menuDark, 0, (SCREEN_HEIGHT - menuLight.height) / 2, WHITE);
           
        EndDrawing();
    }

    CloseWindow();
}