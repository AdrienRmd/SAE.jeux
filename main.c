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
    char lang[3];
    strcpy(lang, intro());
    int floor = 1;
    int biome[2], choosen_biome;
    char filepath[100];
    sprintf(filepath, "%s/text.txt", lang);
    char save[10];
    value_line("player/player_info.txt", 21, save, sizeof(save));
    int starting_floor = 1;

    if (strcmp(save, "0")){
        char string[50];
        value_line(filepath, 42, string, sizeof(string));
        if(choosing(string, 2)){
            char buffer[10];
            value_line("player/player_info.txt", 20, buffer, sizeof(buffer));
            starting_floor = atoi(buffer);
        }
        else{
            player_init(filepath);
            starting_floor = 1;
        }
    }
    else{
        player_init(filepath);
        starting_floor = 1;
    }

    

    choose_random_biome(floor, biome);
    choosen_biome = choose_biome(biome, lang);

    for (floor = starting_floor; floor < NB_FLOOR; floor++)
    {
        choosen_biome = ongoing_floor(lang, choosen_biome, floor);
    }

    // final_boss();

    return 0;
}
