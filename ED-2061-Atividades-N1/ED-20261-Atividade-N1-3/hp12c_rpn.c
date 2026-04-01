#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    double X, Y, Z, T;
} PilhaHP;

void inicio(PilhaHP *p) {
    p->X = p->Y = p->Z = p->T = 0.0;
}

void exibiroEstado(PilhaHP *p) {
    printf("\n[T]: %8.2f", p->T);
    printf("\n[Z]: %8.2f", p->Z);
    printf("\n[Y]: %8.2f", p->Y);
    printf("\n[X]: %8.2f\n", p->X);
    printf("--------------------------\n");
}

void push(PilhaHP *p, double valor) {
    p->T = p->Z;
    p->Z = p->Y;
    p->Y = p->X;
    p->X = valor;
}

void operacao(PilhaHP *p, char op) {
    double resultado = 0;
    if (op == '+') resultado = p->Y + p->X;
    else if (op == '-') resultado = p->Y - p->X;
    else if (op == '*') resultado = p->Y * p->X;
    else if (op == '/') {
        if(p->X != 0) resultado = p->Y / p->X;
        else { printf("\nErro com a divisao"); return; }
    }

    p->X = resultado;
    p->Y = p->Z;
    p->Z = p->T;
    p->T = 0; 
}

int main() {
    PilhaHP minhaPilha;
    inicio(&minhaPilha);
    char expressao[100];
    printf("Digite sua expressao RPN (ex: 5 1 2 + 4 * + 3 -): ");
    fgets(expressao, 100, stdin);
    char *token = strtok(expressao, " \n");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&minhaPilha, atof(token));
        } 
        else if (strchr("+-*/", token[0])) {
            operacao(&minhaPilha, token[0]);
        }
        exibiroEstado(&minhaPilha);
        token = strtok(NULL, " \n");
    }

    printf("\nO resultado e: %.2f\n", minhaPilha.X);
    return 0;
}
