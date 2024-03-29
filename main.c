#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "graph.h"
#include "entry.h"

int main(int argc, char *argv[]){
    // measuring execution and processing time
    struct timeval start, end;
    struct rusage usage;
    gettimeofday(&start, NULL);  // start time

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

    // printing execution time
    gettimeofday(&end, NULL);  // end time
    long seconds = end.tv_sec - start.tv_sec;
    long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
    printf("Elapsed time: %ld seconds and %ld microseconds\n", seconds, micros);

    // printing CPU usage
    getrusage(RUSAGE_SELF, &usage);
    printf("CPU usage: %ld seconds and %ld microseconds\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);

    // free memory and close file
    free(numArestas);
    free(numVertices);
    free(kCaminhos);
    FreeGraph(graph);  // assuming you have a function to free the graph
    fclose(file);

    return 0;
}