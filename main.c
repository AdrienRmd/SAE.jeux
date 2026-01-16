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
    char lang[3], filepath[100];
    strncpy(lang, intro(), sizeof(lang) - 1);
    lang[sizeof(lang) - 1] = '\0';
    int floor = 1;
    int biome[2], chosen_biome;
    snprintf(filepath, sizeof(filepath), "%s/text.txt", lang);
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
    chosen_biome = choose_biome(biome, lang);

    for (floor = starting_floor; floor < NB_FLOOR; floor++)
    {
        chosen_biome = ongoing_floor(lang, chosen_biome, floor);
    }

    // final_boss();

    return 0;
}
