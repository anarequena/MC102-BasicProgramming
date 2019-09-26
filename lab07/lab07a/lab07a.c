/* Nome: Ana Carolina R. Barbosa
 * RA: 163755
 * Laboratorio 07a - Cargo-Bot - Part II */

#include <stdio.h>
#include <stdlib.h>

#define MAXCAIXA 10
#define MAXCOMANDO 60
#define MAXPROGRAMA 9


int left(char braco, char **posicao, int coluna){
  /* se o braco estiver vazio, move-se normalmente para a esquerda */
  if (braco == '0') {
    if ((coluna-1) >=0)
      return coluna-1;
  }
  /* se o braco estiver ocupado, move-se para a esquerda se nao houver uma caixa atrapalhando */
  else {
    if ((posicao[0][coluna-1] != '.') && ((coluna-1) >=0))
      return -1;
    else {
      if ((coluna-1) >=0)
	coluna -= 1;
     }
  }
  
  return coluna;
}



int right(char braco, char **posicao, int coluna, int maxcoluna){
  /* se o braco estiver vazio, move-se normalmente para a direita */
  if (braco == '0'){
    if (coluna+1 < maxcoluna)
      return coluna + 1;
  }
  /* se o braco estiver ocupado, move-se para a direita se nao houver uma caixa atrapalhando */
  else {
    if ((posicao[0][coluna+1] != '.') && ((coluna+1) < maxcoluna))
      return -1;
    else 
      if (coluna+1 < maxcoluna)
	coluna += 1;
  }
  
  return coluna;
}

int down(char braco, char **posicao, int linha, int coluna, int maxemp){
  /* movimento o braco para baixo até encontrar uma caixa ou o 'chao' */
  while ((linha < maxemp) && (posicao[linha][coluna]=='.')){
    linha++;
  }
  
  /* se o braco estiver vazio, e tiver uma caixa para pegar na coluna, o braco pega a caixa da posicao indicada */ 
  if ((braco == '0') && (linha < maxemp)){
    if (posicao[linha][coluna] != '.'){
      braco = posicao[linha][coluna];
      posicao[linha][coluna] = '.'; 
    }
  }
  /* se o braco estiver ocupado, deixa a caixa na posicao indicada */
  else if (braco != '0'){
    posicao[linha-1][coluna] = braco;
    braco = '0';
  }
  
  return braco; 
}




int main () {
  int X, Y, P, C, E, i, j, n, pl=0, pc=0, acidente=0, move;
  char braco='0', **posicao, execucao[MAXCOMANDO+2], programa[MAXPROGRAMA][MAXCOMANDO+2];
  
  posicao = malloc(MAXCAIXA * sizeof(char *));
  for(i=0; i<MAXCAIXA; i++)
    posicao[i] = malloc((MAXCAIXA + 1) * sizeof(char));
  
  /* lê X(posições), Y(max empilhamento), P(n. de programas), C(max comandos) e E(n. de execucoes)*/
  scanf ("%d %d %d %d %d", &X, &Y, &P, &C, &E);
  
  /* lê o estado inicial das caixas */
  for (i=0; i<Y; i++)
    scanf ("%s", posicao[i]); 
  
  /* lê a ordem de execucao dos programas */
  scanf("%s", execucao);
  
  for(i = 0; i < E; i++)
    execucao[i] = execucao[i] - '0';
  
  /* lê os programas com seus respectivos os comandos */
  for (i=0; i<P; i++)
    scanf ("%s", programa[i]);

  /* verifica qual programa é para executar */
  for (i=0; i<E; i++){ 
    n = (int) execucao[i];
    j=0;

    /* executa o programa (n-1) lendo o caractere j */
    while((programa[n-1][j] != '*') && !(acidente)){
	
      /* se o caractere for A, executa comando do caractere seguinte, se o braco tiver alguma caixa; 
       * se nao, pula o caractere seguinte */
      if (programa[n-1][j] == 'A'){
	if (braco == '0')
	  j = j+2;
	else 
	  j++;
      }
      
      /* se o caractere for N, executa comando do caractere seguinte, se braco nao tiver caixa;
       * se nao, pula o caractere seguinte */
      else if (programa[n-1][j] == 'N'){
	if (braco == '0')
	  j++;
	else
	  j = j+2;
      }
      
      /* se o caractere for B, executa comando do caractere seguinte, se braco tiver caixa azul;
       * se nao, pula o caractere seguinte */
      else if (programa[n-1][j] == 'B'){
	if (braco == 'B')
	  j++;
	else
	  j = j+2;
      }
      
      /* se o caractere for G, executa o comando do caractere seguinte;
       * se nao, pula o caractere seguinte */
      else if (programa[n-1][j] == 'G'){
	if (braco == 'G')
	  j++;
	else
	  j = j+2;
      }
      
      /* se o caractere for Y, executa comando do caractere seguinte;
       * se nao, pula o caractere seguinte */
      else if (programa[n-1][j] == 'Y'){
	if (braco == 'Y')
	  j++;
	else
	  j = j+2;
      }
      
      /* se o caractere for L, movimenta o braco para a esquerda da matriz posicao */
      else if (programa[n-1][j] == 'L'){
	move = left(braco, posicao, pc);
	if(move < 0)
	  acidente++;
	else
	  pc = move;
	
	j++;
      }
      
      /* se o caractere for R, movimenta o braco para a direita da matriz posicao */
      else if (programa[n-1][j] == 'R'){
	move = right(braco, posicao, pc, X);
	if (move < 0)
	  acidente++;
	else
	  pc = move;
	
	j++;
      }
      
      /* se o caractere for D, movimenta o braco para baixo  */
      else if (programa[n-1][j] == 'D'){
	braco = down(braco, posicao, pl, pc, Y);
	j++;
      }
    }
  }

  /* se houver acidente, imprime alerta; se nao, imprime a posicao final das caixas */
  if (acidente)
    printf ("Um acidente ocorreu\n");
  else
    for (i=0; i<Y; i++)
      printf ("%s\n", posicao[i]);
  
  
  for(i=0; i<MAXCAIXA; i++)
    free(posicao[i]);
  free(posicao);
  
    
  return 0;
}