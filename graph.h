#ifndef GRAPH_H
#define GRAPH_H

// Define the structure for a Graph
// using a linked list representation
typedef struct Vertex {
    int value;
    long long int weight;
    struct Vertex *next;
} Vertex;

typedef struct Edge{
    int v1;
    int v2;
    long long int weight;
} Edge;

typedef struct {
    int numVertices;
    Vertex* vertexList;
} Graph;



// Function declarations
Graph* CreateEmptyGraph();
void AddVertex(int vertex, Graph* graph);
void InsertEdge (int v1, int v2, long long int weight, Graph* graph);
int DoesEdgeExist(int v1, int v2, Graph* graph);
Edge* GetAdjacentVertices(int v, Graph* graph);
void RemoveEdge(int v1, int v2, long long int weight, Graph* graph);
void FreeGraph(Graph* graph);
void PrintGraph(Graph* graph);
Graph* TransposeGraph(Graph* graph);
Edge RemoveMinEdge(Graph* graph);
int EqualGraphs(Graph* graph1, Graph* graph2);

#endif