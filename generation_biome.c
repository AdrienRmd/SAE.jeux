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

} coffre;

// enum des terrains possible
typedef enum
{
    plaine = 1,
    desert = 2,
    foret = 3,
    montagne = 4,
    coffre = 5,

} Terrain;