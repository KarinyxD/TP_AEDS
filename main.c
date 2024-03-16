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
    // now print all the vertices
    PrintGraph(graph);
}