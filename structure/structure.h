#ifndef STRUCTURE_H
#define STRUCTURE_H

typedef struct
{
    char name[20];
    char race[10];
    int pv;
    int att;
    int def;
    int dodge;
    int spe;
    int luck;
    int exp;
    int lvl;
    char job[10];
    int money;
    float difficulty;
} Player;

typedef struct 
{
    char name[20];
    int pv;
    int att;
    int def;
    int dodge;
    int spe;
    int luck;
    char *table_loot[];
} Monster;

#endif