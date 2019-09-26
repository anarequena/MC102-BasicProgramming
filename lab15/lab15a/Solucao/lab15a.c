/* Laboratorio 15a - Walk-Bot - Part II
   Autor: Gustavo Rodrigues Galvao
   Email: ggalvao@ic.unicamp.br
*/

#include <stdio.h>
#include <stdlib.h>

/* Funcao recursiva que tenta atravessar o tabuleiro a partir da casa (i,j). 
   Retorna 1 caso tenha conseguido atravessar e 0 caso contrario */
int consegueAtravessar(int **tabuleiro, int m, int i, int j, int e, 
                       int **rastro) {
  int k, lin, col, consegue, casa, bit;

   /* verifica se conseguiu atravessar */
   if (j == m)
      return 1;

   /* verifica se a travessia deve ser interrompida porque:
      - a energia do robo acabou
      - o robo caiu em uma armadilha 
      - o robo ja visitou a casa (i,j) no percurso atual */
   if ((e < 1) || (tabuleiro[i][j] == 0) || (rastro[i][j]))
      return 0;
   
   consegue = 0;
   rastro[i][j] = 1;
   casa = tabuleiro[i][j];

   for (k = 0; (k < 4) && !consegue; k++) {

      bit = casa % 2;
      casa = casa / 2;

      /* verifica se o k-esimo bit da casa (i,j) eh 1 */
      if (bit) {
         lin = i;
         col = j;

         /* escolhe a proxima casa com base na posicao (k) do bit */
         switch (k) {
            case 0:
               col--;
               break;
            case 1:
               lin++;
               break;
            case 2:
               col++;
               break;
            case 3:
               lin--;
               break;
         }
           
         /* verifica se consegue atravessar da proxima casa */
         consegue = consegueAtravessar(tabuleiro, m, lin, col, e - 1, rastro);
      }
   }

   rastro[i][j] = 0;

   return consegue;
}

int main() {
   /* variaveis da entrada */
   int n, m, e, **tabuleiro;
   /* variaveis auxiliares */
   int i, lin, col, **rastro;

   /* leitura da entrada */
   scanf("%d %d %d", &n, &m, &e);

   tabuleiro = malloc(n * sizeof(int *));

   for (lin = 0; lin < n; lin++) {
      tabuleiro[lin] = malloc(m * sizeof(int));

      for (col = 0; col < m; col++)
         scanf("%d", &tabuleiro[lin][col]);
   }

   /* inicializa o rastro do Walk-Bot, usando 0 para indicar
      que uma casa nao foi visitada */
   rastro = malloc(n * sizeof(int *));

   for (lin = 0; lin < n; lin++) {
      rastro[lin] = malloc(m * sizeof(int));

      for (col = 0; col < m; col++)
         rastro[lin][col] = 0;
   }

   /* para cada casa (i,1), imprime uma linha do relatorio */
   for (i = 0; i < n; i++) {
      /* verifica se consegue atravessar comecando da casa (i,1) */
      if (consegueAtravessar(tabuleiro, m, i, 0, e, rastro))
         printf("Sim\n");
      else
         printf("Nao\n");
   }

   /* desaloca a memoria */
   for (lin = 0; lin < n; lin++) {
      free(tabuleiro[lin]);
      free(rastro[lin]);
   }

   free(tabuleiro);
   free(rastro);

   return 0;
}
