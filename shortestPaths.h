#ifndef SHORTESTPATHS_H
#define SHORTESTPATHS_H
#include <stdint.h>

// Estrutura para representar a lista da heap
typedef struct{
    int v;
    int64_t cost;
}Priority_list;

// Estrutura para representar a heap
typedef struct {
    Priority_list *arr;
    int size;
    int capacity;
} MinHeap;


//Funcoes MinPath
void Relaxation(Priority_list v_current, MinHeap* list, Graph* graph);
void Shortest_paths(int vi, int vf, int numArestas, int kCaminhos, Graph* graph, int64_t* S);

//Funçoes Heap
void freeMinHeap(MinHeap* minHeap);
MinHeap* createMinHeap(int capacity);
void insert(MinHeap* minheap, Priority_list key);
Priority_list getMinCostElement(MinHeap* minHeap);
Priority_list removeMinCostElement(MinHeap* minHeap);
void heapifyDown(MinHeap* minHeap, int index);
void heapifyUp(MinHeap* minHeap, int index);
void swap(Priority_list* a, Priority_list* b);

#endif