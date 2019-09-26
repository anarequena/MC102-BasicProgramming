/* Laboratorio 08b - Cinquenta Tons de Cinza
 * Nome: Ana Carolina R. Barbosa
 * RA: 163755 */

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
  
  /* percorre a matriz mudando a intensidade de acordo com a equaçao de potência */
  for (i=0; i<H; i++){
    for (j=0; j<W; j++){
      img[i][j] = floor(c*pow(img[i][j],gama));
      
      /* se o valor do pixel for maior que a intensidade máxima, iguala o pixel a MaxV */
      if (img[i][j] > MaxV)
	img[i][j] = MaxV;
    }
  }
}

/* Espelhamento */
void espelhamento(int img[][MAX_TAM], int W, int H) {
  int i, j;
  
  /* percorre a matriz até metade das colunas, igualando os valores da direita pelos da esquerda */
  for (i=0; i<H; i++){
    for (j=0; j<W/2; j++)
      img[i][j] = img[i][W -1 -j];
  }
}

/* Reducao de Ruidos com Filtro Gaussiano */
void reducaoRuido(int img[][MAX_TAM], int W, int H, int MaxV) {
  int i, j, img2[MAX_TAM][MAX_TAM];
  
  /* percorre a matriz e armazena o novo valor da intensidade em uma matriz auxiliar */
  for (i=1; i < (H-1); i++){
    for (j=1; j< (W-1); j++){
      img2[i][j] = floor (((1 * img[i-1][j-1]) + (2 * img[i][j-1]) + (1 * img[i+1][j-1]) + 
      (2 * img[i-1][j]) + (4 * img[i][j]) + (2 * img[i+1][j]) + (1 * img [i-1][j+1]) +
      (2 * img[i][j+1]) + (1 * img[i+1][j+1]))/16);
    }
  }
  
  /* copia os valores da matriz auxiliar na matriz original */
  for(i=1; i < (H-1); i++){
    for (j=1; j < (W-1); j++)
      img[i][j] = img2[i][j];
  }
}

/* Rotacao 90 graus */
void rotacao(int img[][MAX_TAM], int W, int H) {
  int i, j, img2[MAX_TAM][MAX_TAM];
  
  /* percorre a matriz e armazena o valor da coluna (x) da matriz original 
   * na linha (x -W -1) da matriz auxiliar */ 
  for (i=0; i<H; i++){
    for (j=0; j<W; j++)
      img2[W -1 - j][i]= img[i][j];
  }
  
  /* copia os valores da matriz auxiliar na matriz original */
  for(i=0; i<W; i++){
    for (j=0; j<H; j++)
      img[i][j] = img2[i][j];
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