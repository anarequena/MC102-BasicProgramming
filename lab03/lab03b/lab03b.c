/* Nome: Ana Carolina R. Barbosa
 * RA: 163755
 * Laboratorio 03b - O Enigma dos Guardiões Quânticos */

#include <stdio.h>

int main () {
  int N, a, b, ga[100], gb[100], g[100], nsinceros[100], n, j, k=0, verdadeiro;
  
  scanf ("%d", &N);
  
  for (j=1; j<=N; j++){ /* zera os contadores */ 
    nsinceros[j]=0;
  }
  
  for (n=1; n<=N; n++){ /* iguala os guardiões a 1 */
    g[n]=1;
  }
  
  for (n=1; n<=N; n++){ /* lê cada linha fornecida e seus intervalos */
    scanf ("%d %d", &a, &b);
    ga[n] = a;
    gb[n] = b;
    
    for (j=1; j<=N; j++) { /* conta-se a quant de vezes que cada numero de sinceros aparece nas linhas */  
      if ((j>=a) && (j<=b)) 
	nsinceros[j]++;
    }
  }
  
  for (j=1; j<=N; j++) { /* testa se a quant de vezes condiz com o numero de sinceros dito e encontra o maior valor de numero de sinceros */ 
    if (nsinceros[j] == j) 
	verdadeiro = nsinceros[j];
  }
  
  for (n=1; n<=N; n++){ /* encontra o primeiro guardiao sincero */
    if ((ga[n] <= verdadeiro) && (gb[n] >= verdadeiro)){
      g[n] = k;
      k++;
    }
  }
  
  printf ("Numero de guardioes sinceros = %d\n", verdadeiro); /* imprime o numero de guardioes sinceros */
  
  for (n=1; n<=N; n++){ /* imprime o primeiro guardiao sincero */
    if (g[n] == 0)
      printf ("Guardiao %d\n", n);
 }
 
  return 0;
}
      
      
      
    
  
  
