#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include "file_manipulation.h"
#include "../structure/structure.h"
#include "other.h"
#include "monster_generation.h"

void choose_random_biome(int floor, int *biome);

int choose_biome(int *biome, const char *lang);

char *intro();

void player_init(char *filename);

void add_stat(char *filename, int line, int increment);

void battle(Player player, Monster monster, const char *lang);

int ongoing_floor(const char *lang, int biome, int floor);

void final_floor(const char *lang);

#endif