#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void main(){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    CreateEmptyGraph(graph);
    InsertEdge(1, 2, 10, graph);
    InsertEdge(1, 4, 5, graph);
    InsertEdge(1, 7, 50, graph);
    InsertEdge(2, 3, 3, graph);
    InsertEdge(3, 4, 2, graph);
    InsertEdge(4, 5, 71, graph);
    // RemoveEdge(1, 2, 1, graph);
    // RemoveEdge(1, 4, 5, graph);
    // RemoveEdge(2, 3, 1, graph);
    // RemoveEdge(3, 4, 2, graph);
    // RemoveEdge(4, 5, 1, graph);
    PrintGraph(graph);
    Edge edge = RemoveMinEdge(graph);
    PrintGraph(graph);
    FreeGraph(graph);
}