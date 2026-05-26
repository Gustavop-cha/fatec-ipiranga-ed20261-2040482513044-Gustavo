// RA: 2040482513044 - Gustavo Silva Paulino
#include <stdio.h>

int chamadas_potencia = 0;
long long potenciaRapida(long long base, int exp) {
    chamadas_potencia++;
    
    if (exp == 0) { 
        return 1;
    }
    
    if (exp % 2 == 0) { 
        long long metade = potenciaRapida(base, exp / 2);
        return metade * metade;
    } else { // Caso Recursivo Ímpar [cite: 169]
        return base * potenciaRapida(base, exp - 1);
    }
}

int main() {
    printf("=== PARTE B - POTENCIACAO RAPIDA O(log exp) ===\n"); 
    int bases[] = {2, 3, 5, 7};
    int exps[] = {10, 7, 0, 12};
    
    for (int i = 0; i < 4; i++) {
        chamadas_potencia = 0;
        long long res = potenciaRapida(bases[i], exps[i]);
        printf("%d^%d = %lld | Chamadas Computadas: %d\n", 
               bases[i], exps[i], res, chamadas_potencia);
    }
    return 0;
}