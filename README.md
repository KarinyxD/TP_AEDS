# K menores caminhos entre Mysthollow e Luminae

## 1. Introdução

O problema dos Caminhos de Mysthollow para Luminae consiste em encontrar os k menores custos entre duas cidades específicas. Aqui, k representa a quantidade de menores custos que o usuário deseja encontrar, variando de 1 a 10. É importante ressaltar que os custos dos menores caminhos encontrados podem incluir caminhos que possuem ciclos ou não, a depender da finalidade do uso do usuário.

Desenvolvemos soluções para encontrar os k custos dos menores caminhos com ciclos, assim como para encontrar os k custos e/ou os k menores caminhos simples. Nesta documentação, focaremos em explicar a solução para encontrar os k menores custos de caminhos com ciclo. No entanto, também abordaremos um algoritmo para encontrar os caminhos simples mais curtos, garantindo uma compreensão completa das diferentes abordagens para o problema.

![caminhos-simples-ciclos](https://github.com/KarinyxD/TP_AEDS/assets/121648163/3ee82b7b-46f3-49ba-8183-c5c0d357abdc)

### 1.1 Modelagem do Problema Utilizando Grafos

O problema dos Caminhos de Mysthollow para Luminae pode ser modelado de forma eficaz utilizando conceitos de grafos. Nesta modelagem, as cidades são representadas como nós e os caminhos entre elas como arestas direcionadas. É importante destacar que, no nosso caso, o grafo não deve possuir arestas negativas.

A utilização de grafos oferece diversas vantagens para resolver este problema. Primeiramente, permite uma representação visual intuitiva das conexões entre as cidades e dos caminhos disponíveis. Além disso, a estrutura de grafos facilita a aplicação de algoritmos eficientes para encontrar os k menores custos entre Mysthollow e Luminae. Um exemplo desses algoritmos é o clássico algoritmo de Dijkstra, que será adaptado para lidar com grafos direcionados e encontrar soluções para o problema.

Portanto, a modelagem do problema utilizando grafos oferece uma abordagem poderosa e flexível, permitindo explorar diversas estratégias e encontrar soluções eficientes para os Caminhos de Mysthollow para Luminae.

### 1.2 Restrições

As restrições impostas no problema dos Caminhos de Mysthollow para Luminae têm como objetivo garantir que o programa seja executado de forma eficiente e segura. Algumas dessas restrições têm justificativas específicas, como quantidades de bits reservados para tipos primitivos na linguagem C:

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
- **sys/resource.h**: Biblioteca em C para gerenciamento de uso de recursos, disponivel para sistemas linux
- **limits.h**: Define várias propriedades sobre os vários tipos de variáveis, usado aqui para definir o valor máximo do tipo inteiro.

Certifique-se de ter essas bibliotecas disponíveis em seu sistema ao compilar e executar o programa. Os testes foram realizados em sistemas Linux, e todas as bibliotecas fazem parte do pacote build-essentials, presente em todas as distribuições baseadas em debian.

### 1.6 Utilização do Programa

Após compilar o código-fonte, você pode executar o programa utilizando o arquivo executável gerado. Utilize os seguintes parâmetros pela linha de comando:

- **-i arquivo de entrada**: Especifica o arquivo de entrada contendo as informações sobre as cidades e os caminhos mágicos.
- **-o arquivo de saída**: Especifica o arquivo de saída onde serão escritos os preços dos k caminhos mais baratos.

Certifique-se de passar os parâmetros corretamente ao executar o programa, por exemplo: `./prog.exe -i input.txt -o output.txt`. Isso garantirá que o programa seja executado corretamente e que os resultados sejam salvos no arquivo de saída especificado.

## 2. Soluções Propostas

### 2.1 Conhecimento Prévio

Para entender as soluções propostas para o problema dos Caminhos de Mysthollow para Luminae, é necessário ter conhecimento prévio sobre os seguintes algoritmos:

- **Algoritmo de Dijkstra**: Utilizado para encontrar o caminho mais curto entre dois vértices em um grafo ponderado com arestas não negativas. Este algoritmo será adaptado e combinado com outras técnicas para encontrar os k menores custos entre Mysthollow e Luminae.
- **Heap binária**: Uma variação da estrutura de dados de heap

Esses conhecimentos prévios são essenciais para compreender as soluções propostas e como elas são implementadas para resolver o problema em questão.

### 2.2 Referências
Existem duas soluções bem populares para encontrar os k menores caminhos:
#### 2.2.1 Algoritmo de Eppstein
O Algoritmo de Eppstein (publicado em 1997) é uma abordagem eficiente para encontrar os k menores custos entre dois vértices em um grafo ponderado. Este algoritmo utiliza uma heap binária modificada como estrutura de dados principal. No entanto, apresenta algumas particularidades que a depender do contexto podem ser negativas:
- **Recuperação do Caminho**: Embora o algoritmo de Eppstein calcule eficientemente os k menores custos entre dois vértices em um grafo ponderado, ele apenas calcula os comprimentos dos caminhos, não os próprios caminhos. É possivel modifica-lo, mas seria necessário acompanhar as arestas laterais seguidas durante o processo, o que pode adicionar complexidade à implementação.
- **Sem Arestas Negativas**: Em grafos com ponderação negativa das arestas, o algoritmo de Dijkstra não pode ser aplicado para calcular as distâncias mínimas entre os vértices.
- **Caminhos com Ciclos**: É capaz de encontrar os caminhos mais curtos entre dois vértices, mesmo quando esses caminhos incluem ciclos. Isso significa que os k menores custos podem incluir caminhos idênticos mas que percorrem um ciclo pertencente ao caminho um numero diferente de vezes.
- **Complexidade**: Eppstein otimiza o algoritmo **- EXCLUINDO o primeiro Dijkstra -** para um tempo de execução teórico de O(n + m + k), o nosso código com algumas alterações que vamos mencionar, apresenta desempenho muito semelhante.
**Referências**:
- [Publicação Original de David Eppstein em 1997](https://ics.uci.edu/~eppstein/pubs/Epp-SJC-98.pdf)
- [Implementação Referenciada](https://codeforces.com/blog/entry/102085) - Implementação de uma versão simplificada e otimizada para encontrar os k menores caminhos.

#### 2.2.2 Algoritmo de Yen
O algoritmo de Yen foi implementado em 1971, antes de Eppstein (1997), e é uma solução simples, relativamente fácil de ser compreendida. Ele consiste em encontrar o menor caminho utilizando Dijkstra e remover nós que fazem parte do menor caminho que possuam nós adjacentes.

![Yen's K-Shortest Path Algorithm](https://en.wikipedia.org//wiki/Yen's_algorithm#/media/File:Yen's_K-Shortest_Path_Algorithm,_K=3,_A_to_F.gif)

Também possui algumas particularidades que, dependendo do contexto, podem inviabilizar ou tornar o algoritmo de Yen uma boa escolha:
- **Caminhos simples**: Encontra caminhos simples, ou seja, assim como uma ferramenta GPS, mostra caminhos alternativos, e é um bom algoritmo para não só encontrar os custos, mas também os caminhos mais curtos.
- **Complexidade**: A complexidade é maior do que a do algoritmo de Eppstein devido ao maior número de chamadas ao algoritmo de Dijkstra. A complexidade de tempo de Yen's é O(KN(M + N log N)), onde N é o número de vértices e M é o número de arestas no grafo e K a quantidade de caminhos minimos. Para alcançar essa complexidade de tempo, é necessário utilizar uma Fibonacci heap no algoritmo de Dijkstra para melhorar seu pior caso, que possui complexidade quadrática, O(n^2).

### 2.3 Explicando a solução baseada em Eppstein implementada
#### 2.3.1 Modifcações em Dijkstra e Pseucodigo
- O algoritmo de Dijkstra geralmente é implementado com listas de adjacência e uma heap binária em O(m log m). Esta versão modificada visita cada vértice no máximo k vezes, portanto, sua complexidade é O(km log km).
- Como nosso k, não apresenta valores muito altos, essa abordagem é eficiente para resolver diversos problemas de competições de programação.
```pseudocodigo
q = heap mínima vazia
count = array preenchido com 0
empilhe (0, s) em q
enquanto count[t] < k:
(l, u) = desempilhe q
se count[u] == k:
continue
count[u] += 1
se u == t:
encontrou um caminho de comprimento l
para cada aresta de saída (u, v, w) de u:
empilhe (l + w, v) em q
```