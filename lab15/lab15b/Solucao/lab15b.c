/* Laboratorio 15b - O o CR!
   Autor: Gustavo Rodrigues Galvao
   Email: ggalvao@ic.unicamp.br
*/
 
#include <stdio.h>

/* Retorna 1 se a permutacao esta ordenada e 0 caso contrario */
int eh_identidade(int permutacao[], int n) {
    int i;

    for (i = 1; i <= n; i++)
        if (permutacao[i] != i)
            return 0;
    
    return 1;
}

/* Troca a posicao do segmento de i a j com o segmento de j+1 a k */
void troca_segmentos(int permutacao[], int i, int j, int k) {
    int r, s, aux[10];

    /* Salva o segmento de i a j em aux */
    for (r = i; r <= j; r++)
        aux[r-i] = permutacao[r];

    /* Move o segmento de j+1 a k para a posicao i */
    for (r = j+1, s = i; r <= k; r++, s++)
        permutacao[s] = permutacao[r];

    /* Copia o segmento (em aux) para logo depois de onde o
     * segmento anterior foi copiado (valor jah esta em s) */
    for (r = 0; s <= k; r++, s++)
        permutacao[s] = aux[r];
}

/* Move o bloco de i a j para a posicao k. Supoe que k < i ou k > j */
void move_bloco(int permutacao[], int i, int j, int k) {
    if (k < i)
        troca_segmentos(permutacao, k, i-1, j);
    else
        troca_segmentos(permutacao, i, j, k);
}

/* Copia elementos de permut_origem para permut_dest */
void copia(int permut_origem[], int permut_dest[], int n) {
    int i;

    for (i = 0; i <= n+1; i++)
        permut_dest[i] = permut_origem[i];
}

/* Calcula o numero de breakpoints de uma permutacao */
int num_breakpoints(int permutacao[], int n) {
    int i, bp = 0;

    for (i = 0; i <= n; i++) {
        if (permutacao[i+1] - permutacao[i] != 1) {
            bp++;
        }
    }

    return bp;
}

/* Calcula a distancia de permutacao, colocando-a em melhor.
 * dist guarda o numero de movimentos de blocos que jah foram realizados
 * para chegar em permutacao */
int encontra_distancia(int permutacao[], int n, int melhor, int dist) {
    int i, j, k, permut_copia[12];
    
    /* Quando encontra a permutacao identidade, atualizar a melhor
     * distancia, caso a dist atual seja menor.
     * Parar, de qualquer forma, a recursao */
    if (eh_identidade(permutacao, n)) {
        if (dist < melhor)
            melhor = dist;
        return melhor;
    }
    
    /* Se a permutacao atual nao permite encontrar resultado melhor do
     * que o existente, parar a recursao */
    if ((dist + (num_breakpoints(permutacao, n)/3)) >= melhor)
        return melhor;
    
    /* Resolve recursivamente para todas as permutacoes filhas */
    i = 1;
    
    while (i <= n) {
        j = i;
 
        /* encontra o fim do bloco que comeca em i, armazenando em j */
        while ((j < n) && (permutacao[j+1] - permutacao[j] == 1))
            j++;

        /* cria permutacoes filhas movimentando o bloco de i a j */
        for (k = 1; k <= n; k++)
            if ((k < i) || (k > j)) {
                copia(permutacao, permut_copia, n);
                move_bloco(permut_copia, i, j, k);
                melhor = encontra_distancia(permut_copia, n, melhor, dist + 1);
            }

        i = j + 1;
    }
    
    return melhor;
}

int main() {
    int permutacao[12], i, n;
    int limite_superior, dist;

    /* le entrada */
    scanf("%d", &n);

    permutacao[0] = 0;

    for (i = 1; i <= n; i++)
        scanf("%d", &permutacao[i]);

    permutacao[n+1] = n+1;

    /* calcula a distancia de bloco e imprime */
    limite_superior = num_breakpoints(permutacao, n);
    
    dist = encontra_distancia(permutacao, n, limite_superior, 0);

    printf("%d\n", dist);

    return 0;
}
