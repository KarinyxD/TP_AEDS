#ifndef SHORTESTPATHS_H
#define SHORTESTPATHS_H

typedef struct{
    int predecessor;
    int cost;
}Min_costs;

typedef struct{
    Graph* route;
    int cost;
}Paths;

void CreateMinPath(Graph* graph, Paths* paths, Min_costs* pc, int index);
void Relaxation(int numVertices, Min_costs* pc, int v1, Graph* graph, int *S);
void Dijkstra(int vf, Graph* graph, Min_costs* pc);
void Shortest_paths(int vf, int kCaminhos, Graph* graph);

#endif