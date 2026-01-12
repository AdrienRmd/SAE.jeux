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