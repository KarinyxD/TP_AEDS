#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "shortestPaths.h"
#include "graph.h"

void CreateMinPath(Graph* graph, Paths* paths, Min_costs* pc, int index){
    paths[index].route = CreateEmptyGraph();
    //populating graph
    int i = graph->numVertices; //last vertice
    paths[index].cost = pc[i].cost;
    while (i != 1){
        // printf("inserindo: %d e %d com peso %d.\n", pc[i].predecessor, i, pc[i].cost);
        InsertEdge(pc[i].predecessor, i, pc[i].cost, paths[index].route);
        i = pc[i].predecessor;  
        // printf("i: %d\n", i);      
    }
}

//Get k shortest paths
void Shortest_paths(int vi, int vf, int kCaminhos, Graph* graph){
    Paths *paths = (Paths*)malloc((kCaminhos) * sizeof(Paths));
    Min_costs* pc = (Min_costs*)malloc((graph->numVertices+1)*sizeof(Min_costs)); //predecessors and costs(pc)
    printf("Grafo original:\n");
    PrintGraph(graph);
    //first interation Dijkstra(the minimal path) 
    Dijkstra(vi, vf, graph, pc, 0);
    int index = 0;
    CreateMinPath(graph, paths, pc, index);
    printf("Grafo k[%d] com peso %d: \n", index, paths[index].cost);
    PrintGraph(paths[index].route);
    index++;

    int k = 1;
    Edge temp; 
    while(index < kCaminhos){
    printf("kcaminhos: %d\n", kCaminhos);
        for(int j=0; j < graph->numVertices; j++){
            int v = graph->vertexList[j].value; // pega valor do vertice
            for (int n = 0; n < paths[k-1].route->numVertices; n++){
                if (v == paths[k-1].route->vertexList[n].value){ //se existir, procura em qual n posição esta meu vertice v no meu k-path
                    // printf("valor do vertice no grafo k(n) encontrado: %d\n", paths[k-1].route->vertexList[n].value);
                    Edge* current_vadj = GetAdjacentVertices(v, graph); // pega os vertices adjacentes ao vertice v
                    if(current_vadj[1].v2 != -1 && current_vadj[0].v2 != -1){ // verifica se meu vertice v possui mais de 1 vertice adjacente
                        // printf("current_vadj.v1 = %d\ncurrent_vadj.v2 = %d\ncurrent_vadj.weight = %d\n", current_vadj[1].v1, current_vadj[1].v2, current_vadj[1].weight);
                        temp.v1 = v;
                        temp.v2 = paths[k-1].route->vertexList[n].next->value; 
                        int m = 0;
                        //procura o peso correto do vertice a ser removido
                        while(current_vadj[m].v2 != paths[k-1].route->vertexList[n].next->value){m++;}
                        temp.weight = current_vadj[m].weight;
                        // printf("peso temp de %d e %d: %d\n", temp.v1, temp.v2, temp.weight);
                        //aresta a ser removida salva 
                        RemoveEdge(temp.v1, temp.v2, temp.weight, graph);
                        // int r = v;
                        // while(r > 1){
                        //     InsertEdge(pc[r].predecessor, r, pc[r].cost, paths[k].route); 
                        //     r = pc[r].predecessor;
                        // }
                        // printf("v= %d, pc[v].predecessor= %d, pc[v].cost= %d.\n", v, pc[v].predecessor, pc[v].cost);
                        Dijkstra(1, vf, graph, pc, 0); //calcula o menor caminho/custo entre o vertice ramificado e o vertice final
                        // for(int p=0; p <= graph->numVertices;p++){
                        //    printf("vertice= %d, predecessor: %d, cost= %d\n", p, pc[p].predecessor, pc[p].cost);
                        // } 
                        CreateMinPath(graph, paths, pc, index);
                        printf("Grafo k[%d] com peso %d: \n", index, paths[index].cost);
                        PrintGraph(paths[index].route);
                        //verifica se o caminho já foi encontrado anteriormente
                        int equal;
                        for(int h=0; h < index; h++){
                            equal = EqualGraphs(paths[h].route, paths[index].route);
                            if (equal == 1){
                                FreeGraph(paths[index].route);
                                index--;
                            }
                        }
                        index++; 
                        InsertEdge(temp.v1, temp.v2, temp.weight, graph); //retorna aresta removida ao grafo original
                        //Compara se o novo grafo é igual a algum ja encontrado, se for, remove da lista
                    }
                    free(current_vadj);
                }
            }
        }
    k++;
    }
    printf("teste");
    //Ordena a lista de paths pelo custo.(?)
    //retorna os kCaminhos primeiros custos

    // printf("Custo: %d.\n", paths[0].cost);
    free(pc);
    
    // Liberar a memória alocada para o array de estruturas paths
    for (int i = 0; i < kCaminhos; i++) {
        // Liberar a memória alocada para o grafo em route
        FreeGraph(paths[i].route);
    }
    free(paths);

}


//Get nearest unvisited vertex
void Relaxation(int numVertices, Min_costs* pc, int v1, Graph* graph){

    Edge *AdjVertices = GetAdjacentVertices(v1, graph); 
    int i = 0;
    
    while(AdjVertices[i].v2 != -1){
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

    free(S);
}
