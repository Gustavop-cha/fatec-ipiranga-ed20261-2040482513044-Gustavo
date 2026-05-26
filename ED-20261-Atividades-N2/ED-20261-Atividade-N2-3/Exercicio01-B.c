// RA: 2040482513044 - Gustavo Silva Paulino
#include <stdio.h>

int main() {
    int v[] = {10, 20, 30, 40, 50};
    int n = 5;
    
    // O nome de um vetor decai para um ponteiro apontando para o seu primeiro elemento
    int *ptr = v; 

    printf("--- (a) Elementos e Enderecos ---\n");
    for (int i = 0; i < n; i++) {
        // *(ptr + i) avança 'i' posições de tamanho sizeof(int) a partir do ponteiro base
        printf("Elemento v[%d] = %d no endereco = %p\n", i, *(ptr + i), (void*)(ptr + i));
    }

    printf("\n--- (b) Soma dos Elementos ---\n");
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += *(ptr + i);
    }
    printf("Soma total: %d\n", soma);
    printf("\n--- (c) Inversao do Vetor In-Place ---\n");
    int *inicio = v;       // Aponta para o primeiro elemento (v[0])
    int *fim = v + (n - 1); // Aponta para o último elemento (v[4]) via aritmética de ponteiros

    while (inicio < fim) {
        // Troca os valores apontados por 'inicio' e 'fim' usando uma variável temporária local
        int temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        inicio++;
        fim--;
    }

    ptr = v;
    printf("Vetor invertido: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    return 0;
}