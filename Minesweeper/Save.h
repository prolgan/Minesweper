#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED

#include <iostream>
#include "Game.h"
using namespace std;


void saveMenu(Game);
void SaveGame(Game,string);
Game ReadGame(string);
bool nosaukumuparbaude(string);
Game unsaveMenu();
void dirSave();

#endif // SAVE_H_INCLUDED
