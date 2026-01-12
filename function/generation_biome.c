// structures des biomes

// plaines
typedef struct
{
    int difficulty_biome;

} plaine;

// desert
typedef struct
{
    int difficulty_biome;

} desert;

// foret
typedef struct
{
    int difficulty_biome;

} foret;

// montagne
typedef struct
{
    int difficulty_biome;

} montagne;

// coffre
typedef struct
{
    int difficulty_biome;

} salle_coffre;

// enum des terrains possible
typedef enum
{
    plaine = 1,
    desert = 2,
    champ_de_fleur = 3,
    prairie = 4,
    banquise = 5,

    lac = 6,
    marais = 7,
    canyon = 8,
    jungle = 9,
    mer = 10,

    volcan = 11,
    foret = 12,
    casino = 13,
    marché = 14,
    mine = 15,

    prairie_volcanique = 16,
    foret_noire = 17,
    prairie_demoniaque = 18,
    marais_sombres = 19,
    montagne = 20,

    salle_coffre = 21,
    ruines = 22,
    grotte = 23,

} Terrain;