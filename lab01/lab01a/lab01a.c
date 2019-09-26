/* Nome: Ana Carolina R. Barbosa
 * RA: 163755
 * Laboratorio 01a - Coding Bad */
 
#include <stdio.h>
#include <math.h>

int main () {
  int n1, n2;  /* n é um valor inteiro */
  double C, i, M1, M2;  /* C, i e M são valores reais */
  
  /* Escaneia os numeros fornecidos */
  scanf ("%lf %lf %d %lf", &C, &i, &n1, &M1);

  M2 = (pow(1+i/100,n1))*C;
  n2 = ceil(log(M1/C)/log(1+i/100));
  
  /* Imprime o resultado das equações acima */
  printf ("Montante = %.2f\n%d lote(s)\n", M2, n2);
  
  return 0;
}
