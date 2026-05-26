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
    if (valor < raiz->dado) raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->dado) raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

No* buscarNo(No* raiz, int valor) {
    if (raiz == NULL || raiz->dado == valor) return raiz;
    if (valor < raiz->dado) return buscarNo(raiz->esq, valor);
    return buscarNo(raiz->dir, valor);
}

int alturaNo(No *no) {
    if (no == NULL) return -1;
    int altEsq = alturaNo(no->esq);
    int altDir = alturaNo(no->dir);
    return (altEsq > altDir ? altEsq : altDir) + 1;
}

int profundidadeNo(No *raiz, int valor, int prof) {
    if (raiz == NULL) return -1;
    if (raiz->dado == valor) return prof;
    if (valor < raiz->dado) return profundidadeNo(raiz->esq, valor, prof + 1);
    return profundidadeNo(raiz->dir, valor, prof + 1);
}

int grauNo(No *no) {
    if (no == NULL) return 0;
    int grau = 0;
    if (no->esq != NULL) grau++;
    if (no->dir != NULL) grau++;
    return grau;
}

int imprimirAncestralRecursivo(No *raiz, int valor) {
    if (raiz == NULL) return 0;
    if (raiz->dado == valor) return 1;

    // Se o valor for encontrado em uma das subárvores, o nó atual é um ancestral
    if (imprimirAncestralRecursivo(raiz->esq, valor) || imprimirAncestralRecursivo(raiz->dir, valor)) {
        printf("%d ", raiz->dado);
        return 1;
    }
    return 0;
}

void imprimirAncestral(No *raiz, int valor) {
    if (raiz == NULL || buscarNo(raiz, valor) == NULL) {
        printf("Nenhum");
        return;
    }
    if (raiz->dado == valor) {
        printf("Nenhum (Eh a Raiz)");
        return;
    }
    imprimirAncestralRecursivo(raiz, valor);
}

void percursoDescendentes(No *no) {
    if (no == NULL) return;
    percursoDescendentes(no->esq);
    printf("%d ", no->dado);
    percursoDescendentes(no->dir);
}

void imprimirDescendentes(No *raiz, int valor) {
    No *alvo = buscarNo(raiz, valor);
    if (alvo == NULL || (alvo->esq == NULL && alvo->dir == NULL)) {
        printf("Nenhum");
        return;
    }
    percursoDescendentes(alvo->esq);
    percursoDescendentes(alvo->dir);
}

int contarDescendentes(No *no) {
    if (no == NULL) return 0;
    return 1 + contarDescendentes(no->esq) + contarDescendentes(no->dir);
}
void relatorioNo(No *raiz, int valor) {
    No *alvo = buscarNo(raiz, valor);
    if (alvo == NULL) {
        printf("ERRO: O valor %d nao existe na arvore.\n\n", valor);
        return;
    }

    int prof = profundidadeNo(raiz, valor, 0);
    int alt = alturaNo(alvo);
    int grau = grauNo(alvo);
    int qtd_descendentes = contarDescendentes(alvo) - 1; 

    printf("+--------------------------------------------+\n");
    printf("| RELATORIO DO NO: %-25d |\n", valor);
    printf("+--------------------------------------------+\n");
    printf("  Profundidade  : %d\n", prof);
    printf("  Altura        : %d\n", alt);
    printf("  Grau          : %d\n", grau);
    
    printf("  Ancestrais    : ");
    imprimirAncestral(raiz, valor);
    printf("\n");
    
    printf("  Descendentes  : ");
    imprimirDescendentes(raiz, valor);
    printf("\n");
    
    printf("  Qtd Descend.  : %d\n", qtd_descendentes);
    printf("+--------------------------------------------+\n\n");
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

    printf("=== PARTE C - TESTE SISTEMATICO DE RELATORIOS ===\n\n");
    relatorioNo(raiz, 50); 
    relatorioNo(raiz, 30); 
    relatorioNo(raiz, 10); 
    relatorioNo(raiz, 70); 
    relatorioNo(raiz, 99); 
    liberarArvore(raiz);
    return 0;
}