#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include "other.h"
#include "monster_generation.h"

int random_number(int minimum, int maximum)
{ // automatiquement la graine aléatoire (srand(time(NULL))).
    static int initialized = 0;
    if (!initialized)
    {
        srand(time(NULL));
        initialized = 1;
    }
    return minimum + rand() % (maximum - minimum + 1);
}

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
            monster->table_loot = table_loot;

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