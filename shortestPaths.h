#ifndef SHORTESTPATHS_H
#define SHORTESTPATHS_H
#include <stdint.h>
#include "binary-heap.h"


//Funcoes MinPath
void Relaxation(Priority_list v_current, binary_heap* list, Graph* graph);
void Shortest_paths(int vi, int vf, int numArestas, int kCaminhos, Graph* graph, long long int* S);

#endif