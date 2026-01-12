#ifndef GEN_BIOME_H
#define GEN_BIOME_H

// biome facile

// plaine
typedef struct
{
    int difficulty_biome;
} plaine;

// desert
typedef struct
{
    int difficulty_biome;
} desert;

// champ_de_fleur
typedef struct
{
    int difficulty_biome;
} champ_de_fleur;

// prairie
typedef struct
{
    int difficulty_biome;
} prairie;

// banquise
typedef struct
{
    int difficulty_biome;
} banquise;

// biomes moyens

// lac
typedef struct
{
    int difficulty_biome;
} lac;

// marais
typedef struct
{
    int difficulty_biome;
} marais;

// canyon
typedef struct
{
    int difficulty_biome;
} canyon;

// jungle
typedef struct
{
    int difficulty_biome;
} jungle;

// mer
typedef struct
{
    int difficulty_biome;
} mer;

// biomes durs

// prairie_volcanique
typedef struct
{
    int difficulty_biome;
} prairie_volcanique;

// foret_noire
typedef struct
{
    int difficulty_biome;
} foret_noire;

// prairie_demoniaque
typedef struct
{
    int difficulty_biome;
} prairie_demoniaque;

// marais_sombres
typedef struct
{
    int difficulty_biome;
} marais_sombres;

// montagne
typedef struct
{
    int difficulty_biome;
} montagne;

// biomes marches spéciaux

// volcan
typedef struct
{
    int difficulty_biome;
} volcan;

// foret
typedef struct
{
    int difficulty_biome;
} foret;

// grotte
typedef struct
{
    int difficulty_biome;
} grotte;

// village
typedef struct
{
    int difficulty_biome;
} village;

// mine
typedef struct
{
    int difficulty_biome;
} mine;

// lieux spéciaux

// salle_coffre
typedef struct
{
    int difficulty_biome;
} salle_coffre;

// marché
typedef struct
{
    int difficulty_biome;
} marché;

// ruines
typedef struct
{
    int difficulty_biome;
} ruines;

// casino
typedef struct
{
    int difficulty_biome;
} casino;

// salle_coffre_legend
typedef struct
{
    int difficulty_biome;
} salle_coffre_legend;

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

    // biomes marches spéciaux
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