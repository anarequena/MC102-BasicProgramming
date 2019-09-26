/* Nome: Ana Carolina R. Barbosa
 * RA: 163755
 * Laboratorio 14a - Cargo-Bot - Part III */

#include <stdio.h>
#include <stdlib.h>

/* movimenta para a esquerda */
void left(char *braco, char **posicao, int *coluna, int *acidente){
  /* se o braco estiver vazio, move-se normalmente para a esquerda */
  if (*braco == '0') {
    if ((*coluna-1) >=0)
      *coluna -= 1;
  }
  /* se o braco estiver ocupado, move-se para a esquerda 
   * se nao houver uma caixa atrapalhando */
  else {
    if ((posicao[0][*coluna-1] != '.') && ((*coluna-1) >=0))
      *acidente += 1;
    else {
      if ((*coluna-1) >=0)
	*coluna -= 1;
    }
  }
}

/* movimenta para a direita */
void right(char *braco, char **posicao, int *coluna, int maxcoluna, int *acidente){
  /* se o braco estiver vazio, move-se normalmente para a direita */
  if (*braco == '0'){
    if (*coluna+1 < maxcoluna)
      *coluna += 1;
  }
  /* se o braco estiver ocupado, move-se para a direita 
   * se nao houver uma caixa atrapalhando */
  else {
    if ((posicao[0][*coluna+1] != '.') && ((*coluna+1) < maxcoluna))
      *acidente += 1;
    else 
      if (*coluna+1 < maxcoluna)
	*coluna += 1;
  }
}

/* movimenta para baixo */
void down(char *braco, char **posicao, int *coluna, int maxemp, int *acidente){
  int linha = 0;
  
  /* movimento o braco para baixo até encontrar uma caixa ou o 'chao' */
  while ((linha < maxemp) && (posicao[linha][*coluna]=='.')){
    linha++;
  }
   
  /* se o braco estiver vazio, e tiver uma caixa para pegar na coluna, 
   * o braco pega a caixa da posicao indicada */ 
  if ((*braco == '0') && (linha < maxemp)){
    if (posicao[linha][*coluna] != '.'){
      *braco = posicao[linha][*coluna];
      posicao[linha][*coluna] = '.'; 
    }
  }
  /* se o braco estiver ocupado, deixa a caixa na posicao indicada */
  else if (*braco != '0'){
    posicao[linha-1][*coluna] = *braco;
    *braco = '0';
  }
}

/* execucao de um programa */
void Programa(int n, int P, int X, int Y, int E, int *acidente, char **posicao,
              char **programa, char *braco, int *coluna, int *count) {
  int i, j=0;
  
  /* conta o numero de execucoes do programa */
  *count = *count + 1;
  
  /* verifica se o numero de execucoes nao ultrapassa E */
  if (*count > E)
    return;
     
  /* executa o programa (n-1) lendo o caractere j */
  while((programa[n-1][j] != '*') && !(*acidente)){
     
    /* se o comando for um numero entre 0 e o numer de programas,
     * executa o programa do numero correspondente */
    if(((programa[n-1][j] - '0') > 0) && ((programa[n-1][j] - '0') <= P)){
      i = programa[n-1][j] - '0';
      Programa(i, P, X, Y, E, acidente, posicao, programa, braco, coluna, count);
	
      j++;
    }
    
    
    /* se o caractere for A, executa comando do caractere seguinte, se o
     * braco tiver alguma caixa; se nao, pula o caractere seguinte */
    else if (programa[n-1][j] == 'A'){
      if (*braco == '0')
	j = j+2;
      else 
        j++;
    }
   
    /* se o caractere for N, executa comando do caractere seguinte, se o 
     * braco nao tiver caixa; caso contrario, pula o caractere seguinte */
    else if (programa[n-1][j] == 'N'){
      if (*braco == '0')
         j++;
      else
         j = j+2;
    }
   
    /* se o caractere for B, executa comando do caractere seguinte, se o
      * braco tiver caixa azul; se nao, pula o caractere seguinte */
    else if (programa[n-1][j] == 'B'){
      if (*braco == 'B')
         j++;
      else
         j = j+2;
    }
   
    /* se o caractere for G, executa o comando do caractere seguinte;
     * se nao, pula o caractere seguinte */
    else if (programa[n-1][j] == 'G'){
      if (*braco == 'G')
         j++;
      else
         j = j+2;
    }
   
    /* se o caractere for Y, executa comando do caractere seguinte;
     * se nao, pula o caractere seguinte */
    else if (programa[n-1][j] == 'Y'){
      if (*braco == 'Y')
         j++;
      else
         j = j+2;
    }
   
    /* se o caractere for L, movimenta o braco para a esquerda da matriz posicao */
    else if (programa[n-1][j] == 'L'){
      left(braco, posicao, coluna, acidente);
      j++;
    }
   
    /* se o caractere for R, movimenta o braco para a direita da matriz posicao */
    else if (programa[n-1][j] == 'R'){
      right(braco, posicao, coluna, X, acidente);
      
      j++;
    }
   
    /* se o caractere for D, movimenta o braco para baixo  */
    else if (programa[n-1][j] == 'D'){
      down(braco, posicao, coluna, Y, acidente);
      
      j++;
    }
  }
}

int main () {
   int X, Y, P, C, E, i, n=1, *coluna, coluna_v = 0, *acidente, acidente_v = 0, count_v = 0, *count;
   char **posicao, **programa, *braco, braco_v = '0';
   
   /* inicializa um ponteiro para cada variável */
   count = &count_v;
   coluna = &coluna_v;
   braco = &braco_v;
   acidente = &acidente_v;
  
   /* lê X(posições), Y(max empilhamento), P(n. de programas), C(max comandos) e
    E*(n. de execucoes)*/
   scanf ("%d %d %d %d %d", &X, &Y, &P, &C, &E);
   
   posicao = malloc(Y * sizeof(char *));
   for(i=0; i<Y; i++)
      posicao[i] = malloc((X + 1) * sizeof(char));
   
   programa = malloc(P * sizeof(char *));
   for(i=0; i<P; i++)
      programa[i] = malloc((C + 2) * sizeof(char));
   
   /* lê o estado inicial das caixas */
   for (i=0; i<Y; i++)
      scanf ("%s", posicao[i]);
   
   /* lê os programas com seus respectivos os comandos */
   for (i=0; i<P; i++)
      scanf ("%s", programa[i]);
   
   /* executa o primeiro programa */
   Programa(n, P, X, Y, E, acidente, posicao, programa, braco, coluna, count);
   
   /* se houver acidente, imprime alerta; se nao, imprime a posicao final das
    c*aixas */
   if (*acidente)
      printf ("Um acidente ocorreu\n");
   else
    for (i=0; i<Y; i++)
      printf ("%s\n", posicao[i]);
  
  
  for(i=0; i<Y; i++)
    free(posicao[i]);
  free(posicao);
  
  for(i=0; i<P; i++)
     free(programa[i]);
  free(programa);
  return 0;
}