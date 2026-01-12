#ifndef GESTION_FICHIERS_H
#define GESTION_FICHIERS_H

typedef struct
{
    char name[20];
    char race[10];
    int pv;
    int att;
    int def;
    int dodge;
    int spe;
    int exp;
    int lvl;
    char job[10];
    int money;
    float difficulty;

} player;

#endif