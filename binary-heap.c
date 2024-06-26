#include "binary-heap.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// in this file we will implement the following functions

// Creation functions
binary_heap *create_binary_heap(int capacity){
    binary_heap *heap = (binary_heap *)malloc(sizeof(binary_heap));
    heap->capacity = capacity;
    heap->size = 1;
    heap->array = (Priority_list *)malloc(sizeof(Priority_list) * capacity);
    return heap;
}
void heapify(binary_heap *heap, Priority_list *array, int size){
    heap->size = size;
    for(int i = 0; i < size; i++){
        heap->array[i] = array[i];
    }
    // i = size/2 - 1 is the last node that has at least one child
    for(int i = size/2 - 1; i >= 0; i--){
        sift_down(heap, i);
    }
}
// merge two heaps without including duplicates
binary_heap *merge(binary_heap *heap1, binary_heap *heap2){
    binary_heap *heap = create_binary_heap(heap1->size + heap2->size);
    int new_heap_size = 0;
    // insert all elements of heap1 into the new heap
    for(int i = 0; i < heap1->size; i++){
        insert(heap, heap1->array[i]);
        new_heap_size++;
    }
    // iterate over all elements of heap2
    for (int i = 0; i < heap2->size; i++){
        int j;
        // check if the element is already in the new heap
        for(j = 0; j < heap1->size; j++){
            if(heap2->array[i].v == heap1->array[j].v && heap2->array[i].cost == heap1->array[j].cost){
                break;
            }
        }
        // if not found, insert the element into the new heap
        if (j == heap1->size){
            insert(heap, heap2->array[i]);
            new_heap_size++;
        }
    }
    heap->size = new_heap_size;
    return heap;
}
binary_heap *meld(binary_heap *heap1, binary_heap *heap2){
    // merge the two heaps
    binary_heap* merged_heaps = merge(heap1, heap2);
    // free the two heaps
    free(heap1->array);
    free(heap1);
    free(heap2->array);
    free(heap2);
    // return the merged heap
    return merged_heaps;
}

// Basic functions
Priority_list find_min(binary_heap *heap){
    return heap->array[0];
}
Priority_list extract_min(binary_heap *heap){
    if (heap->size == 0){
        Priority_list empty;
        empty.v = -1;
        empty.cost = -1;
        return empty;
    }
    // change the last element with the first element
    // saving the first element in a variable
    Priority_list min = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    // decrease the size of the heap
    heap->size--;
    // sift down the first element
    sift_down(heap, 0);
    return min;
}
void delete_min(binary_heap *heap){
    if (heap->size == 0){
        return;
    }
    // change the last element with the first element
    heap->array[0] = heap->array[heap->size - 1];
    // decrease the size of the heap
    heap->size--;
    // sift down the first element
    sift_down(heap, 0);
}
void replace_node(binary_heap *heap, Priority_list value_to_remove, Priority_list value_to_insert){
    // find the index of the value to remove
    int index = -1;
    for(int i = 0; i < heap->size; i++){
        if(heap->array[i].v == value_to_remove.v && heap->array[i].cost == value_to_remove.cost){
            index = i;
            break;
        }
    }
    // if the value is not found, return
    if(index == -1){
        return;
    }
    // replace the value
    heap->array[index] = value_to_insert;
    // sift up the value
    sift_up(heap, index);
    sift_down(heap, index);
}
void insert(binary_heap *heap, Priority_list value){
    // if the heap is full, return
    if(heap->size == heap->capacity){
        return;
    }
    // insert the value at the end of the heap
    heap->array[heap->size] = value;
    // increase the size of the heap
    heap->size++;
    // sift up the value
    sift_up(heap, heap->size - 1);
}

// Inspection functions
int size(binary_heap *heap){
    return heap->size;
}
int is_empty(binary_heap *heap){
    return heap->size == 0;
}

// Internal functions
void sift_up(binary_heap *heap, int index){
    // get the parent index
    int parent = (index - 1) / 2;
    // if the parent is greater than the current element
    if(heap->array[parent].cost > heap->array[index].cost){
        // swap the parent and the current element
        Priority_list temp = heap->array[parent];
        heap->array[parent] = heap->array[index];
        heap->array[index] = temp;
        // sift up the parent
        sift_up(heap, parent);
    }
}

void sift_down(binary_heap *heap, int index){
    // get the left child index
    int left_child = 2 * index + 1;
    // get the right child index
    int right_child = 2 * index + 2;
    // get the smallest index
    int smallest = index;
    // if the left child is smaller than the current element
    if(left_child < heap->size && heap->array[left_child].cost < heap->array[smallest].cost){
        smallest = left_child;
    }
    // if the right child is smaller than the current element
    if(right_child < heap->size && heap->array[right_child].cost < heap->array[smallest].cost){
        smallest = right_child;
    }
    // if the smallest index is not the current index
    if(smallest != index){
        // swap the smallest element with the current element
        Priority_list temp = heap->array[smallest];
        heap->array[smallest] = heap->array[index];
        heap->array[index] = temp;
        // sift down the smallest element
        sift_down(heap, smallest);
    }
}

// print the heap
void print_heap(binary_heap *heap){
    for (int i = 0; i < heap->size; i++){
        printf("v: %d, cost: %lld\n", heap->array[i].v, heap->array[i].cost);
    }
    printf("\n");
}