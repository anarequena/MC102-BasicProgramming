/* Nome: Ana Carolina R. Barbosa
 * RA: 163755
 * Laboratorio 05b - Distancia de Tchonsky */

#include <stdio.h>

#define MAX 101

int main () {
  char stringA[MAX], stringB[MAX];
  int a = 0, b = 0, c = 0, flag = 0, i, j, d = 0;
  
  scanf ("%s ", stringA);
  scanf ("%s", stringB);
  
  /* calcula o tamanho de A e B */
  while (stringA[a] != '\0')
      a++;
  while (stringB[b] != '\0')
      b++;
  
  /* transforma as letras maiusculas das strings em minusculas */
  for (i=0; i<a; i++){
    if ((stringA[i]>=65)&&(stringA[i]<=90))
      stringA[i] += 32;
  }
  for (i=0; i<b; i++){
    if ((stringB[i]>=65)&&(stringB[i]<=90))
      stringB[i] += 32;
  }
  
  /* calcula quantos caracteres há em comum nas strings */
  for (i=0; i < a; i++) {
      for (j=0; (stringB[j] != '\0')&&(flag==0); j++) {
	    if ((stringA[i] == stringB[j])){
	      flag++;
	      c++;
	      stringB[j] = '-';
	    }
      }
      flag = 0;   
  }
  
  /* calcula a Distancia de Tchonsky */ 
  d = (a + b) - (2*c); 
  
  /* imprime a Distancia de Tchonsky */
  printf ("Distancia de Tchonsky = %d\n", d);
  
  return 0;
}
      
    
