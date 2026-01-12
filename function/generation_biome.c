// structures des biomes

// biome facile
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

// biomes moyens - lac
typedef struct
{
    int difficulty_biome;

} lac;

// biomes moyens - marais
typedef struct
{
    int difficulty_biome;

} marais;

// biomes moyens - canyon
typedef struct
{
    int difficulty_biome;

} canyon;

// biomes moyens - jungle
typedef struct
{
    int difficulty_biome;

} jungle;

// biomes moyens - mer
typedef struct
{
    int difficulty_biome;

} mer;

// biomes durs - prairie_volcanique
typedef struct
{
    int difficulty_biome;
    int temperature;      // Temperature of the volcanic area
    int lava_level;       // Level of lava activity (1-10)
    int eruption_risk;    // Risk of eruption (percentage)
    int mineral_richness; // Richness of volcanic minerals
    int toxic_fumes;      // Level of toxic gases in the air

} prairie_volcanique;

// biomes durs - foret_noire
typedef struct
{
    int difficulty_biome;

} foret_noire;

// biomes durs - prairie_demoniaque
typedef struct
{
    int difficulty_biome;

} prairie_demoniaque;

// biomes durs - marais_sombres
typedef struct
{
    int difficulty_biome;

} marais_sombres;

// montagne
typedef struct
{
    int difficulty_biome;

} montagne;

// biomes marches spéciaux - volcan
typedef struct
{
    int difficulty_biome;

} volcan;

// foret
typedef struct
{
    int difficulty_biome;

} foret;

// biomes marches spéciaux - grotte
typedef struct
{
    int difficulty_biome;

} grotte;

// biomes marches spéciaux - village
typedef struct
{
    int difficulty_biome;

} village;

// biomes marches spéciaux - mine
typedef struct
{
    int difficulty_biome;

} mine;

// coffre
typedef struct
{
    int difficulty_biome;

} salle_coffre;

// lieux spéciaux - marché
typedef struct
{
    int difficulty_biome;

} marché;

// lieux spéciaux - ruines
typedef struct
{
    int difficulty_biome;

} ruines;

// lieux spéciaux - casino
typedef struct
{
    int difficulty_biome;

} casino;

// lieux spéciaux - salle_coffre_legend
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
