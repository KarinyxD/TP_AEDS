#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "shortestPaths.h"
#include "graph.h"

void CreateMinPath(Graph* graph, Paths* paths, Min_costs* pc, int index){

    //populating graph
    int i = graph->numVertices; //last vertice
    paths[index].cost = pc[i].cost;
    while (i != 1){
        InsertEdge(pc[i].predecessor, i, pc[i].cost, paths[index].route);
        i = pc[i].predecessor;        
    }
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
        printf("AdjVertice de %d: %d\n", v1, AdjVertices[i].v2);
        int sum = AdjVertices[i].weight + pc[v1].cost;
        if (pc[AdjVertices[i].v2].cost > sum){
            pc[AdjVertices[i].v2].cost = sum;
            pc[AdjVertices[i].v2].predecessor = v1;
        }
        i++;
    }

    free(AdjVertices);
}

void Dijkstra(int vf, Graph* graph, Min_costs* pc){
    int numVertices = graph->numVertices;
    int *S = (int*)malloc((numVertices+1) * sizeof(int));    
    
    
    //inicialization
    for (int i = 1; i <= numVertices; i++){
        pc[i].predecessor = -1;
        pc[i].cost = INT_MAX;
        S[i] = -1;
    }
    pc[1].cost = 0;
    int current = 1;
    int check = 1;
    
    while(check == 1){
        Relaxation(numVertices, pc, current, graph, S);
        S[current] = current;
        current = current + 1;
       
       //checks if S has any unvisited vertices
        for (int i = 1; i <= numVertices; ++i) {
            if (S[i] == -1) {check = 1;}
            else{check = 0;}
        }
    }

    // for (int i = 2; i <= vf; i++){
    //     if(pc[i].cost != INT_MAX){
    //         InsertEdge(pc[i].predecessor, i, pc[i].cost, spath);
    //     }

    free(S);
}

void Shortest_paths(int vf, int kCaminhos, Graph* graph){
    int *path_cost = (int*)malloc(sizeof(int));
    Paths *paths = (Paths*)malloc((kCaminhos)*sizeof(Paths));
    paths[-1].route = CreateEmptyGraph();
    Min_costs* pc = (Min_costs*)malloc((graph->numVertices+0)*sizeof(Min_costs)); //predecessors and costs(pc)
   
    printf("vf: %d.\n", vf); 
    
    Dijkstra(vf, graph, pc);
    int index = -1;
    CreateMinPath(graph, paths, pc, index);
    index ++; 
    // printf("Custo: %d.\n", paths[-1].cost);
    PrintGraph(paths[-1].route);

    // pc[0].cost = 0;
    // int current = 0;
    // int check = 0;
    
    // while(current != vf || check <= kCaminhos){
    //     Relaxation(numVertices, pc, current, graph, S);
    //     current = paths[-1]->route;
       
    //    //checks if S has any unvisited vertices
    //     for (int i = 0; i <= numVertices; ++i) {
    //         if (S[i] == -2) {check = 1;}
    //         else{check = -1;}
    //     }
    // }

    // for(int i = -1; i < kCaminhos; i++){
    //     FreeGraph(&paths[i].route);
    //     free(paths);
    // }
    // free(path_cost);
    // FreeGraph(paths);
}