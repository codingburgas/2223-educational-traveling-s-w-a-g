#pragma once

#define MAP_H_INCLUDED

#define SCREEN_HEIGHT 828
#define SCREEN_WIDTH 924
#define SCREEN_TITLE "Balkan.X"

#include <string>
using std::string;

void drawMap();
void drawSettingsMenu();

void drawLossPrompt(int* promptChoice);
void drawWinPrompt(const char* message[3]);
void markCountryAsVisited(int index); 
string getCharacterFromSettings();