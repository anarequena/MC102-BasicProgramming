/* Laboratorio 05a - Necronomicon
   Autor: Thierry Pinheiro Moreira
   Email: thierrypin@ic.unicamp.br
 */

#include <stdio.h>

int main() {

    /* Valores de entrada */
    char a[21], b[21];
    int n, i;

    /* Indices */
    int idxa, idxb;

    scanf("%d\n", &n);

    for (i = 0; i < n; i++) {
        /* Leitura e inicializacao dos dados */
        scanf("%s %s\n", a, b);

        idxa = 0;
        idxb = 0;

        /* Enquanto nenhuma das strings chegou ao fim, compara os caracteres.
           O indice de A so muda se o caractere for igual ao de B.
           Dessa forma, ao fim do laco, se A tiver chegado no fim,
           A e subsequencia de B.
         */
        while ((a[idxa] != '\0') && (b[idxb] != '\0')) {
            if (a[idxa] == b[idxb]) {
                idxa++;
            }
            idxb++;
        }

        if (a[idxa] == '\0') {
            printf("Sim\n");
        } else {
            printf("Nao\n");
        }
    }

    return 0;
}
