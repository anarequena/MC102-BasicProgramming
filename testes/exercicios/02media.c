#include <stdio.h>
#include <math.h>

int main () {
  double a, b, ma, mg, mh;
  
  printf ("Digite dois números inteiros:");
  scanf("%lf %lf", &a, &b);
  
  ma = (a+b)/2;
  mg = sqrt (a*b);
  mh = (1/a + 1/b)/2;
  
  printf ("Média Aritmética = %.2f \nMédia Geométrica = %.2f \nMédia Harmônica = %.2f\n", ma, mg, mh);
  
  return 0;
  
}
  