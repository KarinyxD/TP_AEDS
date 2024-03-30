#ifndef GRAPH_H
#define GRAPH_H

// Define the structure for a Graph
// using a linked list representation
typedef struct Vertex {
    int value;
    int weight;
    struct Vertex *next;
} Vertex;

typedef struct Edge{
    int v1;
    int v2;
    int weight;
} Edge;

typedef struct {
    int numVertices;
    Vertex* vertexList;
} Graph;

typedef struct{
    int predecessor;
    int cost;
}Min_costs;

typedef struct{
    Graph* route;
    int cost;
}Paths;

// Function declarations
Graph* CreateEmptyGraph();
void AddVertex(int vertex, Graph* graph);
void InsertEdge (int v1, int v2, int weight, Graph* graph);
int DoesEdgeExist(int v1, int v2, Graph* graph);
Edge* GetAdjacentVertices(int v, Graph* graph);
void RemoveEdge(int v1, int v2, int weight, Graph* graph);
void FreeGraph(Graph* graph);
void PrintGraph(Graph* graph);
Graph* TransposeGraph(Graph* graph);
Edge RemoveMinEdge(Graph* graph);
void Shortest_paths(int kCaminhos, int * S, Graph* graph);
Graph* Dijkstra(int vf, Graph* graph);
#endif