/* Nome: Ana Carolina R. Barbosa
 * RA: 163755
 * Laboratorio 04a - Cargo-Bot - Part I */

#include <stdio.h>

int main () {
  int X, Y, n, braco = 0, acidente = 0;
  int P[10];
  char C;
  
  scanf ("%d %d", &X, &Y); /* le o numero de posições e o numero maximo de caixas que podem ser empilhadas */
  
  for (n=0; n < X; n++) { /* le a quantidade de caixas inicialmente em cada posição */
    scanf ("%d", &P[n]);
  }
  
  n = 0; /* reinicia a posição do robo */
  
  do {
    scanf ("%c", &C); /* le o caractere fornecido enquanto esse for diferente de '*' */
    if (braco == 0){ /* se o braço estiver vazio, o braço se move de acordo com os comandos */
	if ((C == 'L') && ((n-1) >= 0)) /* o braço se move para a esquerda */
	  n = n - 1;
	if ((C == 'R') && ((n+1) < X)) /* o braço se move para a direita */
	  n++;
	if ((C == 'D') && (P[n] > 0)){ /* o braço pega uma caixa da posição correspondente */
	  P[n] = P[n] - 1;
	  braco++;
	}
      } else if (braco == 1){ /* se o braço conter 1 caixa, o braço se move se nao cruzar com uma posição empilhada ao maximo */
	if ((C == 'L') && ((n-1) >= 0)){ /* o braço se move para a esquerda se não ocorrer um acidente */
	  n = n - 1;
	  if (P[n] == Y)
	    acidente++;
	}
	if ((C == 'R') && ((n+1) < X)){ /* o braço se move para a direita se não ocorrer um acidente */
	  n++;
	  if (P[n] == Y)
	    acidente++;
	}
	if (C == 'D'){ /* o braço deixa a caixa na posição correspondente */
	  P[n] += 1;
	  braco = 0;
	}
      }
         
  } while ((C != '*') && !(acidente));
    
  
  
  if (acidente){ /* se ocorrer um acidente, imprime 'Um acidente ocorreu' */
    printf ("Um acidente ocorreu");
  } else { /* se não ocorreu acidentes, imprime o numero de caixas de cada posição ao final do processo */
    printf ("%d", P[0]);
    for (n = 1; n < X; n++) {
      printf (" %d", P[n]);
    }
  }
  
  printf ("\n");
  
  return 0;      
    
}