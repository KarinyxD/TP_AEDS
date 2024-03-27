#Do que se trata?

#Sobre decisões em relação a estrutura de dados
Inicialmente estaremos implementando grafos utilizando uma lista de adjacencia. O motivo é a facilidade na implementação, que nos permite ter mais tempo para focar em uma boa estruturação do codigo, boa modularização, e solução do problema proposto. Posteriormente, podemos realizar a modificação da estrutura de dados e das funções de grafos para otimizar o codigo, se assim julgarmos necessário.

#Funções Implementadas
Graph* CreateEmptyGraph();
void InsertEdge (int v1, int v2, int weight, Graph* graph);
int DoesEdgeExist(int v1, int v2, Graph* graph);
int* GetAdjacentVertices(int v, Graph* graph);
void RemoveEdge(int v1, int v2, int weight, Graph* graph);
void FreeGraph(Graph* graph);
void PrintGraph(Graph* graph);
Graph* TransposeGraph(Graph* graph);
Edge RemoveMinEdge(Graph* graph);
Graph* Dijkstra(int v1, Graph* graph);

#Funções auxiliares
void AddVertex(int vertex, Graph* graph);
void Relaxation(int numVertices, int vpc[2][numVertices], int v1, Graph* graph, int *S);

#Feitos Kariny
--modifiquei a funçao GetAdjacentVertices para poder retornar uma struct do tipo Edge;
--fiz a funçao auxiliar Relaxation, usada no Djkistra;
--fiz o Djkistra;(retorna um grafo, com o menor caminho).


#To do
--Encontrar os k menores caminhos.

###OBS do programa: para que funcione corretamente, é necessário que se crie os vértices do grafo com valores numéricos,
em ordem crescente(inclusive a declaração), COMEÇANDO do número 0.