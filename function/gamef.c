#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_manipulation.h"
#include <time.h>
#include <sys/stat.h>
#include "gamef.h"

char intro()
{
    print_line("intro.txt", 1);
    char language;
    scanf("%c", &language);
    return language;
}


void player_init(char *filename)
{
    print_line(filename, 1);
    char choice[20];
    for (int i = 1; i <= 4; i++)
    {
        print_line(filename, i + 2);
        scanf("%c", choice);
        change_line("player/base_info.txt", i, choice);
    }

    print_line(filename, 8);
    print_line(filename, 9);
}

void choose_random_biome(int floor, int *biome){

    int random;

    for (int i = 0 ; i < 2 ; i++){
        if (random_number(0, 9) == 0 && biome[0] < 21){
            random = random_number(21, 25);
        }

        else if (floor == 1 || floor == 2){
            random = random_number(1, 5);
        }
        else if (floor == 3 || floor == 4){
            random = random_number(6, 10);
        }
        else if (floor == 5 || floor == 6){
            random = random_number(11, 15);
        }
        else {
            random = random_number(16, 20);
        }
        biome[i] = random;
    }
}

int choose_biome(int *biome){

    int choice;
    char *biome1 = 10 * (biome[0] - 1) + 2;
    char *biome2 = 10 * (biome[1] - 1) + 2;
    printf("Quel biome voulez-vous explorer ?");
    printf("1 - %c / 2 - %c : ", biome1, biome2);
    scanf("%d", &choice);
    if (choice == 1){
        return biome[0];
    }
    else{
        return biome[1];
    }
}

/*void battle(Player player, Monster monster, int lang){
    while (player.pv > 0 && monster.pv > 0){
        if (player.spe > monster.spe){
            combat_action(player, monster, lang);
            if (monster.pv > 0){
                monster_attack(player, monster, lang);
            }
        }
        else{
            monster_attack(player, monster, lang);
            if (player.pv > 0){
                combat_action(player, monster, lang);
            }
        }
    }
}*/