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
    int biome = choose_random_biome();

    if (language == 'f' || language == 'F')
    {   
        language = 'fr';
        player_init("fr/intro-FR.txt");


        for (int floor = 1 ; floor < NB_FLOOR ; floor++){
            biome = ongoing_floor(language, biome, floor);
        }

        final_floor("%c/final.txt", language);
    }
    else if (language == 'e' || language == 'E')
    {
        language = 'en';
        player_init("en/intro-EN.txt");

        for (int floor = 1 ; floor < NB_FLOOR ; floor++){
            biome = ongoing_floor(language, biome, floor);
        }

        final_floor("%c/final.txt", language);
    }

    return 0;
}
