// RA: 2040482513044 - Gustavo Silva Paulino
#include <stdio.h>

int contador_global = 0;
void hanoi_contador(int n, char origem, char destino, char auxiliar, int nivel) {
    if (n == 1) {
        contador_global++; 
        return;
    }
    hanoi_contador(n - 1, origem, auxiliar, destino, nivel + 1);
    contador_global++;
    hanoi_contador(n - 1, auxiliar, destino, origem, nivel + 1);
}

int main() {
    for (int n = 1; n <= 6; n++) {
        contador_global = 0;
        hanoi_contador(n, 'A', 'C', 'B', 0);
        printf("Para n = %d -> Movimentos Contados: %d\n", n, contador_global);
    }
    return 0;
}