/* Nome: Ana Carolina R. Barbosa
 * RA: 163755
 * Laboratorio 02a - Coeficiente de Rendimento */

#include <stdio.h>

int main () {

int j, A = 4, B = 3, C = 2, D = 1, E = 0, soma1 = 0, s1, soma2 = 0;
char i;
double cr;

scanf (" %c", &i); /* lê o primeiro caractere (conceito) fornecido */

if (i == '*') { /* se o caractere fornecido for '*', imprime 'CR = Indefinido' */
  printf ("CR = Indefinido\n");
} 

else { /* se o caractere fornecido for diferente de '*', executa while */

  while (i != '*') { /* lê o número fornecido (cŕedito) */
    scanf ("%d", &j);
  
    if (i == 'A') /* multiplica o peso correspondentes a cada conceito aos créditos */
      s1 = A * j;
    else if (i == 'B') 
      s1 = B * j;
    else if (i == 'C')
      s1 = C * j;
    else if (i == 'D')
      s1 = D * j;
    else if (i == 'E')
      s1 = E * j;
  
    soma1 += s1; /* soma-se as multiplicações */ 
    soma2 += j; /* soma-se os créditos */
  
    cr = (float) soma1 / soma2; /* obtem-se cr pela divisão dos resultados de soma1 e soma2 */
  
    scanf (" %c", &i); /* lê o segundo caractere (conceito) fornecido */
      
}

 printf ("CR = %.4f\n", cr); /* imprime cr final */
 
} 


return 0;

}