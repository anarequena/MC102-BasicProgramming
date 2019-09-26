#include <stdio.h>

int main () {
  int X, Y, n;
  int P[10];
  
  
  scanf ("%d %d", &X, &Y);
  
  for (n=0; n < X; n++) {
    scanf ("%d", &P[n]);
    printf ("P[%d] = %d\n", n, P[n]);
  }
  return 0;
}