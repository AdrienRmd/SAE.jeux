#ifndef STRUCTURE_H
#define STRUCTURE_H

/*
 * Player
 * Structure representing the player character with all stats and attributes.
 * Contains name, race, job/class, HP, combat stats (attack, defense, dodge,
 * speed, luck), experience, level, money, and difficulty multiplier.
 */
typedef struct
{
    char name[20];
    char race[10];
    int hp;
    int att;
    int def;
    int dodge;
    int spe;
    int luck;
    int exp;
    int lvl;
    char job[10];
    int money;
    float difficulty;
} Player;

// AJOUTER CES STRUCTURES :

/*
 * Monster
 * Structure representing a monster/enemy with its combat stats and attributes.
 * Contains ID, name, HP, attack, defense, dodge, speed, luck, and rarity level.
 */
typedef struct
{
    int id;
    char name[40];
    int hp;
    int att;
    int def;
    int dodge;
    int spe;
    int luck;
    int rarity;
} Monster;

/*
 * Temperature
 * Enumeration representing temperature levels from very cold to burning.
 * Used to define temperature ranges for biomes.
 */
typedef enum
{
    tres_froid = 1,
    froid = 2,
    frais = 3,
    tempere = 4,
    chaud = 5,
    tres_chaud = 6,
    brulant = 7
} Temperature;

/*
 * Meteo
 * Enumeration representing weather conditions from sunny to blizzard.
 * Used to define weather patterns for biomes.
 */
typedef enum
{
    ensoleille = 1,
    nuageux = 2,
    pluie = 3,
    brouillard = 4,
    orage = 5,
    vent_fort = 6,
    neige = 7,
    tempete = 8,
    tempete_sable = 9,
    tempete_de_neige = 10,
    blizzard = 11
} Meteo;

/*
 * Biome
 * Structure representing a biome/environment with its characteristics.
 * Contains ID, description, difficulty level, and temperature/weather ranges.
 */
typedef struct
{
    int id_biome;
    char description[256];
    float difficulty_biome;
    Temperature minimum_temperature;
    Temperature maximum_temperature;
    Meteo minimum_meteo;
    Meteo maximum_meteo;
} Biome;

// Niveaux de rareté des monstres
#define RARITY_COMMON 0
#define RARITY_RARE 1
#define RARITY_VERY_RARE 2
#define RARITY_EPIC 3
#define RARITY_LEGENDARY 4
#define RARITY_MYTHIC 5


#endif