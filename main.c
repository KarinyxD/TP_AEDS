#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "graph.h"
#include "entry.h"

void main(){
    Graph * graph = CreateEmptyGraph();
    InsertEdge(1, 2, 10, graph);
    InsertEdge(1, 4, 5, graph);
    InsertEdge(3, 4, 2, graph);
    // InsertEdge(1, 6, 5, graph);   
    // InsertEdge(0, 1, 1, graph);
    // InsertEdge(0, 2, 2, graph);
    // InsertEdge(0, 3, 30, graph);
    InsertEdge(2, 3, 3, graph);
    InsertEdge(2, 5, 10, graph);
    InsertEdge(5, 6, 30, graph);
    InsertEdge(4, 5, 71, graph);
    // RemoveEdge(1, 2, 1, graph);
    // RemoveEdge(1, 4, 5, graph);
    // RemoveEdge(2, 3, 1, graph);
    // RemoveEdge(3, 4, 2, graph);
    // RemoveEdge(4, 5, 1, graph);
    // Edge edge[5];
    // for (int i = 0; i < 5; i++){
    //     edge[i] = RemoveMinEdge(graph);
    // }
    // FreeGraph(graph);
    // Graph* grapht = TransposeGraph(graph);
    // PrintGraph(grapht);
    // FreeGraph(grapht);

    Graph* spath; 
    spath = Dijkstra(graph);
    PrintGraph(graph);
    PrintGraph(spath);
    FreeGraph(spath);
    FreeGraph(graph);
}