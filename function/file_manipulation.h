#ifndef MANIP_FILE_H
#define MANIP_FILE_H

int value_line(const char *filename, int line, char *buffer_destination, int length);

int value_line_return(const char *filename, int line, char *buffer_destination, int length);

void print_line(const char *filename, int line);

void change_line(const char *filename, int line, const char *text);

#endif