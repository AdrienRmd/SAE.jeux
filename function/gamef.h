#ifndef GAME_H
#define GAME_H
#include "../structure/structure.h"

char intro();

void player_init(char *filename);

/*void battle(Player player, Monster monster, int lang);*/

int ongoing_floor(char lang, int biome, int floor);

void final_floor(char lang);

#endif