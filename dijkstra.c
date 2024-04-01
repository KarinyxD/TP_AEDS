#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void CreateMinPath(Graph* graph, Paths* paths, Min_costs* pc, int index){

    //populating graph
    int i = graph->numVertices; //last vertice
    paths[index].cost = pc[i].cost;
    while (i != 1 && pc[i].predecessor != -1){
        InsertEdge(pc[i].predecessor, i, pc[i].cost, paths[index].route);
        i = pc[i].predecessor;        
    }
}

//Get k shortest paths
void Shortest_paths(int vi, int vf, int kCaminhos, Graph* graph){
    int *path_cost = (int*)malloc(sizeof(int));
    Paths *paths = (Paths*)malloc((kCaminhos)*sizeof(Paths));
    paths[0].route = CreateEmptyGraph();
    Min_costs* pc = (Min_costs*)malloc((graph->numVertices+1)*sizeof(Min_costs)); //predecessors and costs(pc)
   
    printf("vf: %d.\n", vf); 

    //first interation Dijkstra(the minimal path) 
    Dijkstra(vi, vf, graph, pc, 0);
    int index = 0;
    CreateMinPath(graph, paths, pc, index);
    int min_cust_v;
    int k = 1;

    while(k < kCaminhos){
    index ++; 
    //att cust vertex
    //min_cust_v = custo do vertice;
    k++;
    }
    // printf("Custo: %d.\n", paths[0].cost);
    PrintGraph(paths[0].route);

    // pc[1].cost = 0;
    // int current = 1;
    // int check = 1;
    
    // while(current != vf || check <= kCaminhos){
    //     Relaxation(numVertices, pc, current, graph, S);
    //     current = paths[0]->route;
       
    //    //checks if S has any unvisited vertices
    //     for (int i = 1; i <= numVertices; ++i) {
    //         if (S[i] == -1) {check = 1;}
    //         else{check = 0;}
    //     }
    // }

    // for(int i = 0; i < kCaminhos; i++){
    //     FreeGraph(&paths[i].route);
    //     free(paths);
    // }
    // free(path_cost);
    // FreeGraph(paths);
}


//Get nearest unvisited vertex
void Relaxation(int numVertices, Min_costs* pc, int v1, Graph* graph){

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

void Dijkstra(int vi, int vf, Graph* graph, Min_costs* pc, int initial_cost){
    int numVertices = graph->numVertices;
    int *S = (int*)malloc((numVertices+1) * sizeof(int));    
    
    
    //inicialization
    for (int i = 1; i <= numVertices; i++){
        pc[i].predecessor = -1;
        pc[i].cost = INT_MAX;
        S[i] = 0;
    }
    pc[vi].cost = initial_cost;

    int current = vi;

    while (!S[vf]) { // Continue até que o vértice de destino seja visitado
        S[current] = 1;
        Relaxation(numVertices, pc, current, graph);

        // Encontrar o próximo vértice não visitado com o menor custo
        int minCost = INT_MAX;
        for (int i = 1; i <= numVertices; i++) {
            if (!S[i] && pc[i].cost < minCost) {
                minCost = pc[i].cost;
                current = i;
            }
        }

        // Se não houver mais vértices acessíveis, saia do loop
        if (minCost == INT_MAX)
            break;
    } 
       //checks if S has any unvisited vertices
        // for (int i = 1; i <= numVertices; ++i) {
        //     if (S[i] == -1) {check = 1;}
        //     else{check = 0;}
        // }
    

    // for (int i = 2; i <= vf; i++){
    //     if(pc[i].cost != INT_MAX){
    //         InsertEdge(pc[i].predecessor, i, pc[i].cost, spath);
    //     }

    free(S);
}

