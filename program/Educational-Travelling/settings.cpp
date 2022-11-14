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

	fstream file;

	int frameNum = 0;

	while (!WindowShouldClose())
	{
		SetMouseCursor(0);
		Vector2 mouse = GetMousePosition();

		file.open("../assets/data/settings.txt", ios::in);
		string str[2];
		if (file.is_open())
		{
			int i = 0;
			
			while (i < 2)
			{
				getline(file, str[i]);
				i++;
			}

			if (str[0] == "female")
			{
				if (str[1] == "light")
					frameNum = 0;
				else if (str[1] == "dark")
					frameNum = 1;
			}
			if (str[0] == "male")
			{
				if (str[1] == "light")
					frameNum = 2;
				else if (str[1] == "dark")
					frameNum = 3;
			}

		}
		file.close();

		file.open("../assets/data/settings.txt", ios::out);
		if (file.is_open())
		{
			if (CheckCollisionPointRec(mouse, { 391, 580, 202, 119 }) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				if (str[0] == "male")
				{
					str[0] = "female";
					if (str[1] == "dark")
						frameNum = 1;

					else if (str[1] == "light")
						frameNum = 0;
				}
				else if (str[0] == "female")
				{
					str[0] = "male";
					if (str[1] == "dark")
						frameNum = 3;

					else if (str[1] == "light")
						frameNum = 2;
				}
			}


			if (CheckCollisionPointRec(mouse, { 596, 346, 297, 107 }) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				SetMouseCursor(4);
				str[1] = "dark";
				if (str[0] == "female")
					frameNum = 1;
				else if (str[0] == "male")
					frameNum = 3;
			}

			if (CheckCollisionPointRec(mouse, { 596, 479, 297, 102 }) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				SetMouseCursor(4);
				str[1] = "light";
				if (str[0] == "female")
					frameNum = 0;
				else if (str[0] == "male")
					frameNum = 2;

			}
			file << str[0] + "\n" + str[1];
		}
		file.close();

		BeginDrawing();

		ClearBackground(str[1] == "light" ? Color{ 124, 164, 200 } : Color{ 103, 89, 113 });
		
		DrawTextureRec(settingsMenu, 
					{ (float(settingsMenu.width) / 4) * frameNum, 0, float(settingsMenu.width / 4), float(settingsMenu.height) },
					{ 0, float(SCREEN_HEIGHT - settingsMenu.height) / 2 }, 
					WHITE);
		EndDrawing();
	}
}