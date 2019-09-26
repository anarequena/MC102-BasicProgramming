/* Laboratorio 03b - O Enigma dos Guardioes Quanticos
   Autor: Gustavo Rodrigues Galvao
   Email: ggalvao@ic.unicamp.br
*/

#include <stdio.h>

int main() {
   /* variaveis da entrada */
   int n, a[100], b[100];
   /* variaveis auxiliares */
   int i, numGuardSinc, cont;

   /* leitura da entrada */
   scanf("%d", &n);

   for (i = 0; i < n; i++)
      scanf("%d %d", &a[i], &b[i]);

   /* calcula a quantidade de guardioes sinceros do cenario consistente 
      que possui o maior numero de guardioes sinceros e imprime */
   numGuardSinc = n + 1;

   do {
      numGuardSinc--;

      cont = 0;

      for (i = 0; i < n; i++)
	 if ((a[i] <= numGuardSinc) && (b[i] >= numGuardSinc))
	    cont++;
   } while (cont != numGuardSinc);

   printf("Numero de guardioes sinceros = %d\n", numGuardSinc);

   /* encontra o primeiro guardiao sincero e o imprime */
   i = 0;

   while ((a[i] > numGuardSinc) || (b[i] < numGuardSinc))
      i++;

   printf("Guardiao %d\n", i+1);

   return 0;
}
