#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_manipulation.h"
#include <time.h>
#include <sys/stat.h>
#include "gamef.h"

char intro()
{
    FILE *intro = fopen('intro.txt', "r");

    print_line(intro, 1);
    char language;
    scanf("%c", &language);
    fclose(intro);
    return language;
}


void player_init(char filename)
{
    FILE *text = fopen(filename, "r");

    print_line(text, 1);
    char choice[20];
    for (int i = 1; i <= 4; i++)
    {
        print_line(text, i + 2);
        scanf("%s", &choice);
        change_line("player/base_info.txt", i, choice);
    }
    free(&choice);

    print_line(text, 8);
    print_line(text, 9);

    fclose(text);
}

void battle(Player player, Monster monster, int lang){
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
}