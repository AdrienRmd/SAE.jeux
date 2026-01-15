#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

int be_int(char *str)
{
    if (str == NULL)
        return 0;
    return atoi(str);
}

char *int_to_string(int num)
{
    char *str = (char *)malloc(20 * sizeof(char));
    if (str != NULL)
        sprintf(str, "%d", num);
    return str;
}

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

int choosing(const char *string, int nb_choice){
    int choosed = -1;
    do{
        printf("%s", string);
        scanf("%d", &choosed);
        if (choosed > 0 && choosed <= nb_choice){
            return choosed;
        }
    }
    while (1);
}