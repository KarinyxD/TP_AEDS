//import .h file
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

//function to create a new empty graph
void CreateEmptyGraph(Graph* graph){
    graph->numVertices = 0;
    graph->vertexList = NULL;
}

//function to add a vertex to the graph
void AddVertex(int vertex, Graph* graph){
    graph->numVertices++;
    graph->vertexList = (Vertex*)realloc(graph->vertexList, graph->numVertices * sizeof(Vertex));
    graph->vertexList[graph->numVertices - 1].value = vertex;
    graph->vertexList[graph->numVertices - 1].weight = 0;
    graph->vertexList[graph->numVertices - 1].next = NULL;
}

//function to print the graph
void PrintGraph(Graph* graph){
    printf("The graph has %d vertices\n", graph->numVertices);
    for(int i = 0; i < graph->numVertices; i++){
        printf("Vertex %d has value %d and points to %p\n", i, graph->vertexList[i].value, graph->vertexList[i].next);
    }
}