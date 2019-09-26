/* Nome: Ana Carolina Requena Barbosa
 * RA: 163755
 * Laboratorio 04b - O Lobo de Wall Street */

#include <stdio.h>

#define MAX 100

int main () {
    int D, C, X[MAX], lucro1, lucro2, maior=0;
    int d, m, y, j, quant;
    
    /* lê a primeira linha fornecida */
    scanf ("%d %d", &D, &C); 
    
    /* lê o valor de cada dia */
    for (d=0; d< D; d++){ 
        scanf ("%d", &X[d]);        
    }
    
    for (d=0; d<D; d++){ 
        /* calcula o lucro após a primeira compra e primeira venda */    
        for (m=d+1; m<D;m++){ 
            quant = C/X[d]; 
            lucro1 = quant*X[m] + C%X[d];
            /* encontra o maior lucro */
            if (lucro1 > maior)
                maior= lucro1;
            /* calcula lucro após a segunda compra e segunda venda */
            for (y=m+1; y<D; y++){      
                for (j=y+1; j<D; j++){
                    quant = lucro1/X[y];
                    lucro2 = quant*X[j] + lucro1%X[y];
                    /*encontra o maior lucro */
                    if (lucro2 > maior)
                        maior = lucro2;
                }

            }
        }
    }
    
   
    /* se o lucro maior for maior que o capital incial, imprime o capital final */
    if (maior > C)
        printf ("Capital final = R$%d\n", maior);
    /* se o lucro maior for menor que o capital inicial, imprime 'Melhor nao investir agora, cara!' */
    else 
        printf ("Melhor nao investir agora, cara!\n");
    
    return 0;
}
