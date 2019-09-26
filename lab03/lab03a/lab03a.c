/* Nome: Ana Carolina R. Barbosa
 * RA: 163755
 * Laboratorio 03a - Admirável Mundo Novo */

#include <stdio.h>

int main () {
  
 int casta[8], n, c, ni, j, total = 0;
 double perc[8];
 char x;
 
 scanf ("%d %d ", &n, &c);
 
 for (j = 0; j <= 8; j++) { /*zera a contagem das castas */
   casta[j] = 0;
 }
 
 for (ni = 1; ni <= n; ni++){ /* lê cada linha fornecida */
   scanf ("%c", &x);
   while (x!='\n'){   /* contagem do total de individuos e do total em cada casta */
     total++;
     casta[x - '1']++;
     scanf ("%c", &x);
  }
 }
   
 printf ("Total: %d individuos\n", total); /* imprime o total de individuos */
  
 for (j = 0; j <= (c-1); j++){ /* imprime o total em cada casta */
    printf ("Total da casta %d: %d\n", j+1, casta[j]); 
  }
  
  for (j = 0; j <= (c-1); j++) { /* calcula e imprime o percentual de cada casta */
   perc[j] = (float) casta[j]/total;
   perc[j] *= 100;
   printf ("Percentual da casta %d: %.2f\n", j+1, perc[j]);
 }   
   
return 0;

}
	 