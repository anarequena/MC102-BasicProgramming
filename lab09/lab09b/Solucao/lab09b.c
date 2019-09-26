/* Laboratorio 09b - Peladeiros
 * Autor: Gustavo Rodrigues Galvao
 * E-mail: ggalvao@ic.unicamp.br
*/

#include <stdio.h>

/* Define os capitaes com base na soma das notas de cada jogador.
   Casos de empate sao implicitamente resolvidos pela ordem do loop */
void defineCapitaes(int n, int t, int capitaes[], double somaNota[], 
                    int escolhidos[]) {
   int i, j;
   double somaMax;
   
   for (i = 0; i < t; i++) {
      somaMax = -1;
      
      for (j = 0; j < n; j++)
         if ((escolhidos[j] == 0) && (somaNota[j] > somaMax)) {
            capitaes[i] = j;
            somaMax = somaNota[j];
         }

      escolhidos[capitaes[i]] = 1;
   }
}

/* Escolha dos times pelos capitaes com base na soma das notas de cada
   jogador.  Casos de empate sao implicitamente resolvidos pela ordem
   do loop */
void escolheTimes(int n, int t, int times[][25], double notas[][50],
                  int capitaes[], int escolhidos[]) {
   double notaMax;
   int i, j, k, capitao;

   /* o primeiro jogador de cada time eh o capitao */
   for (i = 0; i < t; i++) {
      times[i][0] = capitaes[i];
   }

   /* os demais jogadores sao definidos pelo processo de escolha
      alternada */
   for (k = 1; k < n/t; k++)
      for (i = 0; i < t; i++) {
         notaMax = -1;
         capitao = capitaes[i];
      
         for (j = 0; j < n; j++)
            if ((escolhidos[j] == 0) && (notas[capitao][j] > notaMax)) {
               times[i][k] = j;
               notaMax = notas[capitao][j];
            }

         escolhidos[times[i][k]] = 1;
      }
}

int main() {
   /* variaveis de entrada */
   int n, t;
   double notas[50][50];
   /* variaveis auxiliares */
   double somaNota[50];
   int i, j, times[10][25], capitaes[10], escolhidos[50];

   /* le a entrada */
   scanf("%d %d", &n, &t);
   
   for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
         scanf("%lf", &notas[i][j]);

   /* define as variaveis somaNota e escolhidos */
   for (j = 0; j < n; j++) {
      somaNota[j] = notas[0][j];

      for (i = 1; i < n; i++)
         somaNota[j] += notas[i][j];

      escolhidos[j] = 0;         
   }
   
   /* define capitaes e escolhe os times */
   defineCapitaes(n, t, capitaes, somaNota, escolhidos);
   escolheTimes(n, t, times, notas, capitaes, escolhidos);

   /* imprime a saida */
   for (i = 0; i < t; i++) {
      printf("Time %d:", i + 1);
      for (j = 0; j < n/t; j++)
         printf(" %d", times[i][j] + 1);
      printf("\n");
   }

   return 0;
}
