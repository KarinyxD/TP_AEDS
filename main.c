#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "graph.h"
#include "shortestPaths.h"
#include "entry.h"
// #include "shortestPaths.h"

int main(int argc, char *argv[]){
    // measuring execution and processing time
    struct timeval start, end;
    struct rusage usage;
    gettimeofday(&start, NULL);  // start time

    // verifying if the arguments are correct
    Arguments args = parse_arguments(argc, argv);

    // reading arg_i file
    FILE* file = open_file(args.inputFile, "r");

    // getting the number of vertices, edges and k paths from file
    int numArestas, numVertices, kCaminhos;
    read_line(file, &numVertices, &numArestas, &kCaminhos);
    
    // building graph
    Graph* graph = CreateEmptyGraph();

    // inserting data into graph
    for (int i = 0; i < numArestas; i++){
        int v1, v2, weight;
        read_line(file, &v1, &v2, &weight);
        InsertEdge(v1, v2, weight, graph);
    }

    // allocating memory for the k paths size
    int *S = (int*)malloc(sizeof(int) * kCaminhos);

    // calculating the shortest path
    Shortest_paths(1, numVertices, numArestas, kCaminhos, graph, S);

    // cleaning the output and opening file
    FILE* output = open_file(args.outputFile, "w");
    // printing the k shortest paths in output file
    for (int i = 0; i < kCaminhos; i++){
        printf("%d ", S[i]);
        fprintf(output, "%d ", S[i]);
    }
    printf("\n");
    // free memory and close file
    FreeGraph(graph);  // assuming you have a function to free the graph
    fclose(file);
    fclose(output);
    free(S);

    // printing execution time
    gettimeofday(&end, NULL);  // end time
    long seconds = end.tv_sec - start.tv_sec;
    long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
    printf("Elapsed time: %ld seconds and %ld microseconds\n", seconds, micros);

    // printing CPU usage
    getrusage(RUSAGE_SELF, &usage);
    printf("CPU usage: %ld seconds and %ld microseconds\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);

    return 0;
}