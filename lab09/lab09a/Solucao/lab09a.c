/* Laboratorio 09a - A Batalha de Geonosis
   Autor: Javier Alvaro Vargas Munoz
   Email: ra153620@students.ic.unicamp.br
*/

#include <stdio.h>

#define MAX 50

int main() {
    /* variaveis da entrada */
    int M, N;
    int campo[MAX][MAX];

    /* variaveis auxiliares */
    int i, j, k, delta, t, droides, disparos;

    /* variaveis para o calculo da posicao e o numero de droides
       eliminados */
    int linha, coluna;
    int max_droides;
    int min_disparos;

    /* leitura do numero de linhas e colunas */
    scanf("%d %d", &M, &N);

    /* leitura do conteudo do campo de batalha */
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            scanf("%d", &campo[i][j]);

    /* inicializa o maior numero de droides a serem eliminados */
    max_droides = 0;
    min_disparos = M*N;

    /* testa todas as posicoes do campo de batalha e em busca da
       melhor para o AT-TE */
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++) {
            /* se a posicao (i,j) estiver livre, calcula o numero de
               droides que podem ser eliminados e o numero de
               disparos necessarios */
            if (campo[i][j] == 0) {
                
                disparos = 0;
                droides = 0;
                
                /* procura droides na i-esima linha */
                t = 0;

                for (k = 0; k < N; k++)
                    if (campo[i][k] == 1)
                        droides++;

                if (droides != t) 
                    disparos++;

                /* procura droides na j-esima coluna */
                t = droides;

                for (k = 0; k < M; k++)
                    if (campo[k][j] == 1)
                        droides++;

                if (droides != t)
                    disparos++;

                /* procura droides em uma diagonal */
                t = droides;

                if (i <= j)
                    delta = -i;
                else
                    delta = -j;

                while ((i+delta < M) && (j+delta < N)) {
                    if (campo[i+delta][j+delta] == 1)
                        droides++;
                    delta++;
                }

                if (droides != t)
                    disparos++;

                /* procura droides na outra diagonal */
                t = droides;

                if (M - i - 1 <= j)
                    delta = M - i - 1;
                else
                    delta = j;

                while ((i+delta >= 0) && (j-delta < N)) {
                    if (campo[i+delta][j-delta] == 1)
                        droides++;
                    delta--;
                }

                if (droides != t)
                    disparos++;

                /* verifica se achou uma posicao melhor */
                if ((max_droides < droides) || 
                    ((max_droides == droides) && 
                     (min_disparos > disparos))) {
                    max_droides = droides;
                    min_disparos = disparos;
                    linha = i;
                    coluna = j;
                }
            }
        }

    /* imprime a posicao do AT-TE, o maximo numero de droides que
       podem ser eliminados e o numero de disparos necessarios */
    printf("Posicao = (%d,%d)\n", linha, coluna);
    printf("Droids = %d\n", max_droides);
    printf("Disparos = %d\n", min_disparos);

    return 0;
}
