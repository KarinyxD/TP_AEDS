#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Get nearest unvisited vertex
void Relaxation(int numVertices, Min_costs* pc, int v1, Graph* graph, int *S){

    Edge *AdjVertices = GetAdjacentVertices(v1, graph); 
    int i = 0;
    
    while(AdjVertices[i].v2 != -1){
        // int check = 0;
        // for(int j = 0; j < numVertices; j++){ 
        //     if (AdjVertices[i].v2 == S[j]){ //checar se o vertice ja foi visitado
        //         check = 1;
        //     }
        // }
        int sum = AdjVertices[i].weight + pc[v1].cost;
        if (pc[AdjVertices[i].v2].cost > sum){
            pc[AdjVertices[i].v2].cost = sum;
            pc[AdjVertices[i].v2].predecessor = v1;
        }
        i++;
    }

    free(AdjVertices);
}

Graph* Dijkstra(Graph* graph){
    // int *path_cost = (int*)malloc(sizeof(int));
    Graph* spath = CreateEmptyGraph();
    int numVertices = graph->numVertices;
    int *S = (int*)malloc((numVertices+1) * sizeof(int));    
    
    Min_costs* pc = (Min_costs*)malloc((numVertices+1)*sizeof(Min_costs)); //predecessors and costs(pc)
    
    //inicialization
    for (int i = 1; i <= numVertices; i++){
        pc[i].predecessor = -1;
        pc[i].cost = INT_MAX;
        S[i] = -1;
    }
    pc[1].cost = 0;
    int i = 1;
    
    while(i <= numVertices){
        Relaxation(numVertices, pc, i, graph, S);
        S[i] = graph->vertexList[i-1].value;
        i++;
    }

    //populating graph
    for (int i = 2; i <= numVertices; i++){
        InsertEdge(pc[i].predecessor, i, pc[i].cost, spath);
        // if(i == numVertices){
        //     *path_cost = pc[i].cost;
        // } 
    } 
    free(pc);
    free(S);
    return spath;
}
