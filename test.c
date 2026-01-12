#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

const char *filename = "fr/intro-FR.txt";

char value_ligne(int target_line, char *file_contents, FILE *in_file) {
    int current_line = 1;

    while (fscanf(in_file, "%[^\n] ", file_contents) != EOF) {
        if (current_line == target_line) {
            return *file_contents;
        }
        current_line++;
    }
    return '\0';
}

int main()
{
    // open the file
    FILE *in_file = fopen(filename, "r");

    // read the file size
    struct stat sb;
    stat(filename, &sb);

    // allocation of the character array
    char *file_contents = malloc(sb.st_size);

    printf("%c\n", value_ligne(3, file_contents, in_file));

    // display line by line
    while (fscanf(in_file, "%[^\n] ", file_contents) != EOF)
    {
        printf("> %s\n", file_contents);
    }

    // close file
    fclose(in_file);
    exit(EXIT_SUCCESS);
}
