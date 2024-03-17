#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void main(){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    CreateEmptyGraph(graph);
    AddVertex(1, graph);
    AddVertex(2, graph);
    AddVertex(3, graph);
    AddVertex(4, graph);
    AddVertex(5, graph);
    InsertEdge(1, 2, 1, graph);
    InsertEdge(1, 4, 5, graph);
    InsertEdge(2, 3, 1, graph);
    InsertEdge(3, 4, 1, graph);
    InsertEdge(4, 5, 1, graph);
    // int *list = GetAdjacentVertices(1, graph);
    // while (*list != -1){
    //     printf("%d ", *list);
    //     list++;
    // }
    // printf("\n");
    // RemoveEdge(1, 2, 1, graph);
    // list = GetAdjacentVertices(1, graph);
    // while (*list != -1){
    //     printf("%d ", *list);
    //     list++;
    // }
    FreeGraph(graph);
}