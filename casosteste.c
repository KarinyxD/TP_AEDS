#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WEIGHT 100000

int main() {
    int n = 1000; // número de vértices
    int m = 2 * n;  // número de arestas (aproximadamente)

    // Abre o arquivo para escrita
    FILE *outputFile = fopen("input2.txt", "w");
    if (outputFile == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    // Escreve a primeira linha da entrada no arquivo
    fprintf(outputFile, "%d %d %d\n", n, m, 5);

    // Inicializa a semente para geração de números aleatórios
    srand(time(NULL));

    // Gera as arestas aleatórias
    for (int i = 1; i <= n; i++) {
        int edges = rand() % (n - 1) + 1; // Número aleatório de arestas para cada vértice (pelo menos uma)
        for (int j = 0; j < edges; j++) {
            int destination = rand() % n + 1; // Vértice de destino aleatório
            int weight = rand() % MAX_WEIGHT + 1; // Peso aleatório entre 1 e MAX_WEIGHT
            fprintf(outputFile, "%d %d %d\n", i, destination, weight);
        }
    }

    // Fecha o arquivo
    fclose(outputFile);

    printf("Grafo gerado e salvo no arquivo: input.txt\n");

    return 0;
}