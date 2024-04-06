#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "shortestPaths.h"
#include "graph.h"
#include "binary-heap.h"

// // Função para criar uma nova heap
// MinHeap* createMinHeap(int capacity) {
//     MinHeap* minHeap = (MinHeap*)malloc(capacity * sizeof(MinHeap));
//     minHeap->capacity = capacity;
//     minHeap->size = 1;
//     minHeap->arr = (Priority_list*)malloc(capacity * sizeof(Priority_list));
//     return minHeap;
// }

// void swap(Priority_list* a, Priority_list* b) {
//     Priority_list temp = *a;
//     *a = *b;
//     *b = temp;
// }
// // Função para ajustar a heap após inserção
// void heapifyUp(MinHeap* minHeap, int index) {
//     while (index > 0 && minHeap->arr[(index - 1) / 2].cost > minHeap->arr[index].cost) {
//         swap(&minHeap->arr[(index - 1) / 2], &minHeap->arr[index]);
//         index = (index - 1) / 2;
//     }
// }

// void insert(MinHeap* minHeap, Priority_list key) {
//     // Verifica se a heap está cheia
//     if (minHeap->size >= minHeap->capacity) {
//         // Realoca memória para aumentar a capacidade da heap
//         minHeap->capacity *= 2; // Por exemplo, pode dobrar a capacidade
//         minHeap->arr = realloc(minHeap->arr, minHeap->capacity * sizeof(Priority_list));
//     }

//     // Insere o novo elemento na heap
//     int index = minHeap->size;
//     minHeap->arr[index] = key;
//     minHeap->size++;

//     // Executa heapifyUp para manter as propriedades da heap
//     heapifyUp(minHeap, index);
// }

// // Função para ajustar a heap após remoção
// void heapifyDown(MinHeap* minHeap, int index) {
//     int smallest = index;
//     int left = 2 * index + 1;
//     int right = 2 * index + 2;

//     if (left < minHeap->size && minHeap->arr[left].cost < minHeap->arr[smallest].cost)
//         smallest = left;

//     if (right < minHeap->size && minHeap->arr[right].cost < minHeap->arr[smallest].cost)
//         smallest = right;

//     if (smallest != index) {
//         swap(&minHeap->arr[index], &minHeap->arr[smallest]);
//         heapifyDown(minHeap, smallest);
//     }
// }

// // Função para remover o elemento com o menor custo da heap
// Priority_list removeMinCostElement(MinHeap* minHeap) {
//     // Verifica se a heap está vazia
//     if (minHeap->size <= 0) {
//         // printf("Heap vazia. Não há elementos para remover.\n");
//         Priority_list null_value;
//         null_value.v = -1; // Valor inválido para indicar que a heap está vazia
//         null_value.cost = -1;
//         return null_value;
//     }

//     // Remove o elemento com o menor custo da heap
//     Priority_list minCostElement = minHeap->arr[0];
//     minHeap->arr[0] = minHeap->arr[minHeap->size - 1];
//     minHeap->size--;
//     heapifyDown(minHeap, 0);

//     return minCostElement;
// }

// void freeMinHeap(MinHeap* minHeap) {
//     // Libere a memória alocada para o array de elementos da heap
//     free(minHeap->arr);

//     // Libere a memória alocada para a própria estrutura da heap
//     free(minHeap);
// }

//Get k shortest paths
void Shortest_paths(int vi, int vf, int numArestas, int kCaminhos, Graph* graph, long long int* S){
    int count[graph->numVertices];
    binary_heap* list = create_binary_heap(numArestas);
    for (int i = 0; i < graph->numVertices; i++){
        count[i] = 0;
    }
    
    list->array[0].v = vi;
    list->array[0].cost = 0;
    Priority_list current = list->array[0];
    int k = 0;
    //em quanto o contador de caminhos para o ultimo vertice for menor q kCaminhos, faça:
    while(count[graph->numVertices-1] < kCaminhos && list->size > 0){ 
        //procurar e remover o menor peso em list e armazenar em current
        current = extract_min(list);

        if(count[(current.v - 1)] == kCaminhos){ //se ja achou kCaminhos pra o vertice atual
            continue; //prox interaçao
        }

        count[current.v - 1]++;
        if (current.v == vf){ //se o vertice atual for o final, salva o custo do caminho
            S[k] = current.cost;
            k++;
        }
        //chamar relaxation pra salvar os custos dos vertices adjacentes ao current na lista 
        Relaxation(current, list, graph);
    }
    S[k] = -1; //sinaliza o final da lista de kCaminhos
    free(list->array);
    free(list);
}

//Get nearest unvisited vertex
void Relaxation(Priority_list v_current, binary_heap* list, Graph* graph){

    Edge *AdjVertices = GetAdjacentVertices(v_current.v, graph); // retorna uma lista com os vertices adjacentes a v 
    int i = 0;
    Priority_list AddinList;
    while(AdjVertices[i].v2 != -1){ //em quanto a lista de adj nao chegar ao fim
        long long int sum = AdjVertices[i].weight + v_current.cost;
        AddinList.v = AdjVertices[i].v2;
        AddinList.cost = sum;
        insert(list, AddinList);
        i++;
    }

    free(AdjVertices);
}



