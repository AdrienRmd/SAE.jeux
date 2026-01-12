#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include "function/gamef.h"


int main()
{
    int language = intro();

    if (language == 0)
    {
        player_init("fr/intro-FR.txt");
    }
    else
    {
        player_init("en/intro-EN.txt");
    }
    return 0;
}
