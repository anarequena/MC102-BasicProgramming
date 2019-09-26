/* Nome: Ana Carolina R. Barbosa
 * RA: 163755
 * Laboratorio 06a - Raio Sugestor */

#include <stdio.h>

#define MAX 50

int main (){
  int matriz[MAX][MAX];
  int m, n, r, i, j, nr, k, l, total = 0, maior=0;
  
  /* lê m (coluna), n (linha) e r (raio) */ 
  scanf ("%d %d %d", &m, &n, &r);
  
  /* lê cada elemento da matriz fornecida */
  for (i=0; i<m;i++){
    for (j=0;j<n;j++){
      scanf ("%d", &matriz[i][j]);
    } 
  }
  
  /* calcula o lado do quadrado (nr) da área afetada pelo alcance do raio */
  nr = r*2 + 1;
  
  /* calcula todas as possibilidades de alcance e encontra o maior numero de pessoas afetadas */
  for (k=0; k<m; k++){
    for (l=0; l<n; l++){
      for (i=k; i<(k+nr); i++){
	for (j=l; j<(l+nr); j++){
	  total += matriz[i][j];
	}
      }
      if (total > maior)
	maior=total;
      total=0;
    }
  }
  
  /* imprime o maior numero de pessoas afetadas */
  printf ("%d\n", maior);
  
  return 0;
}