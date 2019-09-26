/* Laboratorio 10a - Tag Cloud
 * Autor: Andre Rodrigues Oliveira
 * Email: andre.oliveira@students.ic.unicamp.br
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Funcao que ordena pelo numero de frequencia e lexicograficamente */
void ordenaFrequencia(char **texto, int *contador, 
                      int num_palavras, int tam_max) {
    int i, j, auxi, maior;
    char *auxc;
    
    auxc = malloc(sizeof(char)*tam_max+1);

    /* Ordena com Selection Sort */
    for (i = 0; i < num_palavras; i++) {
        /* Inicialmente a palavra da posicao 'i' eh a com maior numero
           de ocorrencias encontrada */
        maior = i;

        for (j = i + 1; j < num_palavras; j++) {
            /* Se a palavra da posicao 'j' possui um numero maior de
               ocorrencias que a palavra da posicao 'maior', entao
               atualiza a variavel 'maior' */
            if (contador[j] > contador[maior])
                maior = j;
                
            /* Se a palavra da posicao 'j' possui a mesma quantidade
               de ocorrencias que a palavra da posicao 'maior', mas a
               palavra da posicao 'j' eh lexicograficamente menor que
               a palavra da posicao 'maior', entao atualiza a variavel
               'maior' */
            else if (contador[j] == contador[maior]) {
                for (auxi = 0; (texto[j][auxi] != '\0') && 
		               (texto[maior][auxi] != '\0') && 
                               (texto[j][auxi] == texto[maior][auxi]); auxi++);

                if ((texto[j][auxi] == '\0') || 
                    (texto[j][auxi] < texto[maior][auxi])) {
                    maior = j;
                }
            }
        }

        /* Se os valores de 'i' e 'maior' sao diferentes, troca as
           palavras e os contadores de 'i' e 'maior' de lugar */
        if (i != maior) {
            auxi = contador[i];
            contador[i] = contador[maior];
            contador[maior] = auxi;

            strcpy(auxc,texto[i]);
            strcpy(texto[i],texto[maior]);
            strcpy(texto[maior],auxc);
        }
    }
    
    free(auxc);
}

/* Funcao que incrementa o contador de uma palavra, se ela ja existe
   no vetor texto, ou, caso contrario, adiciona a palavra no vetor
   texto (com contador igual a 1) e incrementa o numero de palavras */
void incrementa_ou_adiciona(char *aux, char **texto, int *contador, 
                            int *num_palavras) {
    int i = 0;

    while ((i < *num_palavras) && (strcmp(aux, texto[i]) != 0))
        i++;
    
    if (i < *num_palavras) {
        contador[i]++;
    } else {
        contador[i] = 1;
        strcpy(texto[i], aux);
        (*num_palavras)++;
    }
}

int main() {
    char *aux, **texto;
    int i, num_palavras = 0, num_dist, min_ocorr, tam_min, tam_max, *contador;
    
    /* Leitura do numero maximo de palavras distintas no texto, do
       numero minimo de ocorrencias para uma palavra ser considerada,
       do tamanho minimo das palavras a serem consideradas e do
       tamanho maximo de cada palavra */
    scanf("%d %d %d %d\n", &num_dist, &min_ocorr, &tam_min, &tam_max);
    
    /* Aloca os vetores e contadores */
    aux = malloc(sizeof(char)*tam_max+1);
    contador = malloc(sizeof(int)*num_dist);
    texto = malloc(sizeof(char*)*num_dist);
    for (i = 0; i < num_dist; i++)
        texto[i] = malloc(sizeof(char)*tam_max+1);

    /* le todas as palavras da entrada e, se ela for maior ou igual a
       tam_min, chama a funcao que incrementa ou adiciona a palavra no
       vetor texto, atualizando o total de palavras no vetor texto */
    scanf("%s", aux);

    while (strcmp(aux, "*") != 0) {
        if (strlen(aux) >= tam_min)
            incrementa_ou_adiciona(aux, texto, contador, &num_palavras);
     
        scanf("%s", aux);
    }
    
    /* Ordena as palavras do vetor texto pela suas frequencias no texto */
    ordenaFrequencia(texto, contador, num_palavras, tam_max);
    
    /* Imprime em ordem decrescente as palavras e suas frequencias no
       texto, enquanto o numero de frequencias for maior que min_ocorr */
    for (i = 0; (contador[i] >= min_ocorr) && (i < num_palavras); i++)
        printf("%s %d\n", texto[i], contador[i]);
    
    /* Desaloca os vetores */
    free(aux);
    free(contador);
    for (i = 0; i < num_dist; i++)
        free(texto[i]);
    free(texto);
    
    return 0;
}
