#include <stdio.h>

int mmc(int x, int y) {
  int aux, resultado;
  
  if (x < y) {
    aux = x;
    x = y;
    y = aux;
  }
  
  resultado = x;
  
  while (resultado % y)
    resultado += x;
  
  return resultado;
}

int main (){
  int m, n, mc;
  
  printf("Entre com dois numeros inteiros positivos: ");
  
  scanf("%d %d", &m, &n);
  
  mc = mmc(m,n);
  
  printf("Minimo multiplo comum: %d\n", mc);
  
  return 0;
}