#ifndef GEN_BIOME_H
#define GEN_BIOME_H

#include <stdbool.h>

// Temperature
typedef enum
{
    tres_froid = 1, // Coefficient 0.75 for stats
    froid = 2,      // Coefficient 0.90 for stats
    frais = 3,      // Coefficient 0.95 for stats
    tempere = 4,    // Coefficient 1.00 for stats
    chaud = 5,      // Coefficient 0.95 for stats
    tres_chaud = 6, // Coefficient 0.90 for stats
    brulant = 7     // Coefficient 0.75 for stats
} Temperature;

// Weather enum for biomes
typedef enum
{
    ensoleille = 1,        // Coefficient 1.00 for stats
    nuageux = 2,           // Coefficient 1.00 for stats
    pluie = 3,             // Coefficient 0.95 for stats
    brouillard = 4,        // Coefficient 0.90 for stats
    orage = 5,             // Coefficient 0.85 for stats
    vent_fort = 6,         // Coefficient 0.85 for stats
    neige = 7,             // Coefficient 0.80 for stats
    tempete = 8,           // Coefficient 0.75 for stats
    tempete_sable = 9,     // Coefficient 0.75 for stats
    tempete_de_neige = 10, // Coefficient 0.70 for stats
    blizzard = 11          // Coefficient 0.70 for stats
} Meteo;

// Commerce structure for biomes
typedef struct
{
    int nombre_consommable; // Number of consumables (random between 3 and 10)
    int nombre_objet;       // Number of objects (random between 5 and 20)
    float coeff_vente;      // Sale coefficient (random between 0.80 and 1.20)
} Commerce;

// Generic place
typedef struct
{
    int id_biome;                    // Unique biome identifier
    char *description;               // Detailed description
    float difficulty_biome;          // Difficulty coefficient (between 0.80 and 3.00)
    Temperature minimum_temperature; // Temperature type (affects stats)
    Temperature maximum_temperature; // Temperature type (affects stats)
    Meteo minimum_meteo;             // Weather type (affects stats)
    Meteo maximum_meteo;             // Weather type (affects stats)
} Biome;

// Merchant
typedef struct
{
    char *description;       // Detailed description
    Temperature temperature; // Temperature type (affects stats)
    Meteo meteo;             // Weather type (affects stats)
    Commerce commerce;       // For trading
    float difficulty_biome;  // Difficulty coefficient (between 0.80 and 3.00)
} Marchand;

// Casino game
typedef struct
{

} Jeux_casino;

// casino
typedef struct
{
    char *description;       // Detailed description
    Temperature temperature; // Temperature type (affects stats)
    Meteo meteo;             // Weather type (affects stats)
    Jeux_casino casino;      // For the casino
    float difficulty_biome;  // Difficulty coefficient (between 0.80 and 3.00)
} Casino;

// Enum of possible terrains
typedef enum
{
    // easy biomes
    plaine = 1,
    desert = 2,
    champ_de_fleur = 3,
    prairie = 4,
    banquise = 5,

    // medium biomes
    lac = 6,
    marais = 7,
    canyon = 8,
    jungle = 9,
    mer = 10,

    // hard biomes
    prairie_volcanique = 11,
    foret_noire = 12,
    prairie_demoniaque = 13,
    marais_sombres = 14,
    montagne = 15,

    // special mining biomes
    volcan = 16,
    foret = 17,
    grotte = 18,
    village = 19,
    mine = 20,

    // special places
    salle_coffre = 21,
    marché = 22,
    ruines = 23,
    casino = 24,
    salle_coffre_legend = 25,
} Terrain;

#endif