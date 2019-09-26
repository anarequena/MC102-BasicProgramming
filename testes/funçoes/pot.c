#include <stdio.h>

int pot (int a, int b){
  int n=2, res = a;
  
  if (b==0)
    res = 1;
  
  while (n <= b){
    res *= a;
    n++;
  }
    
  return res;
  
}

int main () {
  int x, y, z;
  
  printf ("Entre com dois numeros reais positivos: ");
  
  scanf ("%d %d", &x, &y);
  
  z = pot(x,y);
  
  printf ("%d^%d = %d\n",x, y, z);
  
  return 0;
}
    