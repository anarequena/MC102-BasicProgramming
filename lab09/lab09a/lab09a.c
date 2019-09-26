/* Nome: Ana Carolina R. Barbosa 
 * RA: 163755 
 * Lab 09a - A Batalha de Geonosis */

#include <stdio.h>
#include <stdlib.h>

#define MAX 50


int main () {
  int linha, coluna, i, j, k, l, attelinha, attecoluna, eliminados, disparo, menordis=4, maiorelim = 0, horizontal=0, vertical=0, diagonal1=0, diagonal2=0;
  int campo[MAX][MAX];
  
  /* le o numero de linhas e colunas */
  scanf ("%d %d", &linha, &coluna);
  
  /* le a matriz fornecida */
  for (i=0; i<linha; i++){
    for (j=0; j<coluna; j++){
      scanf ("%d", &campo[i][j]);
    }
  } 
  
  /* percorre toda a matriz, verificando todas as possibilidades de posiçao do atte */
  for (i=0; i<linha; i++){
    for (j=0; j<coluna; j++){
      eliminados = 0;
      disparo = 0;
      /* se a posicao indicada nao estiver ocupada por um droid, posiciona o atte */
      if (campo[i][j] != 1){
	/* percorre a horizontal da posicao do atte e conta o numero de droids encontrados */
	for (k=0; k<coluna; k++){
	  if(campo[i][k] == 1){
	    eliminados++;
	    horizontal++;
	  }  
	}
	/* percorre a vertical da posicao do atte e conta o numero de droids encontrados */
	for (l=0; l<linha; l++){
	  if(campo[l][j] == 1){
	    eliminados++;
	    vertical++;
	  }
	}
	/* percorre a primeira diagonal da posicao do atte e conta o numero de droids encontrados */
	for (k=j, l=i; (k<coluna)&&(l<linha); k++, l++){
	  if (campo[l][k] == 1){
	    eliminados++;
	    diagonal1++;
	  }
	}
	for (k=j, l=i; (k>=0)&&(l>=0); k--, l--){
	  if (campo[l][k] == 1){
	    eliminados++;
	    diagonal1++;
	  }
	}
	/* percorre a segunda diagonal da posicao do atte e conta o numero de droids encontrados */
	for (k=j, l=i; (k<coluna)&&(l>=0); k++, l--){
	  if (campo[l][k] == 1){
	    eliminados++;
	    diagonal2++;
	  }
	}
	for (k=j, l=i; (k>=0)&&(l<linha); k--, l++){
	  if (campo[l][k] == 1){
	    eliminados++;
	    diagonal2++;
	  }
	}
	
	/* conta o numero total de disparos */
	if (horizontal)
	  disparo++;
	if (vertical)
	  disparo++;
	if (diagonal1)
	  disparo++;
	if (diagonal2)
	  disparo++;
	
	/* zera os contadores */
	horizontal = 0;
	vertical = 0;
	diagonal1 = 0;
	diagonal2 = 0;
	
	/* encontra o maior numero de droids eliminados com o menor numero de disparos */
	if (eliminados > maiorelim){
	  maiorelim = eliminados;
	  attelinha = i;
	  attecoluna = j;
	  menordis = disparo;
	} else if (eliminados == maiorelim)
	  if (disparo < menordis){
	    maiorelim = eliminados;
	    attelinha = i;
	    attecoluna = j;
	    menordis = disparo;
	  }
      }
    }
  }
  
  /* imprime a melhor posicao de atte, o numero de droids eliminados e o numero de disparos */
  printf ("Posicao = (%d,%d)\n", attelinha, attecoluna);
  printf ("Droids = %d\n", maiorelim);
  printf ("Disparos = %d\n", menordis);
      
  return 0;
}