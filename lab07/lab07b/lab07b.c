/* Nome: Ana Carolina R. Barbosa
 * RA: 163755
 * Laboratorio 07b - Walk-Bot - Part I */

#include <stdio.h>

#define MAX 50

int main () {
    int N, M, i, j, k, passo=0, loop=0, fim=0, aux[MAX][MAX];
    char tabuleiro[MAX][MAX+1];
    
    /* lê o numero de linhas (N) e colunas (M) */
    scanf ("%d %d", &N, &M);
    
    /* lê a matriz de caracteres, correspondente ao tabuleiro */
    for (i=0; i<N; i++)
      scanf ("%s", tabuleiro[i]);
    
    /* percorre o tabuleiro */
    for (k=0; k<N; k++){
      
      /* zera os elementos da matriz auxiliar */
      for (i=0; i<N; i++){
	for (j=0; j<M; j++)
	  aux[i][j]=0;
      }
      
      /* zera os contadores */
      j=0;
      i=k;
      loop=0;
      passo=0;
      fim=0;
      
      /* enquanto o programa nao encontrar um fim */
      while (!(fim)){
	/* se o elemento da matriz auxiliar for diferente de zero,
	 * termina o caminho e imprime o tamanho do loop */ 
	if (aux[i][j] != 0){
	  loop = passo - aux[i][j];
	  printf ("Loop de tamanho %d\n", loop);
	  fim++;
	}
	/* se o elemento do tabuleiro for 'D', movimenta o robo para baixo;
	 * armazena na matriz auxiliar o numero de passos do robo até a posicao */
	else if (tabuleiro[i][j] == 'D'){
	  aux[i][j] = passo;
	  passo++;
	  i++;
	} 
	/* se o elemento do tabuleiro for 'U', movimenta o robo para cima;
	 * armazena na matriz auxiliar o numero de passos do robo até a posicao */
	else if (tabuleiro[i][j] == 'U'){
	  aux[i][j] = passo;
	  passo++;
	  i--;
	} 
	/* se o elemento do tabuleiro for 'L', movimenta o robo para a esquerda;
	 * armazena na matriz auxiliar o numero de passos do robo até a posicao */
	else if (tabuleiro[i][j] == 'L'){
	  aux[i][j] = passo;
	  passo++;
	  j--;
	}
	/* se o elemento do tabuleiro for 'R'; 
	 * se o robo estiver na ultima coluna, o robo sai do tabuleiro e imprime o n. de passos;
	 * se nao, movimenta o robo para a direita;
	 * armazena na matriz auxiliar o numero de passos do robo até a posicao. */
	else if (tabuleiro[i][j] == 'R'){
	  if (j == (M-1)){
	    fim++; 
	    printf ("Saiu em (%d,%d) apos %d passo(s)\n", i+1, j+1, passo);
	  } else {
	    aux[i][j] = passo;
	    passo++;
	    j++;
	    
	  }
	} 
	/* se o elemento do tabuleiro for 'X', 
	 * termina o caminho e imprime o n. de passos até a armadilha; */
	else if (tabuleiro[i][j] == 'X'){
	  printf ("Armadilha em (%d,%d) apos %d passo(s)\n", i+1, j+1, passo);
	  fim++;
	}
      }
      
    }
    
    return 0;
}