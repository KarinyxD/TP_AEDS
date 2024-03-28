#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Get nearest unvisited vertex
void Relaxation(int numVertices, int **vpc, int v1, Graph* graph, int *S){

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
}

Graph* Dijkstra(int v1, Graph* graph){
    Graph* spath = CreateEmptyGraph();

    int numVertices = graph->numVertices;
    int *S = (int*)malloc((numVertices+1) * sizeof(int));    
    int **vpc = (int**)malloc(2 * sizeof(int*)); // Aloca as linhas da matriz    
    for (int i = 0; i < 2; i++) {
        vpc[i] = (int*)malloc((numVertices+1) * sizeof(int)); // Aloca as colunas da matriz
    }
    //inicialization
    for (int i = 1; i < numVertices+1; i++){
        vpc[0][i], S[i] = -1;
        vpc[1][i] = INT_MAX;
    }
    vpc[1][v1] = 0;
    S[0] = v1;

    int i = v1;
    
    while(i < numVertices){
        Relaxation(numVertices, vpc, i, graph, S);
        S[i] = graph->vertexList[i].value;
        i++;
    }

    //AddVertex(1, spath);
    for (int i = 2; i <= numVertices; i++){
        InsertEdge(vpc[0][i], i, vpc[1][i], spath);
    }
    
    for (int j = 0; j < 2; j++) {
        free(vpc[j]);
    }
    free(vpc);
    free(S);
    return spath;
}