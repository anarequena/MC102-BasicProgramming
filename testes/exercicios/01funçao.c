#include <stdio.h>
#include <math.h>

int main () {
  int a, b, c, x, y;
  a = 1;
  b = 1;
  c = 5;
  
  printf("Entre com x");	
  scanf("%d", &x);
  
  y = a*(pow(x,2)) + b*x + c;
  
  printf("O valor de f(%d) é %d\n", x, y );
  
  return 0;
}
  