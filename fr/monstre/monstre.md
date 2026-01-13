typedef structgit status
{
    int id;         // Global unique ID (1, 2, 3, 4...)
    char name[40];  // Monster name
    int pv;         // Health points
    int att;        // Attack power
    int def;        // Defense value
    int dodge;      // Dodge chance
    int spe;        // Special/speed
    int luck;       // Luck stat
    int rarity;     // 0=common, 1=rare, 2=very rare, 3=epic, 4=legendary, 5=mythic
    int table_loot; // Keep for backward compatibility
} Monster;

les monstres se font par biome ( 3 par biome)

plus l'id est elevé plus le monstre est fort
