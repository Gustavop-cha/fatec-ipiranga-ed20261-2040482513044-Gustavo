#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

int calcularAltura(No* n) {
    if (n == NULL) {
        printf("    Filho NULL encontrado -> altura = -1\n");
        return -1;
    }

    printf("Calculando altura do No %d...\n", n->valor);

    int h_esq = calcularAltura(n->esq);
    int h_dir = calcularAltura(n->dir);

    int maiorAltura = (h_esq > h_dir ? h_esq : h_dir);
    int alturaFinal = 1 + maiorAltura;

    printf("=> No %d calculado: Esq: %d | Dir: %d | Altura Final: %d\n", 
            n->valor, h_esq, h_dir, alturaFinal);

    return alturaFinal;
}

int obterFB(No* n) {
    if (n == NULL) return 0;

    printf("\n=== Calculando FB do No %d (Raiz) ===\n", n->valor);

    printf("--- Subarvore Esquerda ---\n");
    int h_esq = calcularAltura(n->esq);

    printf("--- Subarvore Direita ---\n");
    int h_dir = calcularAltura(n->dir);

    int fb = h_esq - h_dir;

    printf("\nRESULTADO FB do No %d: %d (Esq) - %d (Dir) = %d\n", 
            n->valor, h_esq, h_dir, fb);

    return fb;
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

    printf("--- Atividade N2-2: Estrutura de Dados (FATEC) ---\n");
    printf("Cenario: Insercao de 20, 10, 5, 2\n");

    int fb_raiz = obterFB(raiz);

    printf("\n-------------------------------------------\n");
    if (fb_raiz < -1 || fb_raiz > 1) {
        printf("Status Final da Raiz: %d (DESBALANCEADO!)\n", fb_raiz);
    } else {
        printf("Status Final da Raiz: %d (BALANCEADO)\n", fb_raiz);
    }
    printf("-------------------------------------------\n");

    return 0;
}
