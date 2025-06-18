#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Protótipos
void swap(int* a, int* b, int index_a, int index_b);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void printArray(int arr[], int n, const char* message);

// Implementações das funções 
void printArray(int arr[], int n, const char* message) {
    printf("%s", message);
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* a, int* b, int index_a, int index_b) {
    printf("    -> Trocando arr[%d](%d) com arr[%d](%d)\n", index_a, *a, index_b, *b);
    int temp = *a;
    *a = *b;
    *b = temp;
}

// A função heapify é responsável por garantir que a sub-árvore com raiz no índice i seja um Max-Heap.
void heapify(int arr[], int n, int i) {
    printf("\n-- Chamando heapify(tamanho do heap=%d, raiz no índice=%d (valor %d)) --\n", n, i, arr[i]);
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;
    printf("   Analisando a sub-árvore com raiz arr[%d](%d).\n", i, arr[i]);
    // Verifica se o filho da esquerda existe e é maior que a raiz
    if (esquerda < n) {
        printf("   Comparando com o filho da esquerda arr[%d](%d).\n", esquerda, arr[esquerda]);
        if (arr[esquerda] > arr[maior]) {
            maior = esquerda;
        }
    }
    // Verifica se o filho da direita existe e é maior que o maior encontrado até agora
    if (direita < n) {
        printf("   Comparando com o filho da direita arr[%d](%d).\n", direita, arr[direita]);
        if (arr[direita] > arr[maior]) {
            maior = direita;
        }
    }
    // Se o maior não é a raiz, trocamos e continuamos heapificando
    if (maior != i) {
        printf("   O maior valor é arr[%d](%d), que não é a raiz. Precisamos trocar.\n", maior, arr[maior]);
        swap(&arr[i], &arr[maior], i, maior);
        printArray(arr, n, "    Array após a troca: ");
        heapify(arr, n, maior);
    } else {
        printf("   A raiz arr[%d](%d) já é o maior. Nenhuma troca necessária.\n", i, arr[i]);
    }
}
// A função heapSort constrói um Max-Heap a partir do array e depois ordena o array.
void heapSort(int arr[], int n) {
    printf("\n======================================================\n");
    printf("=== FASE 1: Construindo o Max-Heap Inicial ===\n");
    printf("======================================================\n");
    printf("Vamos transformar o array em um Max-Heap, começando pelo último nó pai e subindo até a raiz.\n");
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    printf("\n======================================================\n");
    printArray(arr, n, "HEAP INICIAL CONSTRUÍDO! O array agora é um Max-Heap: ");
    printf("======================================================\n\n");
    printf("\n======================================================\n");
    printf("=== FASE 2: Extraindo Elementos para Ordenar ===\n");
    printf("======================================================\n");
    printf("Agora, repetidamente movemos o maior elemento (a raiz) para o final e reconstruímos o heap com os elementos restantes.\n");
    for (int i = n - 1; i > 0; i--) {
        printf("\n--------------------------------------------------\n");
        printf("PASSO DE ORDENAÇÃO (elementos restantes no heap: %d)\n", i + 1);
        printf("Movendo a raiz atual (maior elemento) arr[0](%d) para o final da porção não ordenada arr[%d](%d).\n", arr[0], i, arr[i]);
        swap(&arr[0], &arr[i], 0, i);
        printArray(arr, n, "Array após mover a raiz para a posição final ordenada: ");
        printf("Reconstruindo o heap para os %d elementos restantes.\n", i);
        heapify(arr, i, 0);
    }
}

// Função principal do script CGI

int main() {
    // Configura o cabeçalho HTTP 
    printf("Content-Type: text/plain;charset=utf-8\n\n");

    // Verifica se o ambiente CGI está configurado corretamente
    char* query_string = getenv("QUERY_STRING");
    if (query_string == NULL) {
        printf("Erro: Nenhuma entrada recebida. Este script deve ser executado através de um servidor web.\n");
        return 1;
    }

    int n = 0;
    sscanf(query_string, "n=%d", &n);

    if (n <= 0) {
        printf("Erro: O tamanho do array 'n' não foi fornecido ou é inválido.\n");
        return 1;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Erro: Falha ao alocar memória para o array.\n");
        return 1;
    }
    
    // Extrai os valores do array da query string
    char* param = strtok(query_string, "&");
    int i = 0;
    while(param != NULL && i < n) {

        if (strncmp(param, "val", 3) == 0) {
            sscanf(param, "val%*d=%d", &arr[i]); 
            i++;
        }
        param = strtok(NULL, "&");
    }

    if (i < n) {
        printf("Erro: Número insuficiente de elementos do array recebidos. Esperado: %d, Recebido: %d\n", n, i);
        free(arr);
        return 1;
    }

    printf("Array original recebido:\n");
    printArray(arr, n, "");

    // Chama a função de ordenação 
    heapSort(arr, n);

    printf("\n\n================= RESULTADO FINAL =================\n");
    printArray(arr, n, "Array final ordenado: ");
    printf("===================================================\n");

    // Libera a memória alocada
    free(arr);

    return 0;
}