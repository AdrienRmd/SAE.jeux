#ifndef GAME_H
#define GAME_H
#include "../structure/structure.h"

int intro();

void player_init(char filename);

void battle(Player player, Monster monster, int lang);

#endif