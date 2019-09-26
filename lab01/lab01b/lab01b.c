/* Nome: Ana Carolina R. Barbosa
 * RA: 163755
 * Laboratorio 01b - Conta de agua */

#include <stdio.h>
#include <math.h>

int main () {
  int c0, c1;
  double x, y;

  /* escaneia o consumo médio do ano anterior (c0) e o consumo atual (c1) */
  scanf ("%d %d", &c0, &c1);
  

  /* calcula valor original (x) do consumo atual (c1) */
  if ((c1 > 0) && (c1 <= 10))
    x = 17.34;
  else if ((c1>10) && (c1<=20))
    x = 17.34 + (c1-10)*2.41;
  else if ((c1>20) && (c1<=50))
    x = 17.34 + 10*2.41 + (c1-20)*3.70;
  else if (c1>50) 
    x = 17.34 + 10*2.41 + 30*3.70 + (c1-50)*4.43;
 
 
  /* calcula o valor final (y) de acordo com os descontos e aumentos de x */
  if (c1 > c0){ /* houve aumento */
    if (c1 < 1.2*c0)
      y = 1.4*x;
    else if (c1 >= 1.2*c0)
      y = 2*x;
  }
  else if (c1 < c0) { /* houve diminuiçao */
    if (c1 > 0.9*c0)
      y = x;      
    else if((c1 <= 0.9*c0) && (c1 > 0.85*c0))
      y = 0.9*x;
    else if ((c1 <= 0.85*c0) && (c1 > 0.8*c0))
      y = 0.8*x;
    else if (c1 <= 0.8*c0)
      y = 0.7*x;
  } 
  else { /* c1 = c0 */
      y = x;
  }
  
  /* Imprime os valores obtidos de x e y */
  printf ("Valor original = %.2f\nValor final = %.2f\n", x, y);
  

  return 0;
}

  