//import .h file
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//function to create a new empty graph
Graph* CreateEmptyGraph(){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->vertexList = NULL;
    return graph;
}

//function to add a vertex to the graph
void AddVertex(int vertex, Graph *graph){
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
    int v1Exists = 0, v2Exists = 0;

    // Check if the vertices v1 and v2 existint weight;
    for (int i = 0; i < graph->numVertices; i++){
        if (graph->vertexList[i].value == v1){
            v1Exists = 1;
        }
        if (graph->vertexList[i].value == v2){
            v2Exists = 1;
        }
    }

    // Create the vertices v1 and v2 if they don't exist
    if (!v1Exists){
        AddVertex(v1, graph);
    }
    if (!v2Exists){
        AddVertex(v2, graph);
    }

    // Find the vertex with value v1 and add a new vertex with value v2 and weight to the end of the list
    for (int i = 0; i < graph->numVertices; i++){
        if (graph->vertexList[i].value == v1){
            Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));
            newVertex->value = v2;
            newVertex->weight = weight;
            newVertex->next = NULL;

            // Find the last vertex from vertex next
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
Edge* GetAdjacentVertices(int v, Graph* graph){
    // create a list of adjacent vertices with a maximum size of the number of vertices
    Edge* adjacentVertices = (Edge*)malloc(graph->numVertices * sizeof(Edge));
    int count = 0;
    for (int i = 0; i < graph->numVertices; i++){
        if (graph->vertexList[i].value == v){
            Vertex* current = &graph->vertexList[i];
            while(current->next != NULL){
                adjacentVertices[count].v2 = current->next->value;
                adjacentVertices[count].weight = current->next->weight;
                count++;
                current = current->next;
            }
            // making the last element of the list -1
            adjacentVertices[count].v2 = -1;
            break;
        }
    }
    return adjacentVertices;
}
// remove an edge
void RemoveEdge(int v1, int v2, int weight, Graph* graph){
    // find the vertex with value v1
    for (int i = 0; i < graph->numVertices; i++){
        // if the vertex is found, current is the vertex with value v1 and prev is the vertex before current
        if (graph->vertexList[i].value == v1){
            Vertex* current = graph->vertexList[i].next;
            Vertex* prev = &graph->vertexList[i];
            // find the vertex with value v2 and remove it
            while(current != NULL){
                if (current->value == v2 && current->weight == weight){
                    prev->next = current->next;
                    free(current);
                    return;
                }
                prev = current;
                current = current->next;
            }
            printf("Warning: Edge %d(%d) does not exist\n", v2, weight);
            return;
        }
    }
}
// free the graph
void FreeGraph(Graph* graph){
    for (int i = 0; i < graph->numVertices; i++){
        Vertex* current = &graph->vertexList[i];
        while(current->next != NULL){
            Vertex* temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
    }
    free(graph->vertexList);
    free(graph);
}

//removes the smallest edge of the graph
Edge RemoveMinEdge(Graph* graph){
    Edge edge;
    edge.weight = INT_MAX;
    for (int i = 0; i < graph->numVertices; i++){
        Vertex* current = graph->vertexList[i].next;
        while(current != NULL){
            if (edge.weight > current->weight){
                edge.v1 = graph->vertexList[i].value;
                edge.v2 = current->value;
                edge.weight = current->weight;
            }
            current = current->next;
        }
    }
    RemoveEdge(edge.v1, edge.v2, edge.weight,graph);
    printf("The minimum edge between %d e %d, with weight = %d was delete!\n", edge.v1, edge.v2, edge.weight);
    return edge;
}

Graph* TransposeGraph(Graph* graph){
    Graph *grapht = CreateEmptyGraph();
    Edge edge;
    for(int i = 0; i < graph->numVertices; i++){
        AddVertex(graph->vertexList[i].value, grapht);
    }
    for (int i = 0; i < graph->numVertices; i++){
        edge.v1 = graph->vertexList[i].value;
        Vertex* current = graph->vertexList[i].next;      
        while(current != NULL){
            edge.v2 = current->value;
            edge.weight = current->weight;
            InsertEdge(edge.v2, edge.v1 , edge.weight, grapht);
            current = current->next;
        }
    }
    return grapht;
}