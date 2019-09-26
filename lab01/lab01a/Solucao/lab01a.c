/* Laboratorio 01a - Coding Bad
   Autor: Thierry Pinheiro Moreira
   Email: thierrypin@ic.unicamp.br
 */

#include <stdio.h>
#include <math.h>

int main() {
    /* Valores de entrada */
    double C, i, M;
    int n;
    /* Montante final do calculo 1 */
    double montante_resultado;
    /* Quantidade de lotes do calculo 2 */
    int lotes_resultado;
    double lotes_intermediario;

    /* Leitura de dados */
    scanf("%lf %lf %d %lf", &C, &i, &n, &M);

    /* i eh uma porcentagem */
    i = i / 100.; 

    /* Calculo do montante segundo a formula: */
    /* C * (1 + i)^n */
    montante_resultado = pow(i + 1, n);
    montante_resultado = C * montante_resultado;

    /* Calculo da quantidade de lotes segundo a formula: */
    /* n = log_(1 + i) (M / P) */
    lotes_intermediario = log(M/C) / log(1 + i);
    lotes_resultado = ceil(lotes_intermediario);

    printf("Montante = %.2f\n", montante_resultado);
    printf("%d lote(s)\n", lotes_resultado);

    return 0;
}
