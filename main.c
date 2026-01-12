#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include "function/gamef.h"


/**
 * @brief Generates a random integer between minimum and maximum (inclusive)
 *
 * This function returns a random integer between the specified minimum and maximum values.
 * The range is inclusive, meaning both minimum and maximum values can be returned.
 *
 * @param minimum The minimum value to generate (inclusive)
 * @param maximum The maximum value to generate (inclusive)
 * @return A random integer between minimum and maximum
 *
 * @example
 * int nombre = tirage_nombre(1, 100); // Returns a random number between 1 and 100
 * int de = tirage_nombre(1, 6);     // Returns a random number between 1 and 6
 *
 * @note This function initializes the random seed automatically on first call
 * @warning Ensure maximum >= minimum to avoid undefined behavior
 */
int tirage_nombre(int minimum, int maximum)
{ // automatiquement la graine aléatoire (srand(time(NULL))).
    static int initialized = 0;
    if (!initialized)
    {
        srand(time(NULL));
        initialized = 1;
    }
    return minimum + rand() % (maximum - minimum + 1);
}


int main()
{
    // Test the tirage_nombre function
    printf("Testing random number generation:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Random number between 1 and 100: %d\n", tirage_nombre(1, 100));
    }

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
