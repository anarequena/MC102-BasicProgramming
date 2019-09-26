/* Laboratorio 03a - Admiravel Mundo Novo
   Autor: Thierry Pinheiro Moreira
   Email: thierrypin@ic.unicamp.br
*/

#include <stdio.h>

int main() {
    /* Declaracao das variaveis auxiliares */
    int n, c, i, total = 0;
    char individuo;

    /* Vetor para armazenar o numero de individuos em cada casta */
    int casta[10];

    /* Leitura de dados */
    scanf("%d %d\n", &n, &c);

    /* Inicializacao do numero de individuos por casta */
    for (i = 0; i < c; i++)
        casta[i] = 0;

    /* Leitura de cada linha e contagem dos individuos */
    for (i = 0; i < n; i++) {

        /* le o primeiro individuo da linha */
        scanf("%c", &individuo);

        while (individuo != '\n') {
            total++;
                    
            /* Transformando digitos em numeros */
            casta[individuo - '0' - 1]++;

            /* Le o proximo individuo */
            scanf("%c", &individuo);
        }
    }
        
    printf("Total: %d individuos\n", total);
        
    /* Imprime o total de individuos em cada casta */
    for (i = 0; i < c; i++)
        printf("Total da casta %d: %d\n", i+1, casta[i]);
        
    /* Imprime a porcentagem de individuos em cada casta */
    for (i = 0; i < c; i++)
        printf("Percentual da casta %d: %.2f\n", i+1, ((double) casta[i])/ total * 100);
        
    return 0;
}
