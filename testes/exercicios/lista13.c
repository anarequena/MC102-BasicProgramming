#include <stdio.h>
#include <math.h>

int main () {
  int a, b, c;
  double delta, x1, x2;
  
  scanf ("%d %d %d", &a, &b, &c);
  
  delta = pow(b,2) - 4*a*c;
  
  if (delta < 0) {
    printf ("não há solução real\n");
  } else {
    x1 = (- b + sqrt(delta))/2*a;
    x2 = (- b - sqrt(delta))/2*a;
    printf ("as soluções são %.2f e %.2f\n", x1, x2);
  }
  
  return 0;
  
}