#include <stdio.h>

int mdc(int a, int b){
  int aux;
  while (b > 0) {
    aux = b;
    b = a % b;
    a = aux;
  }
  
  return a;
  
  }


int main() {
  int m, n;
  
  printf("Entre com dois numeros inteiros positivos: ");
  
  scanf("%d %d", &m, &n);
  
  m = mdc(m,n);
  
  printf("MDC = %d\n", m);
  
  return 0;
}