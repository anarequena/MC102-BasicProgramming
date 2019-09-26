/* Laboratorio 14b - PaMonHa
   Autor: Thierry Pinheiro Moreira
   Email: thierrypin@ic.unicamp.br
 */

#include <stdio.h>

#define MAX_PARLAMENTARES 20

/* Funcao que calcula o custo de um arranjo de contratacoes.
   Caso o arranjo não tenha quantidade suficiente de parlamentares
   contratados, retorna -1 */
int calculaCustoArranjo(int n, int k, int custos[],
                        int influencias[][MAX_PARLAMENTARES], 
                        int partidarios[]) {

    /* Parlamentares contratados + influenciados */
    int comprometidos[MAX_PARLAMENTARES];
    int i, j;
    int valor = 0, numpar = 0;

    for (i = 0; i < n; i++)
        comprometidos[i] = 0;

    for (i = 0; i < n; i++) {
        /* Se o partidario for contratado, adiciona o custo dele ao
           valor total e verifica suas influências */
        if (partidarios[i]) {
            valor += custos[i];

            for (j = 0; j < n; j++) {
                if (influencias[i][j] && !comprometidos[j]) {
                    comprometidos[j] = 1;
                    numpar++;
                }
            }
        }
    }

    if (numpar >= k)
        return valor;
    else
        return -1;
}

/* Acha todos os arranjos considerando a contratacao ou nao de cada um
   dos parlamentar */
int arranjos(int n, int k, int custos[], int influencias[][MAX_PARLAMENTARES],
             int partidarios[], int t) {
    int menor, valor1, valor2;

    /* A recursao acaba quando ja se determinou se cada parlamentar vai ser
       contratado ou nao */
    if (t == n) {
        /* Calcula o custo do arranjo e se ele contrata parlamentares
           suficientes (retorna -1 caso contrario). */
        menor = calculaCustoArranjo(n, k, custos, influencias, partidarios);
    } else {
        partidarios[t] = 0;
        valor1 = arranjos(n, k, custos, influencias, partidarios, t+1);

        partidarios[t] = 1;
        valor2 = arranjos(n, k, custos, influencias, partidarios, t+1);

        /* Determina o menor valor */
        if ((valor2 == -1) || ((valor1 != -1) && (valor1 < valor2)))
            menor = valor1;
        else 
            menor = valor2; 
    }

    return menor;
}

int main() {
    int n, k;
    int custos[MAX_PARLAMENTARES];
    int influencia[MAX_PARLAMENTARES][MAX_PARLAMENTARES];
    int i, j;

    /* Vetor para armazenar os arranjos */
    int partidarios[MAX_PARLAMENTARES];
    /* Custo minimo para a contratacao de k parlamentares. */
    int minval;

    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++)
        scanf("%d", &custos[i]);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &influencia[i][j]);

    minval = arranjos(n, k, custos, influencia, partidarios, 0);

    printf("%d\n", minval);

    return 0;
}
