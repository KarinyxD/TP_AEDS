#ifndef GRAPH_H
#define GRAPH_H

// Define the structure for a Graph
typedef struct {
    int numVertices;
    int** edges;
} Graph;

// Define the structure for an Edge
typedef struct {
    int v1;
    int v2;
    int weight;
} Edge;

// Function declarations
Graph* CreateEmptyGraph(int numVertices);
void InsertEdge(int v1, int v2, int weight, Graph* graph);
int DoesEdgeExist(int v1, int v2, Graph* graph);
int* GetAdjacentVertices(int v, Graph* graph);
void RemoveEdge(int v1, int v2, int weight, Graph* graph);
void FreeGraph(Graph* graph);
void PrintGraph(Graph* graph);
Graph* TransposeGraph(Graph* graph);
Edge* RemoveMinEdge(Graph* graph);