/* Laboratorio 10b - O Baile de Inverno
   Autor: Javier Alvaro Vargas Munoz
   Email: ra153620@students.ic.unicamp.br
*/

#include <stdio.h>

/* Troca o conteudo de duas variaveis inteiras */
void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* Calcula o valor absoluto de um numero dado */
int abs(int a) {
    if (a < 0)
        return -a;
    else
        return a;
}

/* Ordena um vetor por Selection Sort */
void ordena(int vetor[], int N) {
    int i, j;
    int id_min, min_val;

    /* Para cada posicao i do vetor... */
    for (i = 0; i < N; i++) { 
        /* ... procura pelo menor elemento no intervalo [i .. N-1] */
        id_min = i;
        min_val = vetor[i];

        for (j = i + 1; j < N; j++)
            if (vetor[j] < min_val) {
                id_min = j;
                min_val = vetor[j];
            }

        /* Troca os elementos de indice i e id_min */
        troca(&vetor[i], &vetor[id_min]);
    }
}

int main() {
    /* variaveis da entrada */
    int M, N, D;
    int homens[1000], mulheres[1000];

    /* variaveis auxiliares */
    int i = 0, j = 0;

    /* variavel para o calculo do maximo numero de duplas
       equilibradas */
    int duplas;

    /* leitura do numero de homens, mulheres e o valor D */
    scanf("%d %d %d", &M, &N, &D);

    /* leitura das habilidades de baile dos homens e mulheres */
    for (i = 0; i < M; i++)
        scanf("%d", &homens[i]);
    for (i = 0; i < N; i++)
        scanf("%d", &mulheres[i]);

    /* ordena os vetores de homens e mulheres */
    ordena(homens, M);
    ordena(mulheres, N);

    /*  inicializa o numero de duplas */
    duplas = 0;
    i = 0;
    j = 0;

    /* tenta formar duplas enquanto houver homens e mulheres */
    while ((i < M) && (j < N)) {
        if (abs(homens[i] - mulheres[j]) <= D) {
            i++;
            j++;
            duplas++;
        } else {
          if (homens[i] < mulheres[j])
            i++;
          else
            j++;
        }
    }

    /* imprime o maximo numero de duplas equilibradas */
    printf("Numero maximo de duplas equilibradas = %d\n", duplas);

    return 0;
}
