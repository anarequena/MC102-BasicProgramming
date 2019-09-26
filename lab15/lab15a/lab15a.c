/* Ana Carolina Requena Barbosa
 * RA: 163755
 * Laboratorio 15a - Walk-Bot - Part II */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int left, down, right, up;
} Tabuleiro;

/* Travessia do robo pelo tabuleiro */
void travessia (int n, int m, int i, int j, int energia, int passo, 
		int *saida, Tabuleiro **tabuleiro, int **passos) {
  /* Se a energia acabar, termina o programa */
  if(energia == 0){
    return;
  }
  
  /* Se o comando for para a direita, executa */
  if(tabuleiro[i][j].right == 1){
    /* se o robo estiver no extremo direito do tabuleiro, termina o programa */
    if(j == m-1){
      *saida = 1;
      return;
    } 
    /* caso contrario, verifica se ja esteve na posicao a direita antes;
     * se nao, move-se para a direita */
    else if (passos[i][j+1] == 0){
      passos[i][j+1] = passo + 1;
      travessia(n, m, i, j+1, energia-1, passo+1, saida, tabuleiro, passos);
      passos[i][j+1] = 0;
    }
  }
  
  /* Se o comando for para a esquerda e se nao esteve na posicao a esquerda antes,
   * move-se para a esquerda */
  if((tabuleiro[i][j].left == 1) && (passos[i][j-1] == 0)){
    passos[i][j-1] = passo + 1;
    travessia(n, m, i, j-1, energia-1, passo+1, saida, tabuleiro, passos);
    passos[i][j-1] = 0;
  }
  
  /* Se o comando for para baixo e se nao esteve na posicao abaixo antes,
   * move-se para baixo */
  if((tabuleiro[i][j].down == 1) && (passos[i+1][j] == 0)){
    passos[i+1][j] = passo + 1;
    travessia(n, m, i+1, j, energia-1, passo+1, saida, tabuleiro, passos);
    passos[i+1][j] = 0;
  }
  
  /* Se o comando for para cima e se nao esteve na posicao acima antes,
   * move-se para cima */
  if((tabuleiro[i][j].up == 1) && (passos[i-1][j] == 0)){
    passos[i-1][j] = passo + 1;
    travessia(n, m, i-1, j, energia-1, passo+1, saida, tabuleiro, passos);
    passos[i-1][j] = 0;
  }
  
  /* Se todos os comandos forem iguais a zero, 
   * a posicao indicada contem uma armadilha */
  if((!tabuleiro[i][j].right) && (!tabuleiro[i][j].left)
    && (!tabuleiro[i][j].down) && (!tabuleiro[i][j].up))
    return;
  
}


/* Conversao do numero decimal para binario */
void conversao (int n, int m, int **tabuleiro_int, Tabuleiro **tabuleiro_bin) {
  int i, j, num, bit, tam = 0;
  
  /* Percorre a matriz do tabuleiro de decimais */
  for(i = 0; i < n; i++){
    for(j = 0; j < m; j++){
      num = tabuleiro_int[i][j];
      /* Enquanto o tamanho for menor que 4 (num dos movimentos */
      while(tam < 4)  {
	/* Se o num ja tiver sido todo convertido em binario, 
	 * coloca 0 nas posicoes */
	if(num == 0){
	  bit = 0;
	  tam++;
	  /* Verifica que posicao coloca-se o zero */
	  if(tam == 1)
	    tabuleiro_bin[i][j].left = bit;
	  else if(tam == 2)
	    tabuleiro_bin[i][j].down = bit;
	  else if(tam == 3)
	    tabuleiro_bin[i][j].right = bit;
	  else if(tam == 4)
	    tabuleiro_bin[i][j].up = bit;
	}
	/* Enquanto o numero for convertivel, continua as operacoes */
	while(num > 0){
	  bit = num % 2;
	  num = num / 2;
	  tam++;
	  /* Verifica que posicao coloca-se o bit */
	  if(tam == 1)
	    tabuleiro_bin[i][j].left = bit;
	  else if(tam == 2)
	    tabuleiro_bin[i][j].down = bit;
	  else if(tam == 3)
	    tabuleiro_bin[i][j].right = bit;
	  else if(tam == 4)
	    tabuleiro_bin[i][j].up = bit;
	}
      }
      tam = 0;
    }
  }
}


int main () {
  int i, j, k, n_linhas, m_colunas, energia, **tabuleiro_int, **passos, *saida, saiu;
  Tabuleiro **tabuleiro_bin;
  
  saida = &saiu;
  
  /* Le a primeira linha fornecida */
  scanf("%d %d %d", &n_linhas, &m_colunas, &energia);
  
  /* Alocacao dinamica das matrizes */
  tabuleiro_int = malloc(n_linhas * sizeof(int *));
  tabuleiro_bin = malloc(n_linhas * sizeof(Tabuleiro *));
  passos = malloc(n_linhas * sizeof(int *));
  for(i = 0; i < n_linhas; i++){
    tabuleiro_int[i] = malloc(m_colunas * sizeof(int));
    tabuleiro_bin[i] = malloc(m_colunas * sizeof(Tabuleiro));
    passos[i] = malloc(m_colunas * sizeof(int));
  }
  
  /* Le o tabuleiro e as possibilidades de movimento */
  for(i = 0; i < n_linhas; i++){
    for(j = 0; j < m_colunas; j++)
      scanf("%d", &tabuleiro_int[i][j]);
  }
  
  /* Converte os numeros inteiros do tabuleiro em binario */
  conversao(n_linhas, m_colunas, tabuleiro_int, tabuleiro_bin);
  
  /* Chama a funcao de travessia para cada linha do tabuleiro */
  for(i = 0; i < n_linhas; i++){
    /* Inicializa a matriz de passos do tabuleiro */
    for(k = 0; k < n_linhas; k++){
      for(j = 0; j < m_colunas; j++)
      passos[k][j] = 0;
    } 
    *saida = 0;
    
    /* Chama a funcao travessia */
    travessia(n_linhas, m_colunas, i, 0, energia, 0, saida, tabuleiro_bin, passos);
    
    /* Se a funcao achou uma saida, imprime 'Sim' */
    if(*saida)
      printf("Sim\n");
    /* se nao, imprime 'Nao' */
    else
      printf("Nao\n");
  }
  
  /* Liberacao da memoria alocada */
  for(i = 0; i < n_linhas; i++){
    free(tabuleiro_int[i]);
    free(tabuleiro_bin[i]);
    free(passos[i]);
  }
  free(tabuleiro_int);
  free(tabuleiro_bin);
  free(passos);
  
  return 0;
}
    
    