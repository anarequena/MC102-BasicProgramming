#include <stdio.h>

int main () {
  int a, b, i;

  scanf ("%d %d", &a, &b);
  
  i = a;
  a = b;
  b = i;
  
  printf ("%d %d\n", a, b);
  
  return 0;
}
  
