#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


Graph* Dijkstra(int v1, Graph* graph){
    Graph* spath = CreateEmptyGraph();

    int numVertices = graph->numVertices;
    int vpc[2][numVertices-1]; //value, predecessor, cost
    int S[numVertices-1];
    for (int i = 0; i < numVertices; i++){
        vpc[0][i] = graph->vertexList[i].value;
        vpc[1][i] = -1;
        vpc[2][i] = INT_MAX;
        S[i] = -1; 
        if (vpc[0][i] == v1){
            vpc[2][i] = 0;
            S[i] = v1;
        }
    }
    Edge *AdjVertices = GetAdjacentVertices(1, graph);
    // printf("os vertices adjacentes a 1 com seus respectivos pesos sao: \n");
    // int i = 0;
    // while(AdjVertices[i].v2 != -1){
    //     printf("%d  %d\n", AdjVertices[i].v2, AdjVertices[i].weight);
    //     i++;
    // }
    // while (S[numVertices-1] != -1){
    //     for(int i = 0; i < numVertices; i++){
    //         if (graph->vertexList[i].value == S[i]){

    //         Vertex* current = &graph->vertexList[i];
    //         }
    //     }
    // }

    return spath;
}