#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file_manipulation.h"
#include "../structure/structure.h"
#include "other.h"
#include <sys/stat.h>

/*
 * value_line
 * Read a specific line from `filename` into `buffer_destination`.
 * Parameters:
 *  - filename: path to the file to read
 *  - line: 1-based line number to retrieve
 *  - buffer_destination: destination buffer to copy the line into
 *  - length: size of the destination buffer
 * Returns: 1 on success (line found), 0 on failure (file missing or line not found)
 */
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

/*
 * print_line
 * Print a specific line from `filename` to stdout.
 * Parameters:
 *  - filename: path to the file to read
 *  - line: 1-based line number to print
 */
void print_line(const char *filename, int line)
{
    char buffer[256];
    value_line(filename, line, buffer, sizeof(buffer));
    printf("%s", buffer);
}

/*
 * change_line
 * Replace the content of a specific line in `filename` with `text`.
 * This function creates a temporary file, writes all lines copying from
 * the original file but replacing the target line, then renames the temp
 * file to the original filename.
 * Parameters:
 *  - filename: path to the file to modify
 *  - line: 1-based line number to replace
 *  - text: new text to write at the specified line
 */
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