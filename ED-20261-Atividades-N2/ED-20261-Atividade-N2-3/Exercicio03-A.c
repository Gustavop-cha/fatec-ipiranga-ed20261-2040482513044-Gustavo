// RA: 2040482513044 - Gustavo Silva Paulino
#include <stdio.h>

void hanoi(int n, char origem, char destino, char auxiliar, int nivel) { // [cite: 125, 134]
    if (n == 1) {
        printf("%*sProfundidade %d: Mover disco 1 de %c para %c\n", nivel * 2, "", nivel, origem, destino);
        return;
    }
    hanoi(n - 1, origem, auxiliar, destino, nivel + 1); 
    printf("%*sProfundidade %d: Mover disco %d de %c para %c\n", nivel * 2, "", nivel, n, origem, destino); // [cite: 134]
    hanoi(n - 1, auxiliar, destino, origem, nivel + 1); 
}

int main() {
    printf("=== Teste Hanoi com n=1 ===\n");
    hanoi(1, 'A', 'C', 'B', 0);

    printf("\n=== Teste Hanoi com n=3 ===\n");
    hanoi(3, 'A', 'C', 'B', 0);

    printf("\n=== Teste Hanoi com n=4 ===\n");
    hanoi(4, 'A', 'C', 'B', 0);

    return 0;
}