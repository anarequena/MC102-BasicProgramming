#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void insertion(double media[], int ordem[], int i) {
  int j, aux2 = ordem[i];
  double aux1 = media[i];
  
  for (j = i - 1; (j >= 0) && (media[j] < aux1); j--){
    ordem[j + 1] = ordem[j];
    media[j + 1] = media[j];
  }
  
ordem[j + 1] = aux2;  
media[j + 1] = aux1;
}

int main () {
  int n , i, ordem[MAX];
  double media[MAX];
  
  printf ("Entre com numero de jogadores: ");
  scanf ("%d", &n);
  
  printf ("Entre com as medias: ");
  for (i=0; i<n; i++)
    scanf ("%lf", &media[i]);
  
  for (i=0; i<n; i++)
    ordem[i] = i+1;
  
  for (i = 1; i < n; i++)
    insertion(media, ordem, i);
  
  for (i=0; i<n; i++){
    printf ("%.3f ", media[i]);
    printf ("%d ", ordem[i]);
  }
  
  printf ("\n");
  
  return 0;
}