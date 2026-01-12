#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

int value_line(const char *filename, int line, char *buffer_destination, int length){
    FILE *file = fopen(filename, 'r');
    int i = 1;
    while (fgets(buffer_destination, length, file) != NULL) {
        if (i == line) {
            buffer_destination[strcspn(buffer_destination, "\n")] = 0;

            fclose(file);
            return 1;
        }
        i++;
    }

    fclose(file);
    return 0;
}



int main()
{
    /*// open the file
    FILE *file = fopen(file, "r");

    // read the file size
    struct stat sb;
    stat(file, &sb);

    // allocation of the character array
    char *file_contents = malloc(sb.st_size);

    // display line by line
    while (fscanf(file, "%[^\n] ", file_contents) != EOF)
    {
        printf("> %s\n", file_contents);
    }

    // close file
    fclose(file);
    exit(EXIT_SUCCESS);*/

    char buffer[256];

    value_line("fr/intro-FR.txt", 3, buffer, sizeof(buffer));
    printf("%s", buffer);
}
