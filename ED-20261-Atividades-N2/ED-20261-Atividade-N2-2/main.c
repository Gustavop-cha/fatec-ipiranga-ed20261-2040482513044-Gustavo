#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq; 
    struct No *dir;
} No;

int calcularAltura(No* n) {
    if (n == NULL) {
        return -1;
    }

    int h_esq = calcularAltura(n->esq);
    int h_dir = calcularAltura(n->dir);

    return 1 + (h_esq > h_dir ? h_esq : h_dir);
}

int obterFB(No* n) {
    if (n == NULL) return 0;
    return calcularAltura(n->esq) - calcularAltura(n->dir);
}

No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo) {
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

int main() {
    No* raiz = criarNo(20);
    raiz->esq = criarNo(10);
    raiz->esq->esq = criarNo(5);
    raiz->esq->esq->esq = criarNo(2);

    printf("--- Atividade N2-2: Calculo de FB ---\n");
    printf("Estrutura: 20 -> 10 -> 5 -> 2\n\n");

    int fb_raiz = obterFB(raiz);
    int altura_raiz = calcularAltura(raiz);

    printf("Altura da Raiz (No 20): %d\n", altura_raiz);
    printf("Fator de Balanceamento da Raiz: %d\n", fb_raiz);

    if (fb_raiz < -1 || fb_raiz > 1) {
        printf("Status: DESBALANCEADO!\n");
    } else {
        printf("Status: BALANCEADO.\n");
    }

    return 0;
}