#ifndef GESTION_FICHIERS_H
#define GESTION_FICHIERS_H

int value_line(const char *filename, int line, char *buffer_destination, int length);

void print_line(const char *filename, int line);

void change_line(const char *filename, int line, const char *text);

#endif