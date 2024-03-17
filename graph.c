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
        // now print the vertex value and all its edges with weights
        printf("Vertex %d has the following edges(weight): ", graph->vertexList[i].value);
        Vertex* current = &graph->vertexList[i];
        while(current->next != NULL){
            printf("%d(%d) ", current->next->value, current->next->weight);
            current = current->next;
        }
        printf("\n");
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
        // give a warning if the vertex v1 does not exist
        else if (i == graph->numVertices - 1){
            printf("Warning: Vertex %d does not exist\n"
            "Warning: No edges were inserted\n", v1);
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

// check if the edge exists
int DoesEdgeExist(int v1, int v2, Graph* graph){
    for (int i = 0; i < graph->numVertices; i++){
        if (graph->vertexList[i].value == v1){
            Vertex* current = &graph->vertexList[i];
            while(current->next != NULL){
                if (current->next->value == v2){
                    return 1;
                }
                current = current->next;
            }
            return 0;
        }
    }
    printf("Warning: Vertex %d does not exist\n", v1);
    return 0;
}
// get a list of all the adjacent vertices
int* GetAdjacentVertices(int v, Graph* graph){
    // create a list of adjacent vertices with a maximum size of the number of vertices
    int* adjacentVertices = (int*)malloc(graph->numVertices * sizeof(int));
    int count = 0;
    for (int i = 0; i < graph->numVertices; i++){
        if (graph->vertexList[i].value == v){
            Vertex* current = &graph->vertexList[i];
            while(current->next != NULL){
                adjacentVertices[count] = current->next->value;
                count++;
                current = current->next;
            }
            // making the last element of the list -1
            adjacentVertices[count] = -1;
            break;
        }
    }
    return adjacentVertices;
}