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
    for(int i = 0; i < 2 ; i++){
        for(int j= 0; j < numVertices; j++){
            printf("%d ", vpc[i][j]);
        }
        printf("\n");
    }
}

Graph* Dijkstra(int v1, Graph* graph){
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
    S[0] = v1;
    
    // for(int i=0;i<numVertices;i++){
    //     printf("%d ", S[i]);
    // }
    Edge *AdjVertices = GetAdjacentVertices(v1, graph); 
    int i = 0;
    int v_current = v1;
    
    Relaxation(numVertices, vpc, v1, graph, S);
    // printf("os vertices adjacentes a 1 com seus respectivos pesos sao: \n");
//    int i = 0;
    // while(AdjVertices[i].v2 != -1){
    //     printf("%d  %d\n", AdjVertices[i].v2, AdjVertices[i].weight);
    //     i++;
    // }
    //for (int i = 0; i < 2; i++) {
    //    free(vpc[i]);
    //}
    //free(vpc);

    // while (S[numVertices-1] != -1){
    //     for(int i = 0; i < numVertices; i++){
    //         Edge *AdjVertices = GetAdjacentVertices(S[i], graph);
    //         if (graph->vertexList[i].value == S[i]){

    //         //Vertex* current = &graph->vertexList[i];
            
    //         }
    //     }
    // }

    return spath;
}