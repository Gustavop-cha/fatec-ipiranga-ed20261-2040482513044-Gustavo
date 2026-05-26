// RA: 2040482513044 - Gustavo Silva Paulino
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *esq;
    struct No *dir;
} No;

No* inserir(No *raiz, int valor) {
    if (raiz == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        if (novo == NULL) return NULL;
        novo->dado = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    if (valor < raiz->dado) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->dado) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

int alturaNo(No *no) {
    if (no == NULL) {
        return -1; 
    }
    int altEsq = alturaNo(no->esq);
    int altDir = alturaNo(no->dir);
    return (altEsq > altDir ? altEsq : altDir) + 1;
}
No* buscarNo(No* raiz, int valor) {
    if (raiz == NULL || raiz->dado == valor) return raiz;
    if (valor < raiz->dado) return buscarNo(raiz->esq, valor);
    return buscarNo(raiz->dir, valor);
}

int profundidadeNo(No *raiz, int valor, int prof) {
    if (raiz == NULL) {
        return -1; 
    }
    if (raiz->dado == valor) {
        return prof;
    }
    if (valor < raiz->dado) {
        return profundidadeNo(raiz->esq, valor, prof + 1);
    } else {
        return profundidadeNo(raiz->dir, valor, prof + 1);
    }
}

int grauNo(No *no) {
    if (no == NULL) return 0;
    int grau = 0;
    if (no->esq != NULL) grau++;
    if (no->dir != NULL) grau++;
    return grau;
}

void percursoEmOrdemGrau(No *raiz) {
    if (raiz != NULL) {
        percursoEmOrdemGrau(raiz->esq);
        printf("No (%2d): Grau = %d\n", raiz->dado, grauNo(raiz));
        percursoEmOrdemGrau(raiz->dir);
    }
}

void liberarArvore(No *raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);
}

int main() {
    No *raiz = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 45, 65};
    int n = 11;

    for (int i = 0; i < n; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    /*
     * PARTE C - VERIFICACAO MANUAL E ARTE ASCII DA ABB:
     * * 50
     * /    \
     * 30      70
     * /  \    /  \
     * 20  40  60  80
     * / \   \  /
     * 10 25  45 65
     * * Validação Manual de 3 Nós:
     * 1) Nó 50: Raiz -> Profundidade Esperada = 0 (Calculada: 0) | Altura calculada pelas folhas mais distantes (10, 25, 45, 65) = 3.
     * 2) Nó 30: Filho esquerdo da raiz -> Profundidade = 1 | Altura = 2 (Caminho até as folhas 25 ou 45).
     * 3) Nó 10: Folha extrema esquerda -> Grau = 0 | Profundidade = 3 | Altura = 0.
     */

    printf("=== PARTE B - CONSULTAS ESTRUTURAIS DA ABB ===\n\n");

    int nos_alt[] = {50, 30, 70, 20, 10};
    printf("a) Altura de nos especificos:\n");
    for(int i = 0; i < 5; i++) {
        No* temp = buscarNo(raiz, nos_alt[i]);
        printf("   No %2d -> Altura: %d\n", nos_alt[i], alturaNo(temp));
    }
    int nos_prof[] = {50, 30, 70, 45, 10};
    printf("\nb) Profundidade de nos especificos:\n");
    for(int i = 0; i < 5; i++) {
        printf("   No %2d -> Profundidade: %d\n", nos_prof[i], profundidadeNo(raiz, nos_prof[i], 0));
    }
    printf("\nc) Grau de cada no (Sequencia Em-Ordem):\n");
    percursoEmOrdemGrau(raiz);
    printf("\nd) Altura total da arvore (raiz 50): %d\n", alturaNo(raiz));
    liberarArvore(raiz);
    return 0;
}