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
{ // automatically the random seed (srand(time(NULL))).
    static int initialized = 0;
    if (!initialized)
    {
        srand(time(NULL));
        initialized = 1;
    }
    return minimum + rand() % (maximum - minimum + 1);
}

int choosing(const char *string, int nb_choice)
{
    int choosed = -1;
    do
    {
        printf("%s", string);
        if (scanf("%d", &choosed) != 1)
        {
            while (getchar() != '\n')
                ;
            continue;
        }
        while (getchar() != '\n')
            ;
        if (choosed > 0 && choosed <= nb_choice)
        {
            return choosed;
        }
    } while (1);
}

/*void print_loose(char filepath[])
{
    int pointer_start = id_biome * 2 - 1;
    int pointer_end = id_biome * 2;
    int line;

    for (line = pointer_start; line <= pointer_end; line++)
    {
        print_line(filepath, line);
        printf("\n");
    }
}*/