/* Nome: Ana Carolina R. Barbosa
 * RA: 163755
 * Lab 09b - Peladeiros */

#include <stdio.h>
#include <stdlib.h>

void insertion(double vet[], int indice[], int i) {
  int j, aux2 = indice[i];
  double aux1 = vet[i];
  
  /* ordena os vetores em ordem decrescente */
  for (j = i - 1; (j >= 0) && (vet[j] < aux1); j--){
    indice[j + 1] = indice[j];
    vet[j + 1] = vet[j];
  }
  
indice[j + 1] = aux2;  
vet[j + 1] = aux1;
}

int main () {
  double **tabela, *media, melhorjogador;
  int i, j, k, l, m, n, t, **time, *ordem, indice;
 
  scanf ("%d %d", &n, &t);
  
  /* alocação dinamica dos vetores media e ordem, e das matrizes tabela e time */
  media = malloc(n * sizeof(double));
  ordem = malloc(n * sizeof(int));
  
  tabela = malloc(n * sizeof(double *));
  for (i = 0; i < n; i++)
    tabela[i] = malloc(n * sizeof(double));
  
  time = malloc(t * sizeof(int *));
  for (i=0; i<t; i++)
    time[i] = malloc(n * sizeof(int));
  
 
  /* zera as medias de todos os jogadores */
  for (i=0; i<n; i++)
    media[i] = 0;
  
  
  /* le a matriz fornecida */
  for (i=0; i < n; i++){
    for (j=0; j<n; j++){
      scanf ("%lf", &tabela[i][j]);
    }
  }
  
  
  /* calcula a media de cada jogador */
  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      media[i] += tabela[j][i];
    }
    media[i] /= n;
  }
  
  
  /* define a ordem dos jogadores */
  for (i=0; i<n; i++)
    ordem[i] = i;
  
  
  /* ordena as médias dos jogadores em forma decrescente */
  for (i = 1; i < n; i++)
    insertion(media, ordem, i);
  
  
  /* define os capitães */
  for (i=0; i<t; i++){
      time[i][0] = ordem[i];
  }
 
  
  /* 'zera' as notas dos capitães */
  for (j=0; j<t; j++){
    k = time[j][0];
    for (i=0; i <n; i++)
      tabela[i][k] = -1;
  }
 
 
  /* define o jogador 'l' de cada time */  
  for(l=1; l < n/t; l++){
    
    /* define o time 'k' */
    for (k=0; k<t; k++){
      i = time[k][0];
      melhorjogador = -1;
      
      /* compara as notas dos jogadores dadas pelos capitães de cada time */
      for (j=0; j<n; j++){
	if(tabela[i][j] > melhorjogador){
	  melhorjogador = tabela[i][j];
	  indice = j;
	}
      }
      
    /* quando escolhe um jogador, 'zera' suas notas */  
    for (m=0; m<n; m++){
      tabela[m][indice] = -1;
    }
    time[k][l] = indice;
    }
  }
  
  /* imprime os times finais */
  for (i=0; i<t; i++){
    printf ("Time %d: ", i+1);
    for (j=0; j< n/t-1; j++){
      printf ("%d ", time[i][j]+1);
    }
    printf ("%d\n", time[i][j]+1);
  }
 
 
  /* desaloca matrizes e vetores */
  for (i = 0; i < n; i++)
    free(tabela[i]);
  free(tabela);
  
  for (i = 0; i < t; i++)
    free(time[i]);
  free(time);
  
  free(media);
  
  free(ordem);
  
  return 0;
  
}