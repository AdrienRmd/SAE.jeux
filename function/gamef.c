#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_manipulation.h"
#include <time.h>
#include <sys/stat.h>

int intro()
{
    FILE *intro = fopen('intro.txt', "r");

    print_line(intro, 1);
    char language;
    scanf("%c", &language);
    if (language == "f" || language == "F")
    {
        fclose(intro);
        return 0;
    }
    else
    {
        fclose(intro);
        return 1;
    }
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