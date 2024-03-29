#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "entry.h"

Arguments parse_arguments(int argc, char *argv[]){
    Arguments args;

    if (argc != 3) {
        printf("Both input and output files must be provided\n");
        exit(EXIT_FAILURE);
    }

    args.inputFile = argv[1];
    args.outputFile = argv[2];

    return args;
}

FILE* open_file(char *filename, char *mode){
    FILE *file = fopen(filename, mode);
    if (file == NULL){
        printf("Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    return file;
}

void read_line(FILE* file, int *n, int *m, int *k){
    // in the first line n will be number of nodes, m will be number of edges and k will be number of paths
    // in the second line n will be a node, m will be a node and k will be the weight of the edge
    fscanf(file, "%d %d %d", n, m, k);
}