#ifndef GEN_BIOME_H
#define GEN_BIOME_H

#include <stdbool.h>

// temperature
typedef enum
{
    tres_froid = 1, // Coefficient 0.75 pour les stats
    froid = 2,      // Coefficient 0.90 pour les stats
    frais = 3,      // Coefficient 0.95 pour les stats
    tempere = 4,    // Coefficient 1.00 pour les stats
    chaud = 5,      // Coefficient 0.95 pour les stats
    tres_chaud = 6, // Coefficient 0.90 pour les stats
    brulant = 7     // Coefficient 0.75 pour les stats
} Temperature;

// Weather enum for biomes
typedef enum
{
    ensoleille = 1,        // Coefficient 1.00 pour les stats
    nuageux = 2,           // Coefficient 1.00 pour les stats
    pluie = 3,             // Coefficient 0.95 pour les stats
    brouillard = 4,        // Coefficient 0.90 pour les stats
    orage = 5,             // Coefficient 0.85 pour les stats
    vent_fort = 6,         // Coefficient 0.85 pour les stats
    neige = 7,             // Coefficient 0.80 pour les stats
    tempete = 8,           // Coefficient 0.75 pour les stats
    tempete_sable = 9,     // Coefficient 0.75 pour les stats
    tempete_de_neige = 10, // Coefficient 0.70 pour les stats
    blizzard = 11          // Coefficient 0.70 pour les stats
} Meteo;

// Commerce structure for biomes
typedef struct
{
    int nombre_consommable; // Nombre de consommables (aléatoire entre 3 et 10)
    int nombre_objet;       // Nombre d'objets (aléatoire entre 5 et 20)
    float coeff_vente;      // Coefficient de vente (aléatoire entre 0.80 et 1.20)
} Commerce;

// lieu générique
typedef struct
{
    int id_biome;                    // Identifiant unique du biome
    char *description;               // Description détaillée
    float difficulty_biome;          // Coefficient de difficulté (entre 0.80 et 3.00)
    Temperature minimum_temperature; // Type de température (affecte les stats)
    Temperature maximum_temperature; // Type de température (affecte les stats)
    Meteo minimum_meteo;             // Type de météo (joue sur les stats)
    Meteo maximum_meteo;             // Type de météo (joue sur les stats)
} Biome;

// marchand
typedef struct
{
    char *description;       // Description détaillée
    Temperature temperature; // Type de température (affecte les stats)
    Meteo meteo;             // Type de météo (joue sur les stats)
    Commerce commerce;       // Pour commercer
    float difficulty_biome;  // Coefficient de difficulté (entre 0.80 et 3.00)
} Marchand;

// jeu du casino
typedef struct
{

} Jeux_casino;

// casino
typedef struct
{
    char *description;       // Description détaillée
    Temperature temperature; // Type de température (affecte les stats)
    Meteo meteo;             // Type de météo (joue sur les stats)
    Jeux_casino casino;      // Pour le casino
    float difficulty_biome;  // Coefficient de difficulté (entre 0.80 et 3.00)
} Casino;

// enum des terrains possible
typedef enum
{
    // biomes faciles
    plaine = 1,
    desert = 2,
    champ_de_fleur = 3,
    prairie = 4,
    banquise = 5,

    // biomes moyens
    lac = 6,
    marais = 7,
    canyon = 8,
    jungle = 9,
    mer = 10,

    // biomes durs
    prairie_volcanique = 11,
    foret_noire = 12,
    prairie_demoniaque = 13,
    marais_sombres = 14,
    montagne = 15,

    // biomes minages spéciaux
    volcan = 16,
    foret = 17,
    grotte = 18,
    village = 19,
    mine = 20,

    // lieux spéciaux
    salle_coffre = 21,
    marché = 22,
    ruines = 23,
    casino = 24,
    salle_coffre_legend = 25,
} Terrain;

#endif