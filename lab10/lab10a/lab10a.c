/* Nome: Ana Carolina R. Barbosa
 * RA: 163755
 * Laboratório 10a - Tag Cloud */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertion(int vet[], char **matriz, int i, int m) {
  int j, aux = vet[i];
  char *aux1;
  
  aux1 = malloc(m * sizeof(char));
  
  /* copia a string (matriz[i]) na auxiliar (aux1) */
  strcpy(aux1,matriz[i]);
  
  /* enquanto o numero de ocorrencias for menor que o aux ou se o numero de ocorrencias for igual e a string for lexigograficamente maior que aux1, excuta */
  for (j = i - 1; (j >= 0) && ((vet[j] < aux) || ((vet[j] == aux) && strcmp(matriz[j], aux1) >= 0)); j--){
    
    /* anda com o vetor e a matriz uma posicao para frente */
    vet[j + 1] = vet[j];
    strcpy(matriz[j+1], matriz[j]);
  }
  
  /* insere as auxiliares no lugar ordenado */
  vet[j + 1] = aux;
  strcpy(matriz[j+1], aux1);
  
  free(aux1);
}

int main () {
  char *texto, **palavra;
  int d, f, l, m, tam, i, flag, *ocorrencia;
  
  /* le as variaveis fornecidas (D, F, L e M) */
  scanf ("%d %d %d %d", &d, &f, &l, &m);
  
  
  texto = malloc(m * sizeof(char));
  palavra = malloc(d * sizeof(char *));
  for (i = 0; i < d; i++)
    palavra[i] = malloc(m * sizeof(char)); 
  ocorrencia = malloc(d * sizeof(int));
  
  
  /* zera a matriz de strings e o vetor de ocorrencias */
  for (i=0; i < d; i++){
    palavra[i][0] = '0';
    ocorrencia[i] = 0;
  }
  
  /* enquanto o texto nao for igual a '*', le uma palavra de cada vez */
  while (texto[0] != '*'){
    tam = 0;
    scanf (" ");
    scanf ("%s", texto);
    
    /* calcula o tamanho da palavra */
    tam = strlen(texto);
        
    /* se a palavra for maior que o minimo fornecido */
    if (tam >= l){
      flag = -1;

      for (i = 0; (i < d) && (flag); i++){
	/* se na posicao da matriz ja houver uma palavra, compara-se essa palavra com a lida */
	if (palavra[i][0] != '0'){
	  flag = strcmp(palavra[i],texto);
	  /* se as palavras forem iguais, incrementa ocorrencia */
	  if (!(flag))
	    ocorrencia[i]++;
	} 
	/* se na posicao da matriz nao tiver uma palavra, insere a palavra lida na posicao */
	else {
	  strcpy(palavra[i], texto);
	  ocorrencia[i]++;
	  flag = 0;
	}
      }
    }
  }
  
  /* ordena as palavras por ordem de ocorrencia e lexigograficamente */
  for (i=0; i<d; i++)
    insertion(ocorrencia, palavra, i, m);
  
  /* imprime as palavras se tiverem o minimo de ocorrencias pedido e se a palavra for diferente de 0 */
  for (i=0; i<d; i++){
    if ((ocorrencia[i] >= f) && (palavra[i][0] != 0))
      printf ("%s %d\n", palavra[i], ocorrencia[i]);
  }
  
  
  free(texto);
  for (i = 0; i < d; i++)
    free(palavra[i]);
  free(palavra);
  free(ocorrencia);
  
  
  return 0;
  
}