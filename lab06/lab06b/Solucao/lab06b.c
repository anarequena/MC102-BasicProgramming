/* Laboratorio 06b - A Ameaca Fantasma
   Autor: Javier Alvaro Vargas Munoz
   Email: ra153620@students.ic.unicamp.br
*/

#include <stdio.h>

int main() {
    /* variaveis da entrada */
    int M, N;
    int recinto[100][100];

    /* variaveis auxiliares */
    int i, j, temp;
    int vazios = 0, contaminados = 1;

    /* variavel para o calculo do tempo */
    int T;

    /* leitura do tamanho do recinto */
    scanf("%d %d", &M, &N);

    /* leitura do conteudo do recinto e contagem de espacos vazios */
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &temp);

            /* se for uma parede */
            if (temp == 1) {
                recinto[i][j] = -2;
            } else {        
                /* se possui um aspersor */
                if (temp == 2) {
                    /* posicao sera contaminada no instante 1 */
                    recinto[i][j] = 1;
                } else {
                    recinto[i][j] = -1;
                    vazios++;
                }
            }
        }
    }

    /* inicializa o tempo e o total de espacos contaminados */
    T = 1;

    /* enquanto for possivel contaminar novas posicoes vazias */
    while ((contaminados > 0) && (vazios > 0)) {
        /* atualiza o tempo */
        T++;

        /* inicializa o numero de espacos contaminados no tempo T+1 */
        contaminados = 0;

        /* verifica todas as posicoes do recinto */
        for (i = 0; i < M; i++)
            for (j = 0; j < N; j++)
                /* para toda posicao vazia */ 
                if (recinto[i][j] == -1)
                    /* verifica se ela eh vizinha de uma posicao
                       contaminada */  
                    if (((i+1 < M) && (recinto[i+1][j] == T-1)) ||
                        ((j+1 < N) && (recinto[i][j+1] == T-1)) ||
                        ((i > 0) && (recinto[i-1][j] == T-1)) ||
                        ((j > 0) && (recinto[i][j-1] == T-1))) {

                        /* contamina o espaco vazio */ 
                        recinto[i][j] = T;

                        /* atualiza o numero de espacos vazios e
                           contaminados */
                        vazios--;
                        contaminados++;                    
                    }
    }

    /* se todos os espacos vazios foram contaminados, 
    imprimir o tempo */
    if (vazios == 0)
        printf("Tempo = %d\n", T);
    else
        printf("Perigo: Jedis podem estar vivos\n");

    return 0;
}
