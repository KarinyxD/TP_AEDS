# K menores caminhos entre Mysthollow e Luminae

## 1. Introdução

O problema dos Caminhos de Mysthollow para Luminae consiste em encontrar os k menores custos entre duas cidades específicas. Aqui, k representa a quantidade de menores custos que o usuário deseja encontrar, variando de 1 a 10. É importante ressaltar que os custos dos menores caminhos encontrados podem incluir caminhos que possuem ciclos ou não, a depender da finalidade do uso do usuário.

Existem soluções para encontrar os k custos dos menores caminhos com ciclos, assim como para encontrar os k custos e/ou os k menores caminhos simples. Nesta documentação, focaremos em explicar a solução para encontrar os k menores custos de caminhos com ciclo. No entanto, também abordaremos um algoritmo para encontrar os caminhos simples mais curtos, garantindo uma compreensão completa das diferentes abordagens para o problema.

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

Para fornecer os dados de entrada ao programa, você deve criar um arquivo de texto chamado input.txt e colocá-lo na pasta "inputs-and-outputs". Este arquivo deve conter três inteiros: o número de cidades (vértices "n"), o número de voos (arestas "m") e o parâmetro k (quantidade de menores caminhos a serem encontrados). Por padrão, o programa espera encontrar esses dados na pasta "inputs-and-outputs".

Para executar o programa, utilize o comando ./prog -i input.txt -o output.txt, onde input.txt é o arquivo de entrada contendo as informações sobre as cidades e os voos, e output.txt é o arquivo de saída onde os resultados serão escritos. Certifique-se de que os arquivos de entrada e saída também estão na pasta "inputs-and-outputs".

### 1.4 Saída de Dados

Os resultados da execução do programa são salvos em um arquivo de texto chamado output.txt, localizado na pasta "inputs-and-outputs". Este arquivo contém k inteiros representando os preços dos k caminhos mais baratos, ordenados de acordo com seus preços. Ao executar o programa com o comando ./prog -i input.txt -o output.txt, os resultados serão automaticamente escritos neste arquivo de saída.

É importante observar que se o arquivo output.txt já existir, ele será sobrescrito com os novos resultados. Apagando o resultado obtido anteriormente.

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
- **Complexidade**: Eppstein otimiza o algoritmo - **EXCLUINDO** o primeiro Dijkstra - para um tempo de execução teórico de O(n + m + k), o nosso código com algumas alterações que vamos mencionar, apresenta desempenho muito semelhante.

**Referências**:

- [Publicação Original de David Eppstein em 1997](https://ics.uci.edu/~eppstein/pubs/Epp-SJC-98.pdf)
- [Implementação Referenciada](https://codeforces.com/blog/entry/102085) - Implementação de uma versão simplificada e otimizada para encontrar os k menores caminhos.

#### 2.2.2 Algoritmo de Yen
O algoritmo de Yen foi implementado em 1971, antes de Eppstein (1997), e é uma solução simples, relativamente fácil de ser compreendida. Ele consiste em encontrar o menor caminho utilizando Dijkstra e remover nós que fazem parte do menor caminho que possuam nós adjacentes.

![Yen's_K-Shortest_Path_Algorithm,_K=3,_A_to_F](https://github.com/KarinyxD/TP_AEDS/assets/121648163/6d71ed3e-3489-42af-8e45-7e947c08a714)

Também possui algumas particularidades que, dependendo do contexto, podem inviabilizar ou tornar o algoritmo de Yen uma boa escolha:
- **Caminhos simples**: Encontra caminhos simples, ou seja, assim como uma ferramenta GPS, mostra caminhos alternativos, e é um bom algoritmo para não só encontrar os custos, mas também os caminhos mais curtos.
- **Complexidade**: A complexidade é maior do que a do algoritmo de Eppstein devido ao maior número de chamadas ao algoritmo de Dijkstra. A complexidade de tempo de Yen's é O(KN(M + N log N)), onde N é o número de vértices e M é o número de arestas no grafo e K a quantidade de caminhos minimos. Para alcançar essa complexidade de tempo, é necessário utilizar uma Fibonacci heap no algoritmo de Dijkstra para melhorar seu pior caso, que possui complexidade quadrática, O(n^2).

**Referências**: [Algoritmo de Yen](https://en.wikipedia.org//wiki/Yen's_algorithm)


### 2.3 Explicando a solução baseada em Eppstein implementada
#### 2.3.1 Modifcações em Dijkstra e Pseucodigo
- O algoritmo de Dijkstra geralmente é implementado com listas de adjacência e uma heap binária em O(m log m). Esta versão modificada visita cada vértice no máximo k vezes, portanto, sua complexidade é O(km log km).
- Quando o k não apresenta valores muito altos essa abordagem por si só já é suficiente
```pseudocodigo
q = heap mínima vazia
count = array preenchido com 0
paths = array vazio
i = 0 //contador para o array paths
armazene (0, s) em q 
enquanto (count[t] < k) && (q != 0):
  (p, u) = desempilhe de q //vertice (u) de menor custo (p) da heap
  se count[u] == k: //se o contador de caminhos de u for igual k, vai pra próxima iteração
    continue
  count[u] += 1 //some +1 para o contador de caminhos de u
  se u == t: //se u for o vértice final encontrou um caminho de comprimento (p)
    paths[i] = p
    i++
  para cada aresta de saída (u, v, w) de u: //para cada vértice adjacente à u, guarde-o(v) na heap somando o custo de u com o peso da aresta de v (p + w) sendo o novo custo de v
    empilhe (p + w, v) em q
```
- count -> array que guarda a quantidade de caminhos encontrados para cada vértice, onde o índice corresponde ao numero do vértice.
- paths -> array que guarda os valores dos primeiros k caminhos encontrados.
- s -> vértice inicial.
- t -> vértice final.
- p -> custo do caminho.

#### 2.3.2 Melhorias que podem ser feitas
##### 2.3.2.1 Removendo todos os vertices do conjunto G que não alcançam a cidade final: 
Com essa modificação e mais algumas outras, é possivel manter a complexidade da solução anterior mas encontrando todos os k caminhos possiveis.
- 1. Com a utilização do grafo transposto, podemos encontrar a distância de todos os vertices em uma só execução de dijkstra, de complexidade assintótica O(m log m).
- 2. Na construção do grafo transposto é possivel ao utilizar uma lista de adjacência que faz com que a complexidade de inserção seja O(1), então a construção do grafo transposto leva O(m)
- 3. Ao realizar a remoção (pop) do menor custo da nossa heap, podem existir O(m) nós (caminhos), então levamos O(km log km) para remover k valores da nossa heap
- **Conclusão** A complexidade total é O(km log km). Isso nos permite encontrar todos os menores caminhos com a mesma complexidade de tempo do nosso código atual.
##### 2.3.2.2 Com a solução anterior uma nova possibilidade surge
- 1. O problema com G′ é que ele é ilimitado, podendo haver qualquer número de arestas saindo de um vértice. Se G′ fosse um grafo limitado com no máximo c arestas saindo de um vértice, k-pop levaria tempo O(kc log kc) reduzindo ainda mais a complexidade. Utilizando uma heap de grau maximo fixo reduzimos a complexidade do k-pop (retirada de menores caminhos da heap de menores caminhos).
##### 2.3.2.3 Com todas as melhorias mencionadas acima
- Chegamos até O(m+nlogn) de complexidade. Que é basicamente a complexidade mencionada na publicação de Eppstein. OBS: A complexidade O(n + m + k) mencionada no tópico 2.2.1 é **excluindo** o primeiro dijkstra.
- Caso queira uma explicação mais detalhada sobre essas melhorias recomendamos acessar [Implementação Referenciada](https://codeforces.com/blog/entry/102085)
#### 2.3.3 Sobre a implementação que está atualmente no nosso repositório
A versão que está implementada no nosso repositório é a primeira, que possui pseudocodigo explicativo. Listamos possiveis melhorias caso seja de interesse do usuário, para nós, como nosso k vai variar de 1 até 10, a solução mais simples é suficiente.

### 2.4 Explicando a solução baseada no algoritmo de Yen implementada
A alguns commits atrás estavamos utilizando a solução proposta por Yen. Acontece que por motivos de tempo, e manutenção necessária, optamos por remover essa implementação já que a mesma não nos atendia, pois precisavamos encontrar os k menores caminhos com ciclos. De toda maneira, é uma solução simples e que só demanda conhecimento previo do algoritmo de Djikstra. Recomendamos checar referências citadas no tópico 2.2.2

### 3. Detalhando código-fonte do repositório

### 4. Contribuição
Atualmente, não temos uma política rígida de contribuição, mas estamos sempre abertos e receptivos a colaborações da comunidade. Se você tiver sugestões de melhorias, correções de bugs ou novos recursos que gostaria de ver implementados, sinta-se à vontade para enviar uma pull request ou abrir uma issue no GitHub.

Pedimos gentilmente que, ao contribuir com código, você mantenha uma prática de comentários em inglês para facilitar a compreensão e a colaboração entre os membros da comunidade internacional.

Embora possamos não ser capazes de aceitar todas as contribuições de imediato, apreciamos muito o esforço e o interesse em ajudar a melhorar nosso projeto. Estaremos atentos a todas as pull requests e issues levantadas e faremos o possível para revisá-las e integrá-las ao projeto. 

### 5. Licensa de Uso
Licença MIT

Nossa permissão é concedida, gratuitamente, a qualquer pessoa que obtenha uma cópia deste software e dos arquivos de documentação associados, para negociar o Software sem restrições, incluindo, sem limitação, os direitos de usar, copiar, modificar, mesclar, publicar, distribuir, sublicenciar e/ou vender cópias do Software, e permitir que as pessoas a quem o Software é fornecido o façam, sujeitas às seguintes condições:

O aviso de direitos autorais acima e este aviso de permissão devem ser incluídos em todas as cópias ou partes substanciais do Software.

O SOFTWARE É FORNECIDO "NO ESTADO EM QUE SE ENCONTRA", SEM NENHUM TIPO DE GARANTIA, EXPRESSA OU IMPLÍCITA, INCLUINDO, MAS NÃO SE LIMITANDO ÀS GARANTIAS DE COMERCIALIZAÇÃO, ADEQUAÇÃO A UM FIM ESPECÍFICO E NÃO VIOLAÇÃO. EM NENHUM CASO OS AUTORES OU TITULARES DE DIREITOS AUTORAIS SERÃO RESPONSÁVEIS POR QUALQUER RECLAMAÇÃO, DANOS OU OUTRA RESPONSABILIDADE, SEJA EM AÇÃO DE CONTRATO, TORT OU DE OUTRA FORMA, DECORRENTE, FORA DE OU EM CONEXÃO COM O SOFTWARE OU O USO OU OUTRAS NEGOCIAÇÕES NO PROGRAMAS.

### 6. Autores
Caio Augusto Reis

Kariny Abrahão Reis