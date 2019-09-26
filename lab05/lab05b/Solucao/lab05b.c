/* Laboratorio 05b - Distancia de Tchonsky
   Autor: Gustavo Rodrigues Galvao
   Email: ggalvao@ic.unicamp.br
*/

#include <stdio.h>
#include <string.h>

int main() {
   /* variaveis da entrada */
   char A[100], B[100];
   /* variaveis auxiliares */
   int i, j, tamA, tamB, numCaracComum, freqCarac[26];

   /* leitura da entrada */
   scanf("%s", A);
   scanf("%s", B);

   tamA = strlen(A);
   tamB = strlen(B);

   /* calcula a frequencia de cada caractere da string A e 
      armazena no vetor freqCarac */
   for (i = 0; i < 26; i++)
      freqCarac[i] = 0;
   for (i = 0; i < tamA; i++) {
      if (A[i] >= 'a' && A[i] <= 'z')
         j = A[i] - 'a';
      else
         j = A[i] - 'A';
      freqCarac[j]++;
   }

   /* contabiliza o numero de caracteres em comum entre A e B 
      com base no vetor freqCarac */
   numCaracComum = 0;

   for (i = 0; i < tamB; i++) {
      if (B[i] >= 'a' && B[i] <= 'z')
         j = B[i] - 'a';
      else
         j = B[i] - 'A';

      if (freqCarac[j] > 0) {
          numCaracComum++;
          freqCarac[j]--;
      }
   }

   /* imprime a distancia de Tchonsky entre A e B */
   printf("Distancia de Tchonsky = %d\n", tamA + tamB - 2*numCaracComum);

   return 0;
}
