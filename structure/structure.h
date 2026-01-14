#ifndef STRUCTURE_H
#define STRUCTURE_H

typedef struct
{
    char name[20];
    char race[10];
    int hp;
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
    int id;                // Monster ID
    char name[50];         // Monster name
    int health;            // Current health points
    int max_health;        // Maximum health points
    int attack_power;      // Attack power
    int defense;           // Defense value
    int speed;             // Speed/initiative
    int experience_reward; // Experience given when defeated
    int gold_reward;       // Gold given when defeated
    int rarity;            // Rarity level (0=common, 1=rare, etc.)
} Monster;

#endif