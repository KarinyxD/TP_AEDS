#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Get nearest unvisited vertex
void Relaxation(int numVertices, int vpc[2][numVertices], int v1, Graph* graph, int *S){

    Edge *AdjVertices = GetAdjacentVertices(v1, graph); 
    int i = 0;
    int v_current = v1;
    
    while(AdjVertices[i].v2 != -1){
        int check = 0;
        for(int j = 0; j < numVertices; j++){ 
            if (AdjVertices[i].v2 == S[j]){ //checar se o vertice ja foi visitado
                check = 1;
            }
        }
        int cost = AdjVertices[i].weight + vpc[1][v_current];
        if (check == 0 && vpc[1][AdjVertices[i].v2] > cost){
            vpc[0][AdjVertices[i].v2] = v_current;
            vpc[1][AdjVertices[i].v2] = cost;
        }
        i++;
    }
    free(AdjVertices);
    // printf("While x: \n");
    // for(int i = 0; i < 2 ; i++){
    //     for(int j= 0; j < numVertices; j++){
    //         printf("%d ", vpc[i][j]);
    //     }
    //     printf("\n");
    // }
}

Graph* Dijkstra(Graph* graph){
    Graph* spath = CreateEmptyGraph();

    int numVertices = graph->numVertices;
    int S[numVertices];
    int vpc[2][numVertices];
    for (int i = 0; i < numVertices; i++){
        vpc[0][i] = -1;
        vpc[1][i] = INT_MAX;
        S[i] = -1; 
    }
    vpc[1][0] = 0;
    S[0] = 0;

    int i = 0;
    while(S[numVertices] != -1 && i < numVertices){
        Relaxation(numVertices, vpc, i, graph, S);
        S[i] = graph->vertexList[i].value;
        i++;
    }

    AddVertex(0, spath);
    for (int i = 1; i < numVertices; i++){
        InsertEdge(vpc[0][i], i, vpc[1][i], spath);
    }
    return spath;
}