#include <stdio.h>

int main () {
  int a, b, c, soma;
  double media;
  
  scanf ("%d %d %d", &a, &b, &c);
  
  soma = a + b + c;
  
  media = (float)soma/3;
  
  printf ("media = %.2f\n", media);
  
  return 0;
  
}
  
