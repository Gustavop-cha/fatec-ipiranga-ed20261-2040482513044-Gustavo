// RA: 2040482513044 - Gustavo Silva Paulino
#include <stdio.h>

int chamadas_busca = 0;
int chamadas_potencia = 0;
int buscaBinaria(int *vet, int inicio, int fim, int alvo) {
    chamadas_busca++;
    
    if (inicio > fim) {
        return -1; 
    }

    int meio = inicio + (fim - inicio) / 2;

    if (*(vet + meio) == alvo) {
        return meio;
    }
    
    if (*(vet + meio) > alvo) {
        return buscaBinaria(vet, inicio, meio - 1, alvo);
    } else {
        return buscaBinaria(vet, meio + 1, fim, alvo);
    }
}
long long potenciaRapida(long long base, int exp) {
    chamadas_potencia++;
    
    if (exp == 0) {
        return 1;
    }
    
    if (exp % 2 == 0) {
        long long metade = potenciaRapida(base, exp / 2);
        return metade * metade;
    } else {
        return base * potenciaRapida(base, exp - 1);
    }
}

int main() {
    int dados[] = {2, 5, 8, 12, 16, 23, 38, 45, 72, 91};
    int tam_dados = 10;
    int alvos[] = {23, 50, 2}; // Presente, Ausente, Primeiro elemento
    
    printf("=== TESTES DA BUSCA BINARIA RECURSIVA ===\n");
    for (int i = 0; i < 3; i++) {
        chamadas_busca = 0;
        int idx = buscaBinaria(dados, 0, tam_dados - 1, alvos[i]);
        printf("Buscando por %2d -> Indice retornado: %2d | Chamadas recursivas: %d\n", alvos[i], idx, chamadas_busca);
    }
    printf("\n=== TESTES DA POTENCIACAO RAPIDA ===\n");
    
    struct TestePot { long long b; int e; } testes_pot[] = {{2,10}, {3,7}, {5,0}, {7,12}};
    
    for (int i = 0; i < 4; i++) {
        chamadas_potencia = 0;
        long long res = potenciaRapida(testes_pot[i].b, testes_pot[i].e);
        printf("%lld^%d = %lld | Chamadas O(log n): %d\n", testes_pot[i].b, testes_pot[i].e, res, chamadas_potencia);
    }
    return 0;
}