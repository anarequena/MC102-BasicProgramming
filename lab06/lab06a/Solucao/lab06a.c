/* Laboratorio 06a - Raio Sugestor
   Autores: Thierry Pinheiro Moreira
   Email: thierrypin@gmail.com
*/

#include <stdio.h>

#define MAX_TAM 50

int main() {
    /* Variaveis para armazernar a entrada */
    int m, n, r;
    int cidade[MAX_TAM][MAX_TAM];

    /* Variaveis para varrer a matriz */
    int i, j, k, l;
	
    int soma, max_soma = -1;

    /* Le a primeira linha da entrada */
    scanf("%d %d %d", &m, &n, &r);

    /* Le o numero de pessoas em cada quadra da cidade */
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cidade[i][j]);

    /* Verifica todas os possiveis lugares onde a maquina pode ser
       instalada */
    for (i = r; i < m-r; i++) {
        for (j = r; j < n-r; j++) {
            soma = 0;

            /* Conta o numero de pessoas afetadas pelo raio */
            for (k = i-r; k <= i+r; k++)
                for (l = j-r; l <= j+r; l++)
                    soma = soma + cidade[k][l];
			
            /* Atualiza a resposta */
            if (soma > max_soma)
                max_soma = soma;
        }
    }

    /* Imprime o numero maximo de pessoas afetadas que podem ser
       afetadas pelo raio sugestor */
    printf("%d\n", max_soma);

    return 0;
}
