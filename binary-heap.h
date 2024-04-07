// this file contains the binary heap data structure and operations
#ifndef BINAR_HEAP_H
#define BINAR_HEAP_H

// struct to store the priority list
typedef struct{
    int v;
    long long int cost;
}Priority_list;

// binary heap data structure
typedef struct binary_heap {
    Priority_list *array;
    int capacity;
    int size;
} binary_heap;

// Creation functions
binary_heap *create_binary_heap(int capacity);
void heapify(binary_heap *heap, Priority_list *array, int size);
binary_heap *merge(binary_heap *heap1, binary_heap *heap2);
binary_heap *meld(binary_heap *heap1, binary_heap *heap2);

// Basic functions
Priority_list find_min(binary_heap *heap);
Priority_list extract_min(binary_heap *heap);
void delete_min(binary_heap *heap);
void replace_node(binary_heap *heap, Priority_list value_to_remove, Priority_list value_to_insert);
void insert(binary_heap *heap, Priority_list value);

// Inspection functions
int size(binary_heap *heap);
int is_empty(binary_heap *heap);

// Internal functions
void sift_up(binary_heap *heap, int index);
void sift_down(binary_heap *heap, int index);

// Test functions
void print_heap(binary_heap *heap);

#endif // BINAR_HEAP_H