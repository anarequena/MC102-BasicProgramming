#include <stdio.h>
#include <stdlib.h>

int main() { 
  int x, y, *digint1, *digint2, i;
  char c;
  char *dig1, *dig2;
  
  /* le o tamanho do primeiro numero(x), o tamanho do segundo numero(y) e
   * a operacao a ser realizada(c) */
  scanf ("%d %d %c ", &x, &y, &c);
  
  /* aloca memória para os digitos de acordo com seus tamanhos */
  dig1 = malloc(x * sizeof(char));
  dig2 = malloc(y * sizeof(char));
  digint1 = malloc(x * sizeof(int));
  digint2 = malloc(y * sizeof(int));
  
  /* le o primeiro digito */
  for (i=0; i<x; i++)
    scanf ("%c", &dig1[i]);
  
  scanf (" ");
  
  /* le o segundo digito */
  for (i=0; i<y; i++)
    scanf ("%c", &dig2[i]);
  
  /* subtrai '0' dos caracteres do primeiro digito 
   * e transpoe o valor para um vetor de inteiros */
  for (i=0; i<x; i++){
    dig1[i] -= '0';
    digint1[i] = (int) dig1[i]; 
  }
  
  /* subtrai '0' dos caracteres dp segundo digito 
   * e transpoe o valor para um vetor de inteiros */
  for (i=0; i<y; i++){
    dig2[i] -= '0';
    digint2[i] = (int) dig2[i];
  }
  
  
  /* libera memoria alocada dos digitos */
  free(dig1);
  free(dig2);
  free(digint1);
  free(digint2);

  return 0;
}