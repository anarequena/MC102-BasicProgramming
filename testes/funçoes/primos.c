#include <stdio.h>

int testaPrimo(int candidato);
int valorAbs(int x);

int main() {
  int n, candidato = 2, primos = 0;
  
  printf("Numero de primos a serem calculados: ");
  
  scanf("%d", &n);
  
  n = valorAbs(n);
  
  while (primos < n) {
    if (testaPrimo(candidato)) {
      printf("%d\n", candidato);
      primos++;
    }
    candidato++;
  }
  
  return 0;
}

/* Calcula o valor absoluto de x */
int valorAbs(int x) {
  if (x < 0)
    return -x;
  else
    return x;
}

/* Verifica se um numero candidato eh primo */
int testaPrimo(int candidato) {
  int primo = 1, divisor;
  
  if ((candidato % 2) == 0)
    return (candidato == 2);
  
  for (divisor = 2; primo && (divisor <= candidato/2); divisor++){
    if ((candidato % divisor) == 0)
      primo = 0;
  }
    
  return primo;
}