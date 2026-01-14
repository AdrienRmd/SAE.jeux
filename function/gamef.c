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
        change_line("player/player_info.txt", i, choice);
    }
    change_line("player/player_info.txt", 5, 10);
    for (int i = 6 ; i < 12 ; i++){
        change_line("player/player_info", i, 1);
    }
    change_line("player/player_info.txt", 12, 0);
    change_line("player/player_info.txt", 13, 0);

    print_line(filename, 8);
    print_line(filename, 9);
}

void choose_random_biome(int floor, int *biome){

    int random;
    biome[0] = 0;

    for (int i = 0 ; i < 2 ; i++){
        if (floor == 1 || floor == 2){
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
    while (biome[0] == biome[1]){
        if (floor == 1 || floor == 2){
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
        biome[1] = random;
    }
    
}

int choose_biome(int *biome, const char *lang){

    int choice = -1;
    char filepath[100];
    char biome1[100], biome2[100];
    
    // Clear input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    sprintf(filepath, "%s/biomes/biome.txt", lang);
    value_line(filepath, 10 * (biome[0] - 1) + 2, biome1, sizeof(biome1));
    value_line(filepath, 10 * (biome[1] - 1) + 2, biome2, sizeof(biome2));
    printf("Quel biome voulez-vous explorer ?\n");
    
    while (choice != 1 && choice != 2) {
        printf("1 - %s / 2 - %s : ", biome1, biome2);
        fflush(stdout);
        int result = scanf("%d", &choice);
        while (getchar() != '\n');
        
        if (result != 1 || (choice != 1 && choice != 2)) {
            printf("Choix invalide. Veuillez entrer 1 ou 2.\n");
            choice = -1;
        }
    }
    
    if (choice == 1){
        return biome[0];
    }
    else{
        return biome[1];
    }
}

/*void battle(Player player, Monster monster, int lang){
    while (player.hp > 0 && monster.hp > 0){
        if (player.spe > monster.spe){
            combat_action(player, monster, lang);
            if (monster.hp > 0){
                monster_attack(player, monster, lang);
            }
        }
        else{
            monster_attack(player, monster, lang);
            if (player.hp > 0){
                combat_action(player, monster, lang);
            }
        }
    }
}*/