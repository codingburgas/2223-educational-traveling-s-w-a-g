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
int drawEnterPrompt(const char* message[3], int *promptChoice);
void drawComingSoonPrompt(Texture2D background, int* promptChoice, Color color, bool isBulgaria);
void lockOrUnlockCountry(int index, char lock_unlock);
string getCharacterFromSettings();
int startProgram();
