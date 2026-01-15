#ifndef MONSTER_GENERATION_H
#define MONSTER_GENERATION_H
#include "file_manipulation.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Rarity levels
#define RARITY_COMMON 0
#define RARITY_RARE 1
#define RARITY_VERY_RARE 2
#define RARITY_EPIC 3biome_buffer
#define RARITY_LEGENDARY 4
#define RARITY_MYTHIC 5

// Monster structure
typedef struct
{
    int id;        // Global unique ID (1, 2, 3, 4...)
    char name[40]; // Monster name
    int hp;        // Health points
    int att;       // Attack power
    int def;       // Defense value
    int dodge;     // Dodge chance
    int spe;       // Special/speed
    int luck;      // Luck stat
    int rarity;    // 0=common, 1=rare, 2=very rare, 3=epic, 4=legendary, 5=mythic
} Monster;

// Function to load monster stats based on selected language and monster ID
void set_monster(Monster *monster, const char *language, int monster_id);

#endif