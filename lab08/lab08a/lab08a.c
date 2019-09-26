/* Laboratorio 08a - BigCalc
 * Nome: Ana Carolina R. Barbosa 
 * RA: 163755 */

#include <stdio.h>
#include <stdlib.h>

/* realiza a adicao n1+n2, armazendo o resultado em result */
void add(int *n1, int tam_n1, int *n2, int tam_n2, int *result) { 
  int tam = 0, sobra = 0, i, temp;
 
  /* enquanto um dos tamanhos for maior que 0, executa */
  while (tam_n1 > 0){
    /* se ambos forem maiores que 0, 
     * soma os dois mais a sobra ao resultado e decrementa os tamanhos */
    if ((tam_n1 > 0) && (tam_n2 > 0)){
      result[tam] = n1[tam_n1-1] + n2[tam_n2-1] + sobra;
      tam_n1--;
      tam_n2--;
    } 
    /* se apenas o primeiro tamanho for maior que 0,
     * soma somento o n1 e a sobra ao resultado e decrementa o tamanho1 */
    else if (tam_n2 == 0){
      result[tam] = n1[tam_n1-1] + sobra;
      tam_n1--;
    }
    sobra = 0;
    /* se a soma for maior que 9, subtrai 10 do resultado e incrementa a sobra */
    if (result[tam] > 9){
      result[tam] -= 10;
      sobra++;
    }
    tam++;
  }
  
  /* se ainda tiver uma sobra para somar ao resultado, soma 10 */
  if (sobra)
    result[tam-1] += 10;
  
  /* inverte o resultado */
  for (i=0; i<tam/2; i++){
    temp = result[tam -i -1];
    result[tam -i -1] = result[i];
    result[i] = temp;
  }
  
  /* imprime o resultado final */
  for (i=0; i<tam; i++)
    printf ("%d", result[i]);
  
  printf ("\n");
}


/* realiza a subtracao n1-n2, com n1>=n2, armazenando o resultado em result */
void substract(int *n1, int tam_n1, int *n2, int tam_n2, int *result) {
   int tam = 0, i, temp;
  
  /* enquanto um dos tamanhos for maior que 0, executa */
  while (tam_n1 > 0){
    /* se ambos forem maiores que 0, 
     * soma os dois mais o extra ao resultado e decrementa os tamanhos */
    if ((tam_n1 > 0) && (tam_n2 > 0)){
      result[tam] = n1[tam_n1-1] - n2[tam_n2-1];
      /* se o resultado for menor que 0, soma 10 e decrementa do digito anterior de n1 */
      if (result[tam] < 0){
	result[tam] += 10;
	n1[tam_n1-2] -= 1;
      }
      tam_n1--;
      tam_n2--;
    }
    /* se apenas o primeiro tamanho for maior que 0,
     * copia os digitos de n1 ao resultado */
    else if (tam_n2 == 0) {
      result[tam] = n1[tam_n1-1];
      /* se o reultado for menor que 0, soma 10 e decrementa do digito anterior de n1 */
      if (result[tam] < 0){ 
	result[tam] +=10;
	n1[tam_n1 -2] -= 1;
      }
      tam_n1--;
    }
    tam++;
  }
  
  /* enquanto existir zeros a 'esquerda' do resultado, decrementa o tamanho */
  while ((result[tam] == 0) && (tam > 0)) 
      tam--;
  
  /* inverte o resultado */
  for (i=0; i<=tam/2; i++){
    temp = result[tam -i];
    result[tam -i] = result[i];
    result[i] = temp;
  }
  
  /* imprime o resultado final */
  for (i=0; i<=tam; i++)
    printf ("%d", result[i]);

  printf ("\n");
} 


/* realiza a multiplicacao n1*n2, armazendo o resultado em result */
void multiply(int *n1, int tam_n1, int *n2, int tam_n2, int *result) {
  int tam=0, i, temp, n;
  
  
  /* enquanto o segundo tamanho for maior que 0, executa */
  for (i=0; tam_n2 > 0; i++){
   tam = i;
   n = tam_n1;
   /* enquanto o primeiro tamanho for maior que 0, multiplica o digito de n2 ao de n1 */
   while (n > 0){
    result[tam] += n1[n -1] * n2[tam_n2-1];
    /* enquanto o resultado for maior que 9, subtrai-se 10 do resultado atual e incrementa o proximo */
    while (result[tam] > 9){
      result[tam] -= 10;
      result[tam+1]++;
    }
    tam++;
    n--;
   }
   tam_n2--;
  }
  
  /* enquanto existir zeros a 'esquerda' do resultado, decrementa o tamanho */
  while ((result[tam] == 0) && (tam > 0)) 
      tam--;
  
  /* inverte o resultado */
  for (i=0; i<=tam/2; i++){
    temp = result[tam -i];
    result[tam -i] = result[i];
    result[i] = temp;
  }
  
  /* imprime o resultado final */
  for (i=0; i<=tam; i++)
    printf ("%d", result[i]);

  printf ("\n");
} 


int main() { 
  int x, y, *digint1, *digint2, *result, i, tam;
  char c;
  char *dig1, *dig2;
  
  /* le o tamanho do primeiro numero(x), o tamanho do segundo numero(y) e
   * a operacao a ser realizada(c) */
  scanf ("%d %d %c ", &x, &y, &c);
  
  /* define o tamanho maximo do resultado */
  tam = x*y;
  
  /* aloca memória para os digitos de acordo com seus tamanhos */
  dig1 = malloc(x * sizeof(char));
  dig2 = malloc(y * sizeof(char));
  digint1 = malloc(x * sizeof(int));
  digint2 = malloc(y * sizeof(int));
  result = malloc(tam * sizeof(int));
  
  for(i=0; i<=tam; i++)
    result[i] = 0;
  
  /* le o primeiro digito */
  for (i=0; i<x; i++)
    scanf ("%c", &dig1[i]);
  
  scanf (" ");
  
  /* le o segundo digito */
  for (i=0; i<y; i++)
    scanf ("%c", &dig2[i]);
  
  /* subtrai '0' dos caracteres do primeiro digito 
   * e transpoe o valor para um vetor de inteiros */
  for (i=0; i<x; i++){
    dig1[i] -= '0';
    digint1[i] = (int) dig1[i]; 
  }
  
  /* subtrai '0' dos caracteres dp segundo digito 
   * e transpoe o valor para um vetor de inteiros */
  for (i=0; i<y; i++){
    dig2[i] -= '0';
    digint2[i] = (int) dig2[i];
  }
  
  /* se o caractere lido for 'A', executa add */
  if (c == 'A')
    add(digint1, x, digint2, y, result);
  /* se o caractere lido for 'S', executa substract */
  else if (c == 'S')
    substract(digint1, x, digint2, y, result);
  /* se o caractere ligo for 'M', executa multiply */
  else if (c == 'M')
    multiply(digint1, x, digint2, y, result);
    
  
  /* libera memoria alocada dos digitos */
  free(dig1);
  free(dig2);
  free(digint1);
  free(digint2);
  free(result);

  return 0;
}