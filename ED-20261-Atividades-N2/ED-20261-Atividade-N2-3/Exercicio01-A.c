// RA: 2040482513044 - Gustavo Silva Paulino
#include <stdio.h>

void trocar(int *a, int *b) {
    // Verifica se os ponteiros não apontam para o mesmo endereço para evitar zerar a variável
    if (a != b) {
        // *a e *b utilizam o operador de desreferenciação para acessar/alterar os valores originais
        *a = *a + *b; // Soma os dois valores e armazena no endereço de 'a'
        *b = *a - *b; // Subtrai o novo 'b' do novo 'a', isolando o 'a' original em 'b'
        *a = *a - *b; // Subtrai o novo 'b' (que possui o 'a' original) do valor em 'a', isolando o 'b' original em 'a'
    }
}

int main() {
    int x = 15;
    int y = 42;

    // &x e &y utilizam o operador de referência para obter o endereço de memória das variáveis
    printf("--- Antes da Troca ---\n");
    printf("x: Valor = %d, Endereco = %p\n", x, (void*)&x);
    printf("y: Valor = %d, Endereco = %p\n\n", y, (void*)&y);

    // Passagem de parâmetros por referência através de ponteiros
    trocar(&x, &y);

    printf("--- Depois da Troca ---\n");
    printf("x: Valor = %d, Endereco = %p\n", x, (void*)&x);
    printf("y: Valor = %d, Endereco = %p\n", y, (void*)&y);

    return 0;
}