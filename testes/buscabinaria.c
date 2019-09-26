#include <stdio.h>

int posicao(int v[], int inicio, int fim, int chave){
  int meio = (inicio + fim)/2;
  
  if(v[meio] == chave)
    return meio;
  
  if(inicio == fim)
    return -1;
  
  if(v[meio] > chave)
    return posicao(v, inicio, meio - 1, chave);
  else 
    return posicao(v, meio + 1, fim, chave);
  
}

int main () {
  int vet[] = {1, 5, 15, 20, 24, 45, 67, 76, 78, 100};
  int n = 10, chave, pos;
  
  printf("chave ");
  scanf("%d", &chave);
  
  pos = posicao(vet, 0, n-1, chave);
  
  if (pos != -1)
    printf("Posicao da chave 15 no vetor: %d\n", pos);
  else
    printf("A chave 15 nao se encontra no vetor.\n");
  
  return 0;
  
}