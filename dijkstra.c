#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Get k shortest pathsi
void Shortest_paths(int kCaminhos, int *S, Graph* graph){
    Paths *paths = (Paths*)malloc((kCaminhos)*sizeof(Paths)); 
}


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

Graph* Dijkstra(int vf, Graph* graph){
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
    int current = 1;
    
    while(pc[vf].cost == INT_MAX){
        Relaxation(numVertices, pc, current, graph, S);
        S[current] = current;
        current = current + 1;
        printf("%d\n", current);
    
    }

    //populating graph
    for (int i = 2; i <= vf; i++){
        if(pc[i].cost != INT_MAX){
            InsertEdge(pc[i].predecessor, i, pc[i].cost, spath);
        }
        // if(i == numVertices){
        //     *path_cost = pc[i].cost;
        // } 
    } 
    free(pc);
    free(S);
    return spath;
}



