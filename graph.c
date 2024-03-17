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

// void InsertEdge(int v1, int v2, int weight, Graph* graph);
// function to insert an edge between two vertices
void InsertEdge(int v1, int v2, int weight, Graph* graph){
    // check if the v1 vertex exists
    for (int i = 0; i < graph->numVertices; i++){
        if (graph->vertexList[i].value == v1){
            break;
        }
        if (i == graph->numVertices - 1){
            printf("Vertex %d does not exist\n", v1);
            return;
        }
    }
    // check if the v2 vertex exists
    for (int i = 0; i < graph->numVertices; i++){
        if (graph->vertexList[i].value == v2){
            break;
        }
        // if it doesnt exists create it
        if (i == graph->numVertices - 1){
            AddVertex(v2, graph);
            break;
        }
    }
    // find the vertex with value v1 and add a new vertex with value v2 and weight to the end of the list
    for (int i = 0; i < graph->numVertices; i++){
        if (graph->vertexList[i].value == v1){
            Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));
            newVertex->value = v2;
            newVertex->weight = weight;
            newVertex->next = NULL;
            // find the last vertex from vertex next
            Vertex* current = &graph->vertexList[i];
            while(current->next != NULL){
                current = current->next;
            }
            current->next = newVertex;
            break;
        }
    }
}