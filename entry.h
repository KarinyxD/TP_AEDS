#ifndef ENTRY_H
#define ENTRY_H
#include <stdio.h>

typedef struct {
    char *inputFile;
    char *outputFile;
} Arguments;

// verify if the arguments are correct
Arguments parse_arguments(int argc, char *argv[]);
// open file acording to the mode
FILE* open_file(char *filename, char *mode);
// read a line from the file
void read_line(FILE* file, int *n_vertices, int *n_caminhos, int *k_caminhos);

#endif