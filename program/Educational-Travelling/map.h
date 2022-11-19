#pragma once

#define MAP_H_INCLUDED

#define SCREEN_HEIGHT 828
#define SCREEN_WIDTH 924
#define SCREEN_TITLE "Balkan.X"

#include <string>
using std::string;

int drawMap();
int drawSettingsMenu();

void drawLossPrompt(int* promptChoice);
void drawWinPrompt(const char* message[3], int *promptChoice);
int drawEnterPrompt(const char* message[3]);
void ComingSoonPrompt(Texture2D background, int* promptChoice, Color color);
void markCountryAsVisited(int index);
string getCharacterFromSettings();
