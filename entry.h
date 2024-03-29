#ifndef ENTRY_H
#define ENTRY_H
#include <stdio.h>

typedef struct {
    char *inputFile;
    char *outputFile;
} Arguments;

Arguments parse_arguments(int argc, char *argv[]);
FILE* open_file(char *filename);
void read_line(FILE* file, int *n_vertices, int *n_caminhos, int *k_caminhos);
#endif