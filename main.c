#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include "function/gamef.h"
#include "function/file_manipulation.h"

const int NB_FLOOR = 10;

int main()
{
    char lang[3] = intro();
    int floor = 1;
    int biome[2], choosen_biome;


    char filepath[100];
    sprintf(filepath, "%s/text.txt", lang);
    player_init(filepath);

    //Test choix biome
    choose_random_biome(floor, biome);
    choosen_biome = choose_biome(biome, lang);

    for (floor ; floor < 10 ; floor++){
        ongoing_floor(lang, choosen_biome, floor);
    }
    
    return 0;
}
