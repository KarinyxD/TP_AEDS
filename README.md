# K Menores Caminhos entre Mysthollow e Luminae

## 1. Introdução

O problema dos Caminhos de Mysthollow para Luminae consiste em encontrar os k menores custos entre duas cidades específicas. Aqui, k representa a quantidade de menores custos que o usuário deseja encontrar, variando de 1 a 10. É importante ressaltar que os custos dos menores caminhos encontrados podem incluir caminhos que possuem ciclos ou não.

![caminhos-simples-ciclos](https://github.com/KarinyxD/TP_AEDS/assets/121648163/3ee82b7b-46f3-49ba-8183-c5c0d357abdc)

Desenvolvemos soluções para encontrar os k custos dos menores caminhos com ciclos, assim como para encontrar os k custos e/ou os k menores caminhos simples. Nesta documentação, focaremos em explicar a solução para encontrar os k menores custos de caminhos com ciclo. No entanto, também abordaremos um algoritmo para encontrar os caminhos simples mais curtos, garantindo uma compreensão completa das diferentes abordagens para o problema.

### 1.1 Modelagem do Problema Utilizando Grafos

O problema dos Caminhos de Mysthollow para Luminae pode ser modelado de forma eficaz utilizando conceitos de grafos. Nesta modelagem, as cidades são representadas como nós e os caminhos entre elas como arestas direcionadas. É importante destacar que, no nosso caso, o grafo não deve possuir arestas negativas.

A utilização de grafos oferece diversas vantagens para resolver este problema. Primeiramente, permite uma representação visual intuitiva das conexões entre as cidades e dos caminhos disponíveis. Além disso, a estrutura de grafos facilita a aplicação de algoritmos eficientes para encontrar os k menores custos entre Mysthollow e Luminae. Um exemplo desses algoritmos é o clássico algoritmo de Dijkstra, que será adaptado para lidar com grafos direcionados e encontrar soluções para o problema.

Portanto, a modelagem do problema utilizando grafos oferece uma abordagem poderosa e flexível, permitindo explorar diversas estratégias e encontrar soluções eficientes para os Caminhos de Mysthollow para Luminae.
### 1.2 Restrições

As restrições impostas no problema dos Caminhos de Mysthollow para Luminae têm como objetivo garantir que o programa seja executado de forma eficiente e segura. Algumas dessas restrições têm justificativas específicas:

- O número de cidades (vértices), representado por "n", deve estar no intervalo entre 2 e 10^5.
- O número de voos (arestas), representado por "m", deve estar no intervalo entre 1 e 2 × 10^5.
- Os vértices de partida e destino de cada voo, representados por "a" e "b" respectivamente, devem estar no intervalo de 1 a "n".
- O custo de cada voo, representado por "c", deve estar no intervalo de 1 a 10^9.
- O parâmetro k, que determina a quantidade de menores caminhos a serem encontrados, deve estar no intervalo de 1 a 10.
### 1.3 Entrada de Dados

A entrada consiste em três inteiros: o número de cidades (vértices "n"), o número de voos (arestas "m") e o parâmetro k (quantidade de menores caminhos a serem encontrados). Esses dados são fornecidos em um arquivo de texto, que é passado como parâmetro ao executar o programa, por exemplo: `./prog -i input.txt -o output.txt`. Em seguida, o arquivo de entrada contém "m" linhas descrevendo os voos (arestas), cada linha contendo três inteiros: o vértice de partida (a), o vértice de destino (b) e o custo do vértice (c).

### 1.4 Saída de Dados

A saída consiste em k inteiros representando os preços dos k caminhos mais baratos, ordenados de acordo com seus preços. Esses resultados são escritos em um arquivo de texto, que também é especificado como parâmetro ao executar o programa.

### 1.5 Compilação do Programa

Antes de executar o programa, é necessário compilar o código-fonte. Certifique-se de estar dentro do diretório do repositório e utilize o comando `make`. Isso irá compilar o código e gerar um arquivo executável chamado `prog.exe`.

O programa utiliza as seguintes bibliotecas:

- **stdio.h**: Biblioteca padrão em C para operações de entrada/saída.
- **stdlib.h**: Biblioteca padrão em C para funções gerais, incluindo gerenciamento de memória dinâmica.
- **sys/time.h**: Biblioteca em C para operações de tempo.
- **sys/resource.h**: Biblioteca em C para gerenciamento de uso de recursos.
- **limits.h**: Define várias propriedades sobre os vários tipos de variáveis, usado aqui para definir o valor máximo do tipo inteiro.

Certifique-se de ter essas bibliotecas disponíveis em seu sistema ao compilar e executar o programa. Os testes foram realizados em sistemas Linux, e todas as bibliotecas fazem parte do pacote build-essentials, presente em todas as distribuições baseadas em debian.

### 1.6 Utilização do Programa

Após compilar o código-fonte, você pode executar o programa utilizando o arquivo executável gerado. Utilize os seguintes parâmetros pela linha de comando:

- **-i arquivo de entrada**: Especifica o arquivo de entrada contendo as informações sobre as cidades e os caminhos mágicos.
- **-o arquivo de saída**: Especifica o arquivo de saída onde serão escritos os preços dos k caminhos mais baratos.

Certifique-se de passar os parâmetros corretamente ao executar o programa, por exemplo: `./prog.exe -i input.txt -o output.txt`. Isso garantirá que o programa seja executado corretamente e que os resultados sejam salvos no arquivo de saída especificado.
## Soluções Propostas

Para resolver este problema, foram implementados dois algoritmos:

1. **Algoritmo para encontrar a distância dos k caminhos mais curtos, permitindo ciclos:** Este algoritmo calcula apenas a distância dos k caminhos mais curtos entre Mysthollow e Luminae, permitindo que os caminhos possam revisitar as mesmas cidades múltiplas vezes.
    
2. **Algoritmo para encontrar os k caminhos mais curtos sem ciclos:** Este algoritmo não só calcula a distância dos k caminhos mais curtos, mas também os próprios caminhos, garantindo que não haja revisitação de cidades.
    

Ambos os algoritmos foram implementados em módulos separados para garantir modularidade e facilitar a manutenção do código. Além disso, foi definido um arquivo de protótipos e definições contendo as estruturas de dados e protótipos das funções dos vários módulos. A compilação do programa utiliza o utilitário Make para facilitar o processo.

### 
## Avaliação de Desempenho

O programa implementado foi avaliado para várias entradas utilizando as funções getrusage e gettimeofday para medir os tempos de execução. Foram distinguindos os tempos de computação dos tempos de entrada e saída. Foram também analisados os tempos de usuário e os tempos de sistema e sua relação com os tempos de relógio para entender o desempenho do programa em diferentes cenários.

## Conclusão

Embarque nesta jornada mágica em busca dos k caminhos mais curtos de Mysthollow para Luminae. Com os algoritmos implementados, você estará pronto para desvendar os segredos dos caminhos místicos e completar sua busca. Que a orientação dos antigos ilumine seu caminho nesta aventura!

Esta documentação fornece uma visão geral do problema, da solução proposta e da utilização do programa, garantindo que os usuários possam compreender e utilizar efetivamente a solução implementada.



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
void Relaxation(int numVertices, int **vpc, int v1, Graph* graph, int *S);

#Feitos Kariny
- modifiquei a funçao GetAdjacentVertices para poder retornar uma struct do tipo Edge;
- fiz a funçao auxiliar Relaxation, usada no Djkistra;
- fiz o Djkistra;


#To do
- Testar outros casos.
- Armazenar os valores dos k's no output.txt.
- Fazer documentação.
- Fazer a analise de complexidade do algoritmo.
- Melhorias no código, se necessário(e se tiver tempo).

###OBS1 do programa: para que funcione corretamente, é necessário que se crie os vértices do grafo sem pular numeros.
###OBS2 do programa: provavelmente nao esta encontrando os menores caminhos que possuem ciclos.(passando na mesma aresta mais de uma vez).

###OBS2 funçao djkistra: os pesos dos grafos dos menores caminhos, são os pesos dos vertices anteriores somados. 
Ou seja, o custo minimo para chegar em cada vertice.
O peso do ultimo vértice, corresponde ao custo total do caminho.
