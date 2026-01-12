#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

int value_line(const char *filename, int line, char *buffer_destination, int length){
    FILE *file = fopen(filename, "r");

    if (file == NULL){
        return 0;
    }

    int i = 1;

    while (fgets(buffer_destination, length, file) != NULL) {
        if (i == line) {
            size_t len = strlen(buffer_destination);
            if (len > 0 && buffer_destination[len - 1] == '\n') {
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

void print_line(const char *filename, int line){
    char buffer[256];
    value_line(filename, line, buffer, sizeof(buffer));
    printf("%s", buffer);
}


void intro(){
    FILE *intro = fopen('intro.txt', "r");

    print_line(intro, 1);

    fclose(intro);
}


int main()
{
    intro();

    return 0;
}
