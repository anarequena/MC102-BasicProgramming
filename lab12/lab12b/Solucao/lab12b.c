/* Laboratorio 12b - Bola de Ouro
   Autor: Javier Alvaro Vargas Munoz
   Email: ra153620@students.ic.unicamp.br
*/

#include <stdio.h>
#include <string.h>

/* Tamanho maximo do nome do jogador */
#define MAXNOME 26
/* Tamanho maximo do nome dos arquivos de entrada/saida */
#define MAXNOMEARQ 101
/* Numero maximo de jogadores */
#define MAXJOGADORES 40

/* Jogador:
 * nome = nome do jogador
 * C1 = numero de gols
 * C2 = numero de assistencias
 * C3 = numero de dribles feitos
 * C4 = numero de gols contra
 * C5 = numero de cartoes vermelhos
 * C6 = numero de cartoes amarelos
 */
struct Jogador {
    char nome[MAXNOME];
    int C1;
    int C2;
    int C3;
    int C4;
    int C5;
    int C6;
};

typedef struct Jogador Jogador;

/* Leitura do arquivo binario das estatisticas dos jogadores */
void lerArqEstatisticas(char nomearq[], Jogador J[], int *numJog) {
    FILE *arq = fopen(nomearq, "rb");

    if (arq  == NULL) { 
        printf("Falha na criacao do arquivo.\n");
        return;
    }

    /* Lendo numero de jogadores */
    fread(numJog, sizeof(int), 1, arq);
    /* Lendo todas as estatisticas dos jogadores */
    fread(&J[0], sizeof(Jogador), *numJog, arq);
    
    fclose(arq);
}

/* Atualiza as estatisticas de un jogador */
void atualizaEstatistica(Jogador *J, int numJog, char nome[], 
                         int C1, int C2, int C3, int C4, int C5, int C6) {
    int i = 0;

    /* procura posicao do jogador */
    while ((i < numJog) && (strcmp(J[i].nome, nome) != 0))
        i++;

    /* Atualiza o valor de cada estatistica */
    J[i].C1 += C1;
    J[i].C2 += C2;
    J[i].C3 += C3;
    J[i].C4 += C4;
    J[i].C5 += C5;
    J[i].C6 += C6;
}

/* Troca dois jogadores de lugar */
void trocaJogadores(Jogador *X, Jogador *Y) {
    Jogador Z = *X;
    *X = *Y;
    *Y = Z;
}

/* Determina o jogador com maior pontuacao */
int obterMelhorJogador(Jogador J[], int numJog, 
                       int W1, int W2, int W3, 
                       int W4, int W5, int W6) {
    int max, indice = 0, i, pontuacao;

    max = J[0].C1*W1 + J[0].C2*W2 + 
          J[0].C3*W3 - J[0].C4*W4 - 
          J[0].C5*W5 - J[0].C6*W6;

    for (i = 1; i < numJog; i++) {
        pontuacao = J[i].C1*W1 + J[i].C2*W2 + 
                    J[i].C3*W3 - J[i].C4*W4 - 
                    J[i].C5*W5 - J[i].C6*W6;

        if ((pontuacao > max) || 
            ((pontuacao == max) && 
             (strcmp(J[i].nome, J[indice].nome) < 0))) {
            indice = i;
            max = pontuacao;
        }
    }

    return indice;
}

/* Saida em arquivo binario */
void escreveEstatisticas(Jogador J[], int numJog, char nomeArqSaida[]) {
    FILE *f = fopen(nomeArqSaida, "wb");

    /* Escrevendo as estatisticas atualizadas dos jogadores  */
    fwrite(&numJog, sizeof(int), 1, f);
    fwrite(&J[0], sizeof(Jogador), numJog, f);
    fclose(f);
}

int main(int argc, char **argv) {
    /* Nome do arquivo binario com as estatisticas */
    char nomeArqEstat[MAXNOMEARQ];
    /* Nome do arquivo binario de saida */
    char nomeArqSaida[MAXNOMEARQ];

    /* Variaveis para a leitura da entrada padrao */
    int W1, W2, W3, W4, W5, W6, R, N, i, j;
    int C1, C2, C3, C4, C5, C6;
    char nome[MAXNOME];

    /* Variaveis para a leitura do arquivo binario */
    int numJog = 0;
    Jogador J[MAXJOGADORES];

    /* Variavel para armazenar os indices dos finalistas */
    int finalista;
    
    /* Lendo os nomes dos arquivos binarios */
    strcpy(nomeArqEstat, argv[1]);
    strcpy(nomeArqSaida, argv[2]);   

    /* Lendo o arquivo binario */
    lerArqEstatisticas(nomeArqEstat, J, &numJog);

    /* Lendo os pesos de cada estatistica e o numero de rodadas */
    scanf("%d %d %d %d %d %d\n%d", &W1, &W2, &W3, &W4, &W5, &W6, &R);

    /* Lendo os resultados de cada rodada e atualizando as estatisticas */
    for (i = 0; i < R; i++) {
        scanf("%d", &N);
        for (j = 0; j < N; j++) {
            scanf("%s %d %d %d %d %d %d", nome, 
                  &C1, &C2, &C3, &C4, &C5, &C6);
            atualizaEstatistica(J, numJog, nome, C1, C2, C3, C4, C5, C6);
        }
    }

    /* Saida em arquivo binario */
    escreveEstatisticas(J, numJog, nomeArqSaida);

    /* Determina os jogadores finalistas */
    for (i = 0; i < 3; i++) {
        finalista = obterMelhorJogador(J, numJog - i, W1, W2, W3, W4, W5, W6);
        
        printf("%s\n", J[finalista].nome);

        trocaJogadores(&J[finalista], &J[numJog - i - 1]);
    }
    
    return 0;
}
