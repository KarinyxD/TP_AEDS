#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "shortestPaths.h"
#include "graph.h"

// Função para criar uma nova heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(capacity * sizeof(MinHeap));
    minHeap->capacity = capacity;
    minHeap->size = 1;
    minHeap->arr = (Priority_list*)malloc(capacity * sizeof(Priority_list));
    return minHeap;
}
Priority_list getMinCostElement(MinHeap* minHeap) {
    Priority_list minElement;
    minElement.cost = INT_MAX; // Inicializa o custo mínimo como o máximo possível

    // Percorre o array da heap para encontrar o elemento com o menor custo
    for (int i = 0; i < minHeap->size; i++) {
        if (minHeap->arr[i].cost < minElement.cost) {
            minElement = minHeap->arr[i];
        }
    }
    
    return minElement;
}
void swap(Priority_list* a, Priority_list* b) {
    Priority_list temp = *a;
    *a = *b;
    *b = temp;
}
// Função para ajustar a heap após inserção
void heapifyUp(MinHeap* minHeap, int index) {
    while (index > 0 && minHeap->arr[(index - 1) / 2].cost > minHeap->arr[index].cost) {
        swap(&minHeap->arr[(index - 1) / 2], &minHeap->arr[index]);
        index = (index - 1) / 2;
    }
}

void insert(MinHeap* minheap, Priority_list key) {
    // Inserir o novo elemento na heap
    int index = minheap->size;
    minheap->arr[index] = key;
    minheap->size++;

    // Executar heapifyUp para manter as propriedades da heap
    heapifyUp(minheap, index);
}

// Função para ajustar a heap após remoção
void heapifyDown(MinHeap* minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->arr[left].cost < minHeap->arr[smallest].cost)
        smallest = left;

    if (right < minHeap->size && minHeap->arr[right].cost < minHeap->arr[smallest].cost)
        smallest = right;

    if (smallest != index) {
        swap(&minHeap->arr[index], &minHeap->arr[smallest]);
        heapifyDown(minHeap, smallest);
    }
}

// Função para remover o elemento com o menor custo da heap
Priority_list removeMinCostElement(MinHeap* minHeap) {
    // Verifica se a heap está vazia
    if (minHeap->size <= 0) {
        printf("Heap vazia. Não há elementos para remover.\n");
        Priority_list null_value;
        null_value.v = -1; // Valor inválido para indicar que a heap está vazia
        null_value.cost = -1;
        return null_value;
    }

    // Encontra o elemento com o menor custo
    Priority_list minCostElement = getMinCostElement(minHeap);

    // Encontra o índice do elemento com o menor custo
    int index;
    for (index = 0; index < minHeap->size; index++) {
        if (minHeap->arr[index].cost == minCostElement.cost)
            break;
    }

    // Remove o elemento com o menor custo da heap
    Priority_list removedElement = minHeap->arr[index];
    minHeap->arr[index] = minHeap->arr[minHeap->size - 1];
    minHeap->size--;
    heapifyDown(minHeap, index);

    return removedElement;
}
void freeMinHeap(MinHeap* minHeap) {
    // Libere a memória alocada para o array de elementos da heap
    free(minHeap->arr);

    // Libere a memória alocada para a própria estrutura da heap
    free(minHeap);
}

//Get k shortest paths
void Shortest_paths(int vi, int vf, int numArestas, int kCaminhos, Graph* graph, int* S){
    int count[graph->numVertices];
    MinHeap* list = createMinHeap(numArestas);
    for (int i = 0; i < graph->numVertices; i++){
        count[i] = 0;
    }
    
    list->arr[0].v = vi;
    list->arr[0].cost = 0;
    Priority_list current = list->arr[0];
    int k = 0;
    //em quanto o contador de caminhos para o ultimo vertice for menor q kCaminhos, faça:
    while(count[graph->numVertices-1] < kCaminhos){ 
        //procurar e remover o menor peso em list e armazenar em current
        current = removeMinCostElement(list);

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

    freeMinHeap(list);

}

//Get nearest unvisited vertex
void Relaxation(Priority_list v_current, MinHeap* list, Graph* graph){

    Edge *AdjVertices = GetAdjacentVertices(v_current.v, graph); // retorna uma lista com os vertices adjacentes a v 
    int i = 0;
    Priority_list AddinList;
    while(AdjVertices[i].v2 != -1){ //em quanto a lista de adj nao chegar ao fim
        int sum = AdjVertices[i].weight + v_current.cost;
        AddinList.v = AdjVertices[i].v2;
        AddinList.cost = sum;
        insert(list, AddinList);
        i++;
    }

    free(AdjVertices);
}



