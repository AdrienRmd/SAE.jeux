#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

// structure du joueur

typedef struct
{
    char name[20];
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

int value_line(const char *filename, int line, char *buffer_destination, int length)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        return 0;
    }

    int i = 1;

    while (fgets(buffer_destination, length, file) != NULL)
    {
        if (i == line)
        {
            size_t len = strlen(buffer_destination);
            if (len > 0 && buffer_destination[len - 1] == '\n')
            {
                buffer_destination[len - 1] = '\0';
            }
            fclose(file);
            return 1;
        }
        i++;
    }

    fclose(file);
    return 0;
}

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

void print_line(const char *filename, int line)
{
    char buffer[256];
    value_line(filename, line, buffer, sizeof(buffer));
    printf("%s", buffer);
}

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

void change_line(const char *filename, int line, const char *text)
{
    FILE *f_source, *f_temp;
    char buffer[256];
    int i = 1;
    char temp_name[] = "temp____.tmp"; // Nom temporaire

    f_source = fopen(filename, "r");
    if (f_source == NULL)
    {
        printf("Error : Can't open original file.\n");
        return;
    }

    f_temp = fopen(temp_name, "w");
    if (f_temp == NULL)
    {
        printf("Erreur : Can't create temporary file.\n");
        fclose(f_source);
        return;
    }

    while (fgets(buffer, sizeof(buffer), f_source) != NULL)
    {
        if (i == line)
        {
            fprintf(f_temp, "%s\n", text);
        }
        else
        {
            fputs(buffer, f_temp);
        }
        i++;
    }

    fclose(f_source);
    fclose(f_temp);

    remove(filename);

    rename(temp_name, filename);
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
