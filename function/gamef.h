#ifndef GAME_H
#define GAME_H
#include "../structure/structure.h"
#include "other.h"

void choose_random_biome(int floor, int *biome);

char intro();

void player_init(char *filename);

/*void battle(Player player, Monster monster, int lang);*/

void ongoing_floor(char lang, int biome, int floor);

void final_floor(char lang);

#endif