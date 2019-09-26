/* Laboratorio 13a - Hanabi
   Autor: Thierry Pinheiro Moreira
   Email: thierrypin@ic.unicamp.br
 */

#include <stdio.h>

int calculaAltura() {
    int qtdFilhos, i, altura;
    /* Como a altura da arvore e um inteiro positivo, 
       o valor do maximo e inicializado como 0 */
    int max = 0;
    scanf("%d", &qtdFilhos);
    
    /* Condicao de parada: se a bomba nao possui filhos, a altura de
       sua sub arvore eh 1 */
    if (qtdFilhos == 0)
        return 1;
    
    /* Procura a maior altura entre as sub arvores */
    for (i = 0; i < qtdFilhos; i++) {
        altura = calculaAltura() + 1;
        if (max < altura)
            max = altura;
    }
    
    /* Retornar a altura da arvore */
    return max;
}

int main() {
    int altura;
    
    altura = calculaAltura();
    
    printf("%d\n", altura);
    
    return 0;
}
