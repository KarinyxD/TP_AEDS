#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "entry.h"

Arguments parse_arguments(int argc, char *argv[]){
    Arguments args;
    int opt;

    while ((opt = getopt(argc, argv, "i:o:")) != -1) {
        switch (opt) {
        case 'i':
            args.inputFile = optarg;
            break;
        case 'o':
            args.outputFile = optarg;
            break;
        default:
            printf("Usage: %s -i inputfile -o outputfile\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    if (args.inputFile == NULL || args.outputFile == NULL) {
        printf("Both input and output files must be provided\n");
        exit(EXIT_FAILURE);
    }

    return args;
}


FILE* open_file(char *filename, char *mode){
    char folder[] = "./inputs-and-ouputs/";
    char fullPath[255];

    // Concatenate the folder name and the filename
    strcpy(fullPath, folder);
    strcat(fullPath, filename);

    FILE *file = fopen(fullPath, mode);
    if (file == NULL){
        printf("Error opening file %s\n", fullPath);
        exit(EXIT_FAILURE);
    }
    return file;
}

void read_line(FILE* file, int *n, int *m, int *k){
    // in the first line n will be number of nodes, m will be number of edges and k will be number of paths
    // in the second line n will be a node, m will be a node and k will be the weight of the edge
    fscanf(file, "%d %d %d", n, m, k);
}