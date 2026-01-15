#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_manipulation.h"
#include <time.h>
#include <sys/stat.h>
#include "gamef.h"
#include "monster_generation.h"
#include "other.h"
#include "generation_biome.h"

/*
 * intro
 * Print the intro text (first line of intro.txt) and read a single
 * character representing the chosen language from stdin.
 * Returns: the selected language as a `char`.
 */
char *intro()
{
    char string[100];
    value_line("intro.txt", 1, string, sizeof(string));
    if (choosing(string, 2) == 1){
        return "fr";
    }
    return "en";
}

/*
 * add_stat
 * Read an integer value from `line` in `filename`, add `increment` to it,
 * and write the updated value back to the same line.
 * Parameters:
 *  - filename: path to the file containing the stat
 *  - line: line number to read and update
 *  - increment: amount to add to the parsed integer
 */
void add_stat(char *filename, int line, int increment){
    char stat_str[12], buffer[128];
    value_line(filename, line, buffer, sizeof(buffer));
    int stat = atoi(buffer) + increment;
    snprintf(stat_str, sizeof(stat_str), "%d", stat);
    change_line(filename, line, stat_str);
}


/*
 * player_init
 * Initialize player data by prompting for choices (reads lines from the
 * provided `filename`), writes initial stats into `player/player_info.txt`,
 * and applies class/race-based stat adjustments.
 * Parameters:
 *  - filename: path to the file that contains interactive prompts
 */
void player_init(char *filename)
{
    for (int i = 1 ; i <= 17 ; i++){
        print_line(filename, i);
        printf("\n");
    }
    
    char choice[20];
    print_line(filename, 18);
    scanf("%s", choice);
    change_line("player/player_info.txt", 1, choice);
    printf("\n");
    for (int i = 2; i <= 4; i++)
    {
        char string[100];
        value_line(filename, i + 17, string, sizeof(string));
        int choice_int = choosing(string, 3);
        change_line("player/player_info.txt", i, int_to_string(choice_int));
    }
    change_line("player/player_info.txt", 5, "100");
    for (int i = 6 ; i < 12 ; i++){
        change_line("player/player_info.txt", i, "5");
    }
    change_line("player/player_info.txt", 12, "0");
    change_line("player/player_info.txt", 13, "0");

    char buffer[128];
    value_line("player/player_info.txt", 2, buffer, sizeof(buffer));
    if (strcmp(buffer, "2") == 0){
        change_line("player/player_info.txt", 6, "7");
        change_line("player/player_info.txt", 7, "7");
        change_line("player/player_info.txt", 8, "3");
        change_line("player/player_info.txt", 9, "3");
    }
    else if (strcmp(buffer, "3") == 0){
        change_line("player/player_info.txt", 6, "3");
        change_line("player/player_info.txt", 7, "3");
        change_line("player/player_info.txt", 8, "7");
        change_line("player/player_info.txt", 9, "7");
    }

    value_line("player/player_info.txt", 3, buffer, sizeof(buffer));

    if (strcmp(buffer, "1") == 0){
        add_stat("player/player_info.txt", 6, 2);
        add_stat("player/player_info.txt", 7, 2);
    }
    else if (strcmp(buffer, "2") == 0){
        add_stat("player/player_info.txt", 8, 2);
        add_stat("player/player_info.txt", 9, 2);
    }
    else{
        add_stat("player/player_info.txt", 6, 2);
        add_stat("player/player_info.txt", 9, 2);
    }

    print_line(filename, 8);
    print_line(filename, 9);
}

/*
 * choose_random_biome
 * Fill `biome` array with two distinct random biome IDs based on `floor`.
 * Parameters:
 *  - floor: current dungeon floor (affects biome ranges)
 *  - biome: output array of size >=2 to receive two biome IDs
 */
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

/*
 * choose_biome
 * Present two biome names (loaded from language-specific biome file) to
 * the player and prompt for a choice. Returns the selected biome ID.
 * Parameters:
 *  - biome: array containing two biome IDs
 *  - lang: path prefix for localization (used to locate biome file)
 * Returns: the chosen biome ID (one of biome[0] or biome[1])
 */
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

/*
 * player_attack
 * Execute a player attack against a monster. Checks for monster dodge chance,
 * calculates damage if attack hits, displays appropriate messages, and reduces
 * monster HP.
 * Parameters:
 *  - player: the Player struct containing attack stats
 *  - monster: the Monster struct being attacked
 *  - lang: path prefix for localization (used to locate text file)
 */
void player_attack(Player player, Monster monster, const char *lang){
    if (random_number(1, 100) <= monster.dodge){
        char filepath[100];
        sprintf(filepath, "%s/text.txt", lang);
        print_line(filepath, 15);
    }
    else {
        int damage = player.att - monster.def;
        char *damage_str = int_to_string(damage);
        strcat(damage_str, " HP");
        char filepath[100];
        sprintf(filepath, "%s/text.txt", lang);
        print_line(filepath, 13);
        print_line(filepath, 14);
        printf("%s\n", damage_str);
        monster.hp -= damage;
    }
}

/*
 * monster_attack
 * Execute a monster attack against the player. Checks for player dodge chance,
 * calculates damage if attack hits, displays appropriate messages, and reduces
 * player HP.
 * Parameters:
 *  - player: the Player struct being attacked
 *  - monster: the Monster struct containing attack stats
 *  - lang: path prefix for localization (used to locate text file)
 */
void monster_attack(Player player, Monster monster, const char *lang){
    if (random_number(1, 100) <= player.dodge){
        char filepath[100];
        sprintf(filepath, "%s/text.txt", lang);
        print_line(filepath, 18);
    }
    else {
        int damage = monster.att - player.def;
        char *damage_str = int_to_string(damage);
        strcat(damage_str, " HP");
        char filepath[100];
        sprintf(filepath, "%s/text.txt", lang);
        print_line(filepath, 16);
        print_line(filepath, 17);
        printf("%s\n", damage_str);
        player.hp -= damage;
    }
}


/*
 * battle
 * Execute a turn-based battle between player and monster. Determines attack
 * order based on speed stat and continues until either the player or monster
 * reaches 0 HP.
 * Parameters:
 *  - player: the Player struct participating in battle
 *  - monster: the Monster struct participating in battle
 *  - lang: path prefix for localization (passed to attack functions)
 */
void battle(Player player, Monster monster, const char *lang){
    while (player.hp > 0 && monster.hp > 0){
        if (player.spe > monster.spe){
            player_attack(player, monster, lang);
            if (monster.hp > 0){
                monster_attack(player, monster, lang);
            }
        }
        else{
            monster_attack(player, monster, lang);
            if (player.hp > 0){
                player_attack(player, monster, lang);
            }
        }
    }
}

void stat_monster_generation(Monster *monster, char langue_selectionne, int id_monster)
{
    int verification_id = 0;
    int numero_ligne = 1; // Start at line 1

    // Check les line 1, 11, 21, 31, etc.
    while (verification_id != 1 && numero_ligne <= 1000)
    {
        char buffer[40];

        // selection le nom par rapport a la langue
        if (langue_selectionne == 'F')
            value_line("../fr/monstre/monster.txt", numero_ligne, buffer, sizeof(buffer));
        else
            value_line("../en/monster/monster.txt", numero_ligne, buffer, sizeof(buffer));

        // Extraction des données depuis la ligne lue
        int id;
        char name[40];
        int hp, att, def, dodge, spe, luck, rarity, table_loot;

        int parsed = sscanf(buffer, "%d;%39[^;];%d;%d;%d;%d;%d;%d;%d;%d",
                            &id, name, &hp, &att, &def, &dodge, &spe, &luck, &rarity, &table_loot);

        // recupere les stat du monstre avec l'id correspondant
        if (parsed == 10 && id == id_monster) // Check if parsing succeeded and ID matches
        {
            monster->id = id;
            snprintf(monster->name, sizeof(monster->name), "%s", name);
            monster->hp = hp;
            monster->att = att;
            monster->def = def;
            monster->dodge = dodge;
            monster->spe = spe;
            monster->luck = luck;
            monster->rarity = rarity;

            verification_id = 1; // ID trouvé
        }
        else
        {
            verification_id = 0; // ID non trouvé, continuer la recherche
            numero_ligne += 10;  // Passer à la ligne suivante pour le prochain monstre
        }
    }

    if (verification_id != 1)
    {
        // ID non trouvé après avoir parcouru le fichier
        printf("impossible de trouver le monstre avec l'ID %d\n", id_monster);
    }
}

int ongoing_floor(const char *lang, int biome_id, int floor){
    Monster *monster;
    Biome biome;
    int monster_id;

    
    stat_monster_generation(monster, lang, monster_id);
}