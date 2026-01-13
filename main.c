#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include "function/gamef.h"

const int NB_FLOOR = 10;

int main()
{
    char language = intro();
    int floor = 0;
    int *biome[2];
    int biome_chosen = random_number(1, 5);

    if (language == 'f' || language == 'F')
    {   
        language = 'fr';
        player_init("fr/intro-FR.txt");


        for (floor = 1 ; floor < NB_FLOOR ; floor++){
            ongoing_floor(language, biome_chosen, floor);
            choose_random_biome(floor, biome);
            choose_biome(biome, language);
        }

        final_floor(language);
    }
    else if (language == 'e' || language == 'E')
    {
        language = 'en';
        player_init("en/intro-EN.txt");

        for (floor = 1 ; floor < NB_FLOOR ; floor++){
            ongoing_floor(language, biome_chosen, floor);
            choose_random_biome(floor, biome);
            choose_biome(biome, language);
        }

        final_floor(language);
    }

    return 0;
}
