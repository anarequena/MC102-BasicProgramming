/* Nome: Ana Carolina R. Barbosa
 * RA: 163755
 * Laboratorio 02b - Dólares Élficos */

#include <stdio.h>


int main () {

int N, G, C, total, count1, count2 = 10000000, i, pot = 1, vez;

scanf ("%d %d %d", &N, &G, &C);

total = G * C; /* calcula o total de dólares élficos */


for (vez = 1; vez <= N; vez++)  {
  scanf ("%d", &i);
  
  while (pot*i <= total) { /* descobrir qual a maior potência de i menor que o total */
    pot *= i; 
  } 
  count1++; 
  total -= pot;
  
  while (total > 0) { 
     
    while (total >= pot) { /* quantidade de notas nessa casa de cambio */
      total -= pot;
      count1++;
    } 
       pot /= i;
  }
    
  total = G * C; 
  pot = 1;
  
  if (count1 < count2) { /* comparar a quantidade de cédulas da vez atual com a de menor valor anterior */
  count2 = count1;
  }
  
  count1 = 0;
  
} 

printf ("Numero minimo de notas = %d\n", count2); /* imprime o numero minimo de notas */

return 0;

}