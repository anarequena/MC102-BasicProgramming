/* Laboratorio 08b - Duzentos e Cinquenta e Cinco Tons de Cinza
 * Autor: Thierry Pinheiro Moreira
 * E-mail: thierrypin@gmail.com
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

/* Definindo tamanho maximo das imagens */
#define MAX_TAM 400

/* Le uma imagem em formato PGM a partir da entrada padrao.
 * Retorna 1 se a leitura for realmente de um arquivo PGM
 * e 0 caso contrario */
int ler_pgm(int img[][MAX_TAM], int *W, int *H, int *MaxV,
            int *F, double *C, double *Gama) {
    char nome_formato[3];
    int i,j;

    /* Le o formato da imagem. P2 indica o formato PGM */
    scanf("%s ", nome_formato);
    if (strcmp(nome_formato, "P2") != 0)
        return 0;

    /* Le o '#', que indica um comentario, e os numeros indicando
       o filtro e os parametros, se houver */
    scanf("# %d", F);

    if (*F == 1) {
        scanf("%lf %lf", C, Gama);
    }

    /* Le dimensoes e intensidade maxima da imagem */
    scanf("%d", W);
    scanf("%d", H);
    scanf("%d", MaxV);

    /* Le o valor de cada ponto da imagem */
    for (i = 0; i < (*H); i++) {
        for (j = 0; j < (*W); j++) {
            scanf("%d", &img[i][j]);
        }
    }

    return 1;
}

/* Escreve a imagem em formato PGM na saida padrao */
void escrever_pgm(int img[][MAX_TAM], int W, int H, int MaxV) {
    int i, j;

    /* Escreve os atributos da imagem */
    /* Tipo da imagem: P2 significa pgm*/
    printf("P2\n");

    /* Dimensoes e intensidade maxima da imagem */
    printf("%d %d %d\n", W, H, MaxV);

    /* Escreve os pontos da imagem */
    for (i = 0; i < H; i++) {
        printf("%d", img[i][0]);
        for (j = 1; j < W; j++) {
            printf(" %d", img[i][j]);
        }
        printf("\n");
    }
}

/* Transformacao de Potencia (gama) */
void potencia(int img[][MAX_TAM], int W, int H, int MaxV, 
              double c, double gama) {
    int i, j;

    /* Aplica o filtro a todos os pontos da imagem */
    for (i = 0; i < H; i++ ) {
        for (j = 0; j < W; j++) {
            /* Alterando valores dos pontos */
            img[i][j] = (int) floor(c * pow(img[i][j], gama));

            /* Verificando se o valor do ponto esta no intervalo
               [0..MaxV] */
            if (img[i][j] > MaxV)
                img[i][j] = MaxV;
            if (img[i][j] < 0)
                img[i][j] = 0;
        }
    }
}

/* Espelhamento */
void espelhamento(int img[][MAX_TAM], int W, int H) {
    int i, j;

    /* Copia a metade direita da imagem na metade esquerda */
    for (i = 0; i < H; i++ )
        for (j = 0; j < W/2; j++ )
            img[i][j] = img[i][W - j - 1];
}

/* Reducao de Ruidos com Filtro Gaussiano */
void reducaoRuido(int img[][MAX_TAM], int W, int H, int MaxV) {
    int aux[MAX_TAM][MAX_TAM];
    int i, j, fi, fj;
    double filtro[3][3];
    double soma;

    /* Filtro */
    filtro[0][0] = 1/16.;
    filtro[0][1] = 2/16.;
    filtro[0][2] = 1/16.;
    filtro[1][0] = 2/16.;
    filtro[1][1] = 4/16.;
    filtro[1][2] = 2/16.;
    filtro[2][0] = 1/16.;
    filtro[2][1] = 2/16.;
    filtro[2][2] = 1/16.;

    /* Aplica o filtro em todos os pontos da imegem, com excecao dos
       pontos da borda */
    for (i = 1; i < H - 1; i++) {
        for (j = 1; j < W - 1; j++) {
            soma = 0;

            /* Filtrando o ponto (i,j) e seus vizinhos */
            for (fi = 0; fi <= 2; fi++)
                for (fj = 0; fj <= 2; fj++)
                    soma += (img[i + fi - 1][j + fj - 1] * filtro[fi][fj]);

            /* O ponto (i,j) passa ter a intensidade do filtro gaussiano */
            aux[i][j] = (int) floor(soma);
        }
    }

    /* Imagem Final */
    for (i = 1; i < H - 1; i++) {
        for (j = 1; j < W - 1; j++) {
            img[i][j] = aux[i][j];
        }
    }
}

/* Rotacao 90 graus */
void rotacao(int img[][MAX_TAM], int W, int H) {
    int aux[MAX_TAM][MAX_TAM];
    int i, j;
    int novoI, novoJ;

    /* Rotaciona a imagem */
    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            /* Mudando posicao dos pixels */
            novoI = W - j - 1;
            novoJ = i;
            aux[novoI][novoJ] = img[i][j];
        }
    }

    /* Copia a imagem final */
    for (i = 0; i < W; i++) {
        for (j = 0; j < H; j++) {
            img[i][j] = aux[i][j];
        }
    }
}

int main() {
    /* Matriz que armazena os pixels da imagem */
    int img[MAX_TAM][MAX_TAM];
    /* Atributos da imagem */
    int W, H, MaxV, aux;
    /* Identificador do filtro a ser utilizado */
    int F;
    /* Parametros a serem passados para a potencia */
    double C, Gama;

    /* Le a imagem */
    if (ler_pgm(img, &W, &H, &MaxV, &F, &C, &Gama) != 1) {
        printf("Error: nao foi possivel ler a imagem\n");
        return 0;
    }

    /* Seleciona o filtro */
    switch (F) {
        case 1:
            potencia(img, W, H, MaxV, C, Gama);
            break;
        case 2:
            espelhamento(img, W, H);
            break;
        case 3:
            reducaoRuido(img, W, H, MaxV);
            break;
        case 4:
            rotacao(img, W, H);
            aux = W;
            W = H;
            H = aux;
            break;
    }

    /* Escreve a imagem */
    escrever_pgm(img, W, H, MaxV);

    return 0;
}
