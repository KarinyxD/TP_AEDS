#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


Dijkstra(int v1, Graph* graph){
    Graph* spath = CreateEmptyGraph();
    int vpc[2][graph->numVertices-1]; //value, predecessor, cost
    int Q[graph->numVertices-1], S[graph->numVertices-1];
    
    for (int i = 0; i < graph->numVertices; i++){
        Q[i], vpc[0][i] = graph->vertexList[i].value;
        vpc[1][i] = NULL;
        vpc[2][i] = INT_MAX; 
    }


    return spath;
}