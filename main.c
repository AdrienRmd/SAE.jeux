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
    char language = intro();
    int floor = 1;
    int biome[2];
    char lang[3];

    if (language == 'f' || language == 'F'){
        strcpy(lang, "fr");
    }
    else{
        strcpy(lang, "en");
    }

    char filepath[100];
    sprintf(filepath, "%s/text.txt", lang);
    player_init(filepath);

    //Test choix biome
    choose_random_biome(floor, biome);
    printf("%d",choose_biome(biome, lang));

    //int biome_chosen = random_number(1, 5);
    
    /*
    if (language == 'f' || language == 'F')
    {   
        language = 'fr';
        player_init("fr/intro-FR.txt");


        for (floor = 1 ; floor < NB_FLOOR ; floor++){
            //ongoing_floor(language, biome_chosen, floor);
            choose_random_biome(floor, biome);
            choose_biome(biome);
        }

        //final_floor(language);
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

        //final_floor(language);
    }
*/
    return 0;
}
