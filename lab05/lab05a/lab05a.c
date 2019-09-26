/* Nome: Ana Carolina R. Barbosa
 * RA: 163755
 * Laboratorio 05a - Necronomicon */

#include <stdio.h>

#define MAX 21

int main () {
  char palavra1[MAX], palavra2[MAX], palavra3[MAX];
  int N, n, i, j, m=0, ordem=0, aux=0, verd=0, resultado[MAX];
  
  /* le o numero de pares de palavras */
  scanf ("%d ", &N);
  
  /* para cada linha lida, executa os comandos */
  for (n=0; n<N; n++){
    scanf ("%s", palavra1);
    scanf ("%s", palavra2);
    
    /* conta o numero de caracteres da entidade (palavra1) */
    while (palavra1[m] != '\0')
      m++;
    
    /* encontra um caractere da palavra2 igual a palavra1 e transcreve na palavra3 */
    for (i=0; i <= m; i++) {
      for (j=0; (palavra2[j] != '\0')&&(aux==0); j++) {
	if ((palavra1[i] == palavra2[j]) && (j>=ordem)){
	  palavra3[i] = palavra2[j];
	  aux++;
	  ordem=j;
	  palavra3[i+1] = '\0';
	}
      }
      aux = 0;   
    }
    
    /* compara os caracteres da palavra1 com a palavra3 */
    for (i=0; i<=m; i++){
      if (palavra1[i] == palavra3[i])
	verd++;
    }
    
    /* verifica se o contador de caracteres iguais 'verd' é igual ao tamanho da palavra1 */
    if(verd == (m+1))
      resultado[n]=1;
    else
      resultado[n]=0;
    
    /* zera os contadores */
    verd = 0;
    m = 0;
    ordem = 0;
  }
  
  /* imprime o resultado de cada par de palavras */
  for (n=0; n<N; n++){
    if (resultado[n])
      printf ("Sim\n");
    else
      printf ("Nao\n");
  }
  

  return 0;
  
}
  
  
  
  