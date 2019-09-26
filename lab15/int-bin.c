#include <stdio.h>

int main() {
  unsigned long int n, bit, tam = 0;

  printf("Digite um numero decimal: ");
  scanf("%lu", &n);

  while(tam < 4)  {
    if(n == 0){
      bit = 0;
      tam++;
      if(tam == 1)
	printf("l = %lu\n", bit);
      else if(tam == 2)
	printf("d = %lu\n", bit);
      else if(tam == 3)
	printf("r = %lu\n", bit);
      else if(tam == 4)
	printf("u = %lu\n", bit);
    }
    while(n > 0){
      bit = n % 2;
      n = n / 2;
      tam++;
      if(tam == 1)
	printf("l = %lu\n", bit);
      else if(tam == 2)
	printf("d = %lu\n", bit);
      else if(tam == 3)
	printf("r = %lu\n", bit);
      else if(tam == 4)
	printf("u = %lu\n", bit);
    }
  }
  
  return 0;
}