#ifndef GRAPH_H
#define GRAPH_H

// Define the structure for a Graph
// using a linked list representation
typedef struct {
    int value;
    int weight;
    struct Vertex* next;
} Vertex;

typedef struct {
    int numVertices;
    Vertex* vertexList;
} Graph;


// Function declarations
void CreateEmptyGraph(Graph* graph);
void AddVertex(int vertex, Graph* graph);
// void InsertEdge(int v1, int v2, int weight, Graph* graph);
// int DoesEdgeExist(int v1, int v2, Graph* graph);
// int* GetAdjacentVertices(int v, Graph* graph);
// void RemoveEdge(int v1, int v2, int weight, Graph* graph);
// void FreeGraph(Graph* graph);
void PrintGraph(Graph* graph);
// Graph* TransposeGraph(Graph* graph);
// Edge* RemoveMinEdge(Graph* graph);

#endif