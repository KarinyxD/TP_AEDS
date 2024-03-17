#Do que se trata?

#Sobre decisões em relação a estrutura de dados
Inicialmente estaremos implementando grafos utilizando uma lista de adjacencia. O motivo é a facilidade na implementação. Que nós permite ter mais tempo para focar em uma boa estruturação do codigo, boa modularização, e solução do problema proposto. Posteriormente, podemos realizar a modificação da estrutura de dados e das funções de grafos para otimizar o codigo, se assim julgarmos necessário.

#Funções Implementadas
void CreateEmptyGraph(Graph* graph)
void AddVertex(int vertex, Graph* graph)
void PrintGraph(Graph* graph)
void InsertEdge(int v1, int v2, int weight, Graph* graph)
int DoesEdgeExist(int v1, int v2, graph)

#Funções auxiliares

#To do
- Precisamos corrigir o Remove Edges, pois está tendo algum vazamento de memória ainda não identificado
- Facilitaria nosso trabalho no futuro se a gente removesse a função adicionar vertice, e simplismente criassemos o vertice ao adicionar uma aresta