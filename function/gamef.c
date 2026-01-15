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
 * Print intro text (first line of intro.txt) and read a single
 * character representing chosen language from stdin.
 * Returns: selected language as a `char`.
 */
char *intro()
{
    char string[100];
    value_line("intro.txt", 1, string, sizeof(string));
    if (choosing(string, 2) == 1)
    {
        return "fr";
    }
    return "en";
}

/*
 * add_stat
 * Read an integer value from `line` in `filename`, add `increment` to it,
 * and write updated value back to same line.
 * Parameters:
 *  - filename: path to file containing stat
 *  - line: line number to read and update
 *  - increment: amount to add to parsed integer
 */
void add_stat(char *filename, int line, int increment)
{
    char stat_str[12], buffer[128];
    value_line(filename, line, buffer, sizeof(buffer));
    int stat = atoi(buffer) + increment;
    snprintf(stat_str, sizeof(stat_str), "%d", stat);
    change_line(filename, line, stat_str);
}

/*
 * player_init
 * Initialize player data by prompting for choices (reads lines from
 * provided `filename`), writes initial stats into `player/player_info.txt`,
 * and applies class/race-based stat adjustments.
 * Parameters:
 *  - filename: path to file that contains interactive prompts
 */
void player_init(char *filename)
{
    for (int i = 1; i <= 17; i++)
    {
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
    for (int i = 6; i < 12; i++)
    {
        change_line("player/player_info.txt", i, "5");
    }
    change_line("player/player_info.txt", 12, "0");
    change_line("player/player_info.txt", 13, "0");

    char buffer[128];
    value_line("player/player_info.txt", 2, buffer, sizeof(buffer));
    if (strcmp(buffer, "2") == 0)
    {
        change_line("player/player_info.txt", 6, "7");
        change_line("player/player_info.txt", 7, "7");
        change_line("player/player_info.txt", 8, "3");
        change_line("player/player_info.txt", 9, "3");
    }
    else if (strcmp(buffer, "3") == 0)
    {
        change_line("player/player_info.txt", 6, "3");
        change_line("player/player_info.txt", 7, "3");
        change_line("player/player_info.txt", 8, "7");
        change_line("player/player_info.txt", 9, "7");
    }

    value_line("player/player_info.txt", 3, buffer, sizeof(buffer));

    if (strcmp(buffer, "1") == 0)
    {
        add_stat("player/player_info.txt", 6, 2);
        add_stat("player/player_info.txt", 7, 2);
    }
    else if (strcmp(buffer, "2") == 0)
    {
        add_stat("player/player_info.txt", 8, 2);
        add_stat("player/player_info.txt", 9, 2);
    }
    else
    {
        add_stat("player/player_info.txt", 6, 2);
        add_stat("player/player_info.txt", 9, 2);
    }

    change_line("player/player_info.txt", 21, "1");
}

/*
 * choose_random_biome
 * Fill `biome` array with two distinct random biome IDs based on `floor`.
 * Parameters:
 *  - floor: current dungeon floor (affects biome ranges)
 *  - biome: output array of size >=2 to receive two biome IDs
 */
void choose_random_biome(int floor, int *biome)
{

    int random;
    biome[0] = 0;

    for (int i = 0; i < 2; i++)
    {
        if (floor == 1 || floor == 2)
        {
            random = random_number(1, 5);
        }
        else if (floor == 3 || floor == 4)
        {
            random = random_number(6, 10);
        }
        else if (floor == 5 || floor == 6)
        {
            random = random_number(11, 15);
        }
        else
        {
            random = random_number(16, 20);
        }
        biome[i] = random;
    }
    while (biome[0] == biome[1])
    {
        if (floor == 1 || floor == 2)
        {
            random = random_number(1, 5);
        }
        else if (floor == 3 || floor == 4)
        {
            random = random_number(6, 10);
        }
        else if (floor == 5 || floor == 6)
        {
            random = random_number(11, 15);
        }
        else
        {
            random = random_number(16, 20);
        }
        biome[1] = random;
    }
}

/*
 * choose_biome
 * Present two biome names (loaded from language-specific biome file) to
 * player and prompt for a choice. Returns selected biome ID.
 * Parameters:
 *  - biome: array containing two biome IDs
 *  - lang: path prefix for localization (used to locate biome file)
 * Returns: chosen biome ID (one of biome[0] or biome[1])
 */
int choose_biome(int *biome, const char *lang)
{

    int choice = -1;
    char filepath[100];
    char biome1[100], biome2[100];

    // Clear input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    sprintf(filepath, "%s/biomes/biome.txt", lang);
    value_line(filepath, 10 * (biome[0] - 1) + 2, biome1, sizeof(biome1));
    value_line(filepath, 10 * (biome[1] - 1) + 2, biome2, sizeof(biome2));
    printf("Quel biome voulez-vous explorer ?\n");

    while (choice != 1 && choice != 2)
    {
        printf("1 - %s / 2 - %s : ", biome1, biome2);
        fflush(stdout);
        int result = scanf("%d", &choice);
        while (getchar() != '\n')
            ;

        if (result != 1 || (choice != 1 && choice != 2))
        {
            printf("Choix invalide. Veuillez entrer 1 ou 2.\n");
            choice = -1;
        }
    }

    if (choice == 1)
    {
        return biome[0];
    }
    else
    {
        return biome[1];
    }
}

/*
 * player_attack
 * Execute a player attack against a monster. Checks for monster dodge chance,
 * calculates damage if attack hits, displays appropriate messages, and reduces
 * monster HP.
 * Parameters:
 *  - player: Player struct containing attack stats
 *  - monster: Monster struct being attacked
 *  - lang: path prefix for localization (used to locate text file)
 */
void player_attack(Player *player, Monster *monster, const char *lang)
{
    if (random_number(1, 100) <= monster->dodge)
    {
        char filepath[100];
        sprintf(filepath, "%s/text.txt", lang);
        print_line(filepath, 15);
    }
    else
    {
        int damage = player->att - monster->def;
        char *damage_str = int_to_string(damage);
        strcat(damage_str, " HP");
        char filepath[100];
        sprintf(filepath, "%s/text.txt", lang);
        print_line(filepath, 13);
        print_line(filepath, 14);
        printf("%s\n", damage_str);
        monster->hp -= damage;
        add_stat("player/player_info.txt", 5, -damage);
    }
}

/*
 * monster_attack
 * Execute a monster attack against a player. Checks for player dodge chance,
 * calculates damage if attack hits, displays appropriate messages, and reduces
 * player HP.
 * Parameters:
 *  - player: Player struct being attacked
 *  - monster: Monster struct containing attack stats
 *  - lang: path prefix for localization (used to locate text file)
 */
void monster_attack(Player *player, Monster *monster, const char *lang)
{
    if (random_number(1, 100) <= player->dodge)
    {
        char filepath[100];
        sprintf(filepath, "%s/text.txt", lang);
        print_line(filepath, 18);
    }
    else
    {
        int damage = monster->att - player->def;
        char *damage_str = int_to_string(damage);
        strcat(damage_str, " HP");
        char filepath[100];
        sprintf(filepath, "%s/text.txt", lang);
        print_line(filepath, 16);
        print_line(filepath, 17);
        printf("%s\n", damage_str);
        player->hp -= damage;
        add_stat("player/player_info.txt", 5, -damage);
    }
}

/*
 * battle
 * Execute a turn-based battle between player and monster. Determines attack
 * order based on speed stat and continues until either player or monster
 * reaches 0 HP.
 * Parameters:
 *  - player: Player struct participating in battle
 *  - monster: Monster struct participating in battle
 *  - lang: path prefix for localization (passed to attack functions)
 */
void battle(Player *player, Monster *monster, const char *lang)
{
    char filepath[100];
    sprintf(filepath, "%s/text.txt", lang);
    print_line(filepath, 37);
    printf("%s\n", monster->name);
    while (player->hp > 0 && monster->hp > 0)
    {
        if (player->spe > monster->spe)
        {
            player_attack(player, monster, lang);
            if (monster->hp > 0)
            {
                monster_attack(player, monster, lang);
            }
        }
        else
        {
            monster_attack(player, monster, lang);
            if (player->hp > 0)
            {
                player_attack(player, monster, lang);
            }
        }
    }
}

void afficher_biome(int id_biome, const char *filepath)
{
    int pointeur_debut = id_biome * 2 - 1;
    int pointeur_fin = id_biome * 2;
    int ligne;

    for (ligne = pointeur_debut; ligne <= pointeur_fin; ligne++)
    {
        print_line(filepath, ligne);
        printf("\n");
    }
}

void set_player(Player *player)
{
    char player_buffer[128];
    value_line("player/player_info.txt", 1, player_buffer, sizeof(player_buffer));
    strcpy(player->name, player_buffer);
    value_line("player/player_info.txt", 5, player_buffer, sizeof(player_buffer));
    player->hp = atoi(player_buffer);
    value_line("player/player_info.txt", 6, player_buffer, sizeof(player_buffer));
    player->att = atoi(player_buffer);
    value_line("player/player_info.txt", 7, player_buffer, sizeof(player_buffer));
    player->def = atoi(player_buffer);
    value_line("player/player_info.txt", 8, player_buffer, sizeof(player_buffer));
    player->spe = atoi(player_buffer);
    value_line("player/player_info.txt", 9, player_buffer, sizeof(player_buffer));
    player->dodge = atoi(player_buffer);
}

int get_monster_id(int biome_id, const char *lang)
{
    char filepath[100], buffer[10];
    sprintf(filepath, "%s/monstre/monster.txt", lang);
    value_line(filepath, 30 * (biome_id - 1) + 1 + random_number(0, 2) * 10, buffer, sizeof(buffer));
    return atoi(buffer);
}

void set_monster(Monster *monster, const char *language, int monster_id)
{
    char monster_buffer[128];
    char filename[256];
    int current_line = 1;
    int found = 0;

    sprintf(filename, "%s/monstre/monster.txt", language);

    // Search for the monster by checking each block of 9 lines
    while (!found && current_line < 1000)
    {
        // Try to read ID from current position
        if (value_line(filename, current_line, monster_buffer, sizeof(monster_buffer)))
        {
            int found_id = atoi(monster_buffer);

            if (found_id == monster_id)
            {
                // Found the correct monster, load its data
                found = 1;
                monster->id = monster_id;

                // Load the remaining 8 lines of monster data
                value_line(filename, current_line + 1, monster_buffer, sizeof(monster_buffer));
                strcpy(monster->name, monster_buffer);

                value_line(filename, current_line + 2, monster_buffer, sizeof(monster_buffer));
                monster->hp = atoi(monster_buffer);

                value_line(filename, current_line + 3, monster_buffer, sizeof(monster_buffer));
                monster->att = atoi(monster_buffer);

                value_line(filename, current_line + 4, monster_buffer, sizeof(monster_buffer));
                monster->def = atoi(monster_buffer);

                value_line(filename, current_line + 5, monster_buffer, sizeof(monster_buffer));
                monster->dodge = atoi(monster_buffer);

                value_line(filename, current_line + 6, monster_buffer, sizeof(monster_buffer));
                monster->spe = atoi(monster_buffer);

                value_line(filename, current_line + 7, monster_buffer, sizeof(monster_buffer));
                monster->luck = atoi(monster_buffer);

                value_line(filename, current_line + 8, monster_buffer, sizeof(monster_buffer));
                monster->rarity = atoi(monster_buffer);
            }
            else
            {
                // Move to next monster (skip 9 lines, but check for empty line)
                current_line += 10;
            }
        }
        else
        {
            // Can't read from file, break
            break;
        }
    }
}

void set_biome(Biome *biome, const char *language, int biome_id)
{
    char biome_buffer[128];
    char filename[256];
    int current_line = 1;
    int found = 0;

    sprintf(filename, "%s/biomes/biome.txt", language);

    // Search for the monster by checking each block of 9 lines
    while (!found && current_line < 1000)
    {
        // Try to read ID from current position
        if (value_line(filename, current_line, biome_buffer, sizeof(biome_buffer)))
        {
            int found_id = atoi(biome_buffer);

            if (found_id == biome_id)
            {
                // Found the correct biome, load its data
                found = 1;
                biome->id_biome = biome_id;

                // Load the remaining 8 lines of biome data

                value_line(filename, current_line + 1, biome_buffer, sizeof(biome_buffer));
                biome->description = atoi(biome_buffer);

                value_line(filename, current_line + 2, biome_buffer, sizeof(biome_buffer));
                biome->difficulty_biome = atoi(biome_buffer);

                value_line(filename, current_line + 3, biome_buffer, sizeof(biome_buffer));
                biome->minimum_temperature = atoi(biome_buffer);

                value_line(filename, current_line + 4, biome_buffer, sizeof(biome_buffer));
                biome->maximum_temperature = atoi(biome_buffer);

                value_line(filename, current_line + 5, biome_buffer, sizeof(biome_buffer));
                biome->minimum_meteo = atoi(biome_buffer);

                value_line(filename, current_line + 6, biome_buffer, sizeof(biome_buffer));
                biome->maximum_meteo = atoi(biome_buffer);
            }
            else
            {
                // Move to next biome (skip 9 lines, but check for empty line)
                current_line += 10;
            }
        }
        else
        {
            // Can't read from file, break
            break;
        }
    }
}
int ongoing_floor(const char *lang, int biome_id, int floor)
{
    Monster monster;
    Biome biome;
    Player player;

    set_player(&player);

    /*generation_biome(&biome, biome_id, lang);

    sprintf(filepath, "%s/map.txt", lang);
    afficher_biome(biome.id_biome, filepath);*/

    char filepath[100];
    sprintf(filepath, "%s/text.txt", lang);
    // stat_monster_generation(&monster, lang, get_monster_id(biome_id, lang));
    char string[100];
    value_line(filepath, 38, string, sizeof(string));
    battle(&player, &monster, lang);

    if (player.hp <= 0)
    {
        // print_lose();
        change_line("player/player_info.txt", 21, "0");
        return -1;
    }
    else if (choosing(string, 2) == 1)
    {
        set_player(&player);
        // stat_monster_generation(&monster, lang, get_monster_id(biome_id, lang));
        battle(&player, &monster, lang);
        if (player.hp <= 0)
        {
            change_line("player/player_info.txt", 21, "0");
            return -1;
        }
        else if (choosing(string, 2) == 1)
        {
            // stat_monster_generation(&monster, lang, get_monster_id(biome_id, lang));
            battle(&player, &monster, lang);
            if (player.hp <= 0)
            {
                change_line("player/player_info.txt", 21, "0");
                return -1;
            }
            print_line(filepath, 40);
        }
    }
    if (floor < 9)
    {
        int biomes[2];
        choose_random_biome(floor, biomes);
        return choose_biome(biomes, lang);
    }

    return 0;
}