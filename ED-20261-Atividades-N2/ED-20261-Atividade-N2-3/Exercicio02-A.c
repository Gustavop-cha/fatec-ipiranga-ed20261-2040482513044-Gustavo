// RA: 2040482513044 - Gustavo Silva Paulino
#include <stdio.h>

float calcularMedia(float *vet, int n) {
    float soma = 0.0f;
    float *ptr = vet;
    for (int i = 0; i < n; i++) {
        soma += *ptr;
        ptr++; 
    }
    return soma / n;
}

void encontrarExtremos(float *vet, int n, float *maior, float *menor) {
    float *ptr = vet;
    *maior = *ptr;
    *menor = *ptr;
    ptr++;

    for (int i = 1; i < n; i++) {
        if (*ptr > *maior) {
            *maior = *ptr;
        }
        if (*ptr < *menor) {
            *menor = *ptr; 
        }
        ptr++;
    }
}

void normalizar(float *vet, int n) {
    float maximo;
    float minimo;
    encontrarExtremos(vet, n, &maximo, &minimo);

    if (maximo != 0.0f) {
        float *ptr = vet;
        for (int i = 0; i < n; i++) {
            *ptr = *ptr / maximo; 
            ptr++;
        }
    }
}

void imprimirVetor(float *vet, int n, const char *titulo) {
    printf("%s: [ ", titulo);
    float *ptr = vet;
    for (int i = 0; i < n; i++) {
        printf("%.2ff ", *ptr);
        ptr++;
    }
    printf("]\n");
}

int main() {
    float MyNotas[] = {7.5f, 3.2f, 9.8f, 6.0f, 5.5f, 8.1f};
    int tam = 6;

    printf("=== Dados Estatisticos das Notas ===\n");
    imprimirVetor(MyNotas, tam, "Notas Originais");

    float media = calcularMedia(MyNotas, tam);
    float maiorNota, menorNota;

    encontrarExtremos(MyNotas, tam, &maiorNota, &menorNota);

    printf("Media: %.2f\n", media);
    printf("Maior Valor: %.2f\n", maiorNota);
    printf("Menor Valor: %.2f\n", menorNota);

    printf("\n=== Executando Normalizacao ===\n");
    normalizar(MyNotas, tam);
    imprimirVetor(MyNotas, tam, "Notas Normalizadas");
    return 0;
}