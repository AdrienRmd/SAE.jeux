#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

int random_number(int minimum, int maximum)
{ // automatiquement la graine aléatoire (srand(time(NULL))).
    static int initialized = 0;
    if (!initialized)
    {
        srand(time(NULL));
        initialized = 1;
    }
    return minimum + rand() % (maximum - minimum + 1);
}