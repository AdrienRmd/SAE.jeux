#ifndef MONSTER_GENERATION_H
#define MONSTER_GENERATION_H
#include "function/file_manipulation.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Rarity levels
#define RARITY_COMMON 0
#define RARITY_RARE 1
#define RARITY_VERY_RARE 2
#define RARITY_EPIC 3
#define RARITY_LEGENDARY 4
#define RARITY_MYTHIC 5

// Monster structure
typedef struct
{
    int id;        // Global unique ID (1, 2, 3, 4...)
    char name[40]; // Monster name
    int pv;        // Health points
    int att;       // Attack power
    int def;       // Defense value
    int dodge;     // Dodge chance
    int spe;       // Special/speed
    int luck;      // Luck stat
    int rarity;    // 0=common, 1=rare, 2=very rare, 3=epic, 4=legendary, 5=mythic
} Monster;

// Function to load monster stats based on selected language and monster ID
void stat_monster_generation(Monster *monster, char langue_selectionne, int id_monster)
{
    int verification_id = 0;
    int numero_ligne = 1; // Start at line 1

    // Check les line 1, 11, 21, 31, etc.
    while (verification_id != 1 && numero_ligne <= 1000)
    {
        char buffer[40];

        // selection le nom par rapport a la langue
        if (langue_selectionne == 'F')
            value_line("../fr/monstre/monster.txt", numero_ligne, buffer, sizeof(buffer));
        else
            value_line("../en/monster/monster.txt", numero_ligne, buffer, sizeof(buffer));

        // Extraction des données depuis la ligne lue
        int id;
        char name[40];
        int pv, att, def, dodge, spe, luck, rarity, table_loot;

        int parsed = sscanf(buffer, "%d;%39[^;];%d;%d;%d;%d;%d;%d;%d;%d",
                            &id, name, &pv, &att, &def, &dodge, &spe, &luck, &rarity, &table_loot);

        // recupere les stat du monstre avec l'id correspondant
        if (parsed == 10 && id == id_monster) // Check if parsing succeeded and ID matches
        {
            monster->id = id;
            snprintf(monster->name, sizeof(monster->name), "%s", name);
            monster->pv = pv;
            monster->att = att;
            monster->def = def;
            monster->dodge = dodge;
            monster->spe = spe;
            monster->luck = luck;
            monster->rarity = rarity;

            verification_id = 1; // ID trouvé
        }
        else
        {
            verification_id = 0; // ID non trouvé, continuer la recherche
            numero_ligne += 10;  // Passer à la ligne suivante pour le prochain monstre
        }
    }

    if (verification_id != 1)
    {
        // ID non trouvé après avoir parcouru le fichier
        printf("impossible de trouver le monstre avec l'ID %d\n", id_monster);
    }
}

#endif