/***********************************************************
 * Created: Dom 16 Fev 2014 23:01:20 BRT
 *
 * Author: Carla N. Lintzmayer, carlanl@ic.unicamp.br
 * Laboratorio 00: Baby Steps
 *
 ***********************************************************/
 
#include <stdio.h>

int main() {
    int a, b;

    /* Fazendo leitura dos dados */
    scanf("%d %d", &a, &b);

    /* Imprimindo resposta */
    printf("Soma: %d\n", a + b);
    printf("Diferenca: %d\n", a - b);
    printf("Multiplicacao: %d\n", a * b);
    printf("Divisao: %d\n", a / b);
    printf("Resto da divisao: %d\n", a % b);

    return 0;
}
