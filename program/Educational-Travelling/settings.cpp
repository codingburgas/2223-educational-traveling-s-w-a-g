#include "raylib.h"
#include "map.h"
#include <fstream>
#include <string>

using namespace std;

void drawSettingsMenu()
{
	Texture2D settingsMenu = LoadTexture("../assets/menus/settings_menu.png");

	settingsMenu.width *= 1.21;
	settingsMenu.height *= 1.21;

	fstream settings;

	int frameNum = 0;

	while (!WindowShouldClose())
	{
		SetMouseCursor(0);
		Vector2 mouse = GetMousePosition();

		settings.open("../assets/data/settings.txt", ios::in);
		string character, theme;
		if (settings.is_open())
		{
			getline(settings, character);
			getline(settings, theme);


			if (character == "female")
			{
				frameNum = theme == "light" ? 0 : 1;
			}
			if (character == "male")
			{
				frameNum = theme == "light" ? 2 : 3;
			}

		}
		settings.close();

		settings.open("../assets/data/settings.txt", ios::out);
		if (settings.is_open())
		{
			if (CheckCollisionPointRec(mouse, { 391, 580, 202, 119 }) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				if (character == "male")
				{
					character = "female";
					frameNum = theme == "light" ? 0 : 1;
				}
				else if (character == "female")
				{
					character = "male";
					frameNum = theme == "light" ? 2 : 3;
				}
			}


			if (CheckCollisionPointRec(mouse, { 596, 346, 297, 107 }) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				SetMouseCursor(4);
				theme = "dark";
				frameNum = character == "female" ? 1 : 3;
			}

			if (CheckCollisionPointRec(mouse, { 596, 479, 297, 102 }) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				SetMouseCursor(4);
				theme = "light";
				frameNum = character == "female" ? 0 : 2;
			}
			settings << character + "\n" + theme;
		}
		settings.close();

		BeginDrawing();

		ClearBackground(theme == "light" ? Color{ 124, 164, 200 } : Color{ 103, 89, 113 });
		
		DrawTextureRec(settingsMenu, 
					{ (float(settingsMenu.width) / 4) * frameNum, 0, float(settingsMenu.width / 4), float(settingsMenu.height) },
					{ 0, float(SCREEN_HEIGHT - settingsMenu.height) / 2 }, 
					WHITE);
		EndDrawing();
	}
}