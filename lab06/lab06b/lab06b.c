/* Nome: Ana Carolina R. Barbosa
 * RA: 163755
 * Laboratorio 06b - A Ameaça Fantasma */

#include <stdio.h>

#define MAX 100

int main (){
  int recinto[MAX][MAX], m, n, i, j, t=0, flag, vivos=0, gas=1;
  
  /* lê o numero de colunas (m) e o de linhas (n) da matriz */
  scanf ("%d %d", &m, &n);
  
  
  /* lê a matriz do recinto */
  for (i=0;i<m;i++){
    for (j=0;j<n;j++)
      scanf ("%d", &recinto[i][j]);
  }
  
  
  /* calcula o tempo de contaminação do recinto enquanto o gas é propagado */ 
  do{ 
    flag = 0;
    gas++;
    t++;
    /* percorre a matriz verificando onde ha gas */
    for (i=0;i<m;i++){
      for (j=0;j<n;j++){
	if (recinto[i][j]==gas){
	  /* propaga o gas ao redor do ponto onde se encontra, se possivel */ 
	  if ((j-1>=0) && (recinto[i][j-1]==0)){
	    recinto[i][j-1]=gas+1;
	    flag=1;
	  }
	  if ((i-1>=0) && (recinto[i-1][j]==0)){
	    recinto[i-1][j]=gas+1;
	    flag=1;
	  } 
	  if ((i+1<m) && (recinto[i+1][j]==0)){
	    recinto[i+1][j]=gas+1;
	    flag=1;
	  }
	  if ((j+1<n) && (recinto[i][j+1]==0)){
	    recinto[i][j+1]=gas+1;
	    flag=1;
	  }
	}
      }
    }
  } while (flag);
  
  
  
  /* verifica se há ou não espaços vazios no recinto */
  for (i=0;i<m;i++){
    for (j=0;j<n;j++){
      if (recinto[i][j]==0)
	vivos = 1;
    }
  }
 
 
  /* se houver espaços vazios, imprime o alerta; se nao, imprime o tempo total */
  if (vivos)
    printf ("Perigo: Jedis podem estar vivos\n");
  else
    printf ("Tempo = %d\n", t);
  
 
  return 0;
} 