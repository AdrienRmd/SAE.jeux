#ifndef MONSTER_GENERATION_H
#define MONSTER_GENERATION_H
#include "function/file_manipulation.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;         // Global unique ID (1, 2, 3, 4...)
    char name[40];  // Monster name
    int hp;         // Health points
    int att;        // Attack power
    int def;        // Defense value
    int dodge;      // Dodge chance
    int spe;        // Special/speed
    int luck;       // Luck stat
    int rarity;     // 0=common, 1=rare, 2=very rare, 3=epic, 4=legendary, 5=mythic
    int table_loot; // Keep for backward compatibility
} Monster;

void stat_monster_generation(Monster *monster, char langue_selectionne, int id_monster);

#define RARITY_COMMON 0
#define RARITY_RARE 1
#define RARITY_VERY_RARE 2
#define RARITY_EPIC 3
#define RARITY_LEGENDARY 4
#define RARITY_MYTHIC 5

#endif