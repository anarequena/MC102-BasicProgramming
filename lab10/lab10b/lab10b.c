/* Nome: Ana Carolina R. Barbosa
 * RA: 163755
 * Laboratório 10b - O Baile de Inverno */

#include <stdio.h>
#include <stdlib.h>

void insertion(int vet[], int i) {
  int j, aux = vet[i];

  for (j = i - 1; (j >= 0) && (vet[j] > aux); j--)
    vet[j + 1] = vet[j];
  
  vet[j + 1] = aux;
}

int main () {
  int *mulher, *homem, m, h, d, dupla, i, j, diferenca;
  
  /* le o numero de homens (h), o numero de mulheres (m)
   * e a diferença maxima de habilidade permitida (d) */
  scanf ("%d %d %d", &h, &m, &d);
  
  mulher = malloc(m * sizeof(int));
  homem = malloc(h * sizeof(int));
  
  /* le os valores da segunda linha correspondentes aos homens */
  for(i=0; i<h; i++)
    scanf ("%d", &homem[i]);
  
  /* le os valores da terceira linha correspondentes às mulheres */
  for(j=0; j<m; j++)
    scanf ("%d", &mulher[j]);
  
  /* ordena os vetores a fim de pega o máximo de duplas possível */
  for(i=0; i<h; i++)
    insertion(homem, i);
  
  for(i=0; i<m; i++)
    insertion(mulher, i);
  
  
  /* percorre o vetor dos homens */
  for(i=0; i<h; i++){
    /* percorre o vetor das mulheres */
    for(j=0; j<m; j++){
      diferenca = 0;
      /* se o homem e a mulher nao foram escolhidos para uma dupla */
      if((homem[i] >= 0) && (mulher[j]>=0)){
	diferenca = homem[i] - mulher[j];
	/* se a diferença entre as habilidades do homem e da mulher for menor ou igual a d,
	 * forma-se uma dupla e esses não são mais considerados para a formação de outras duplas */
	if (((diferenca <= d) && (diferenca >= 0)) || ((diferenca >= -d) && (diferenca <= 0))){
	  dupla++;
	  mulher[j] = -mulher[j];
	  homem[i] = -homem[i];
	}
      }
    }
  }
  
  free(mulher);
  free(homem);
  
  /* imprime o numero de duplas */
  printf ("Numero maximo de duplas equilibradas = %d\n", dupla);
  
  
  return 0;
  
}