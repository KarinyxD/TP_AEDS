#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "entry.h"

int main(int argc, char *argv[]){
    // verifying if the arguments are correct
    Arguments args = parse_arguments(argc, argv);

    // reading arg_i file
    FILE* file = open_file(args.inputFile);

    // getting the number of vertices, edges and k paths from file
    int *numArestas = (int*)malloc(sizeof(int));
    int *numVertices = (int*)malloc(sizeof(int));
    int *kCaminhos = (int*)malloc(sizeof(int));
    read_line(file, numVertices, numArestas, kCaminhos);
    printf("numVertices: %d, numArestas: %d, kCaminhos: %d\n", *numVertices, *numArestas, *kCaminhos);
    
    // building graph
    Graph* graph = CreateEmptyGraph();
    // inserting data into graph
    for (int i = 0; i < *numArestas; i++){
        int v1, v2, weight;
        read_line(file, &v1, &v2, &weight);
        InsertEdge(v1, v2, weight, graph);
    }

    // print graph
    PrintGraph(graph);

    return 0;
}