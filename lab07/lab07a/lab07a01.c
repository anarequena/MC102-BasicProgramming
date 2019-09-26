#include <stdio.h>

#define MAXCAIXA 10
#define MAXCOMANDO 60
#define MAXPROGRAMA 9

int left (int pc, char posicao[MAXCAIXA][MAXCAIXA+1]) {
  int pl=0;
  
  if ((posicao[pl][pc-1]) >= 0)
    pc = pc-1;
  
  return pc;
}

int right (int pc, char posicao[MAXCAIXA][MAXCAIXA+1], int X) {
  int pl=0;
  
  if ((posicao[pl][pc+1]) < X)
    pc = pc + 1;

  return pc;
}

int main () {
  int X, Y, P, C, E, i, j=0, n=1, pl=0, pc=0, acidente=0;
  char braco='0', posicao[MAXCAIXA][MAXCAIXA+1], execucao[MAXCOMANDO], programa[MAXPROGRAMA][MAXCOMANDO+2];
  
  /* lê X(posições), Y(max empilhamento), P(n. de programas), C(max comandos) e E(n. de execucoes)*/
  scanf ("%d %d %d %d %d", &X, &Y, &P, &C, &E);
  
  /* lê o estado inicial das caixas */
  for (i=0; i<Y; i++)
    scanf ("%s", posicao[i]); 
  
  /* lê a ordem de execucao dos programas */
  for (i=0; i<=E; i++)
    scanf ("%c", &execucao[i]);
  
  /* lê os programas com seus respectivos os comandos */
  for (i=0; i<P; i++)
    scanf ("%s", programa[i]);
  
   /* verifica qual programa é para executar */
  for (i=0; i<=E; i++){ 
    n = execucao[i]; 
      /* executa o programa (n-1) lendo o caractere j */
      while((programa[n-1][j] != '*') && !(acidente)){
	if (braco == '0'){  
	  /* se o caractere for L, movimenta o braco para a esquerda da matriz posicao */
	  if (programa[n-1][j] == 'L'){
	    pc = left(pc, posicao);
	    j++
	  }
	  /* se o caractere for R, movimenta o braco para a direita da matriz posicao */
	  if (programa[n-1][j] == 'R'){
	    pc = right(pc, posicao, X);
	    j++;
	  }
	  /* se o caractere for D, movimento o braco para baixo até encontrar uma caixa */
	  if (programa[n-1][j] == 'D'){
	    while ((posicao[pl][pc]=='.') && ((pl+1) < Y)){
	      pl++;
	      if (posicao[pl][pc] != '.')
		braco = posicao [pl][pc];
	    }
	    pl=0;
	    j++;
	  }
	}
      }
    }
    n++;
  }
  
  printf ("%d\n", pc);
  
  return 0;
}