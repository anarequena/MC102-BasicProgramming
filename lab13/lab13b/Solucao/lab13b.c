/* Laboratorio 13b - Quadtree
   Autor: Javier Alvaro Vargas Munoz
   Email: ra153620@students.ic.unicamp.br
*/

#include <stdio.h>

#define MAX 1024

/* Determinar se um setor quadrado da imagem tem o mesmo valor */
int homogenea(int img[MAX][MAX], int x1, int y1, int x2, int y2) {
    int i, j,  valor = img[x1][y1];

    for (i = x1; i <= x2; i++)
        for (j = y1; j <= y2; j++)
            if (img[i][j] != valor)
                return 0;

    return 1;
}

/* Calcula o numero de regioes */
int contar_regioes(int img[MAX][MAX], int x1, int y1, int x2, int y2) {
    /* variavel para a contagem de regioes */
    int regioes;
    /* variaveis para o calculo do ponto medio */
    int xm = (x1+x2)/2;
    int ym = (y1+y2)/2;
    
    /* verificar se a regiao eh homogenea */
    if (homogenea(img, x1, y1, x2, y2)) {
        regioes = 1;
    } else {
      /* contar regioes em cada quadrante */
        regioes = contar_regioes(img, x1, y1, xm, ym);
        regioes += contar_regioes(img, x1, ym+1, xm, y2);
        regioes += contar_regioes(img, xm+1, y1, x2, ym);
        regioes += contar_regioes(img, xm+1, ym+1, x2, y2);
    }

    return regioes;
}

int main() {
    /* variaveis de entrada */
    int N;
    int imagem[MAX][MAX];

    /* variaveis auxiliares */
    int i, j;

    scanf("%d", &N);

    /* leitura do conteudo da imagem */
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            scanf("%d", &imagem[i][j]);    

    /* imprime o numero de regioes */
    printf("Numero de regioes = %d\n", 
           contar_regioes(imagem, 0, 0, N-1, N-1));

    return 0;
}
