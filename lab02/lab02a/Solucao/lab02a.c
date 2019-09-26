/* Laboratorio 02a - Coeficiente de Rendimento
   Autor: Andre Rodrigues Oliveira
   Email: andre.oliveira@students.ic.unicamp.br
*/

#include <stdio.h>

int main() {
   /* variaveis para o calculo do CR */
   double total_creditos = 0, calculo = 0;
   
   /* variaveis auxiliares */
   int creditos, peso;
   char conceito;

   /* leitura do primeiro caractere */
   scanf("%c", &conceito);

   /* enquanto o caractere nao eh fim de leitura, faz o calculo */
   while (conceito != '*') {
       /* leitura do numero de creditos, ja jogando fora o \n */
       scanf("%d", &creditos);
       
       /* registra o peso do conceito lido */
       switch(conceito) {
           case 'A':
               peso = 4;
               break;
           case 'B':
               peso = 3;
               break;
           case 'C':
               peso = 2;
               break;
           case 'D':
               peso = 1;
               break;
           case 'E':
               peso = 0;
               break;
       }
       
       /* adiciona o numero de creditos * peso do conceito atual */
       calculo = calculo + creditos * peso;

       /* adiciona no divisor o numero de creditos do conceito atual */
       total_creditos = total_creditos + creditos;

       /* pega o proximo caractere, que pode ser um conceito ou o
          caractere '*' */
       scanf(" %c", &conceito);
   }

   /* se o numero de creditos ao final da leitura eh 0, entao o
      aluno nao cursou disciplinas e seu CR deve ser Indefinido */
   if (total_creditos == 0)
       printf("CR = Indefinido\n");
   /* caso contrario, imprime o CR com 4 casas decimais */
   else
       printf("CR = %.4f\n", calculo/total_creditos);

   return 0;
}
