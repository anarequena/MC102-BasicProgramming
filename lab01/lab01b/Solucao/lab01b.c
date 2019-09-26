/* Laboratorio 01b - Conta de agua
   Autor: Gustavo Rodrigues Galvao
   Email: ggalvao@ic.unicamp.br
*/

#include <stdio.h>

/* define as tarifas da classe residencial */
#define TARIFA1 17.34
#define TARIFA2 2.41
#define TARIFA3 3.70
#define TARIFA4 4.43

int main() {
    /* variaveis da entrada */
    int media, consumo;
    /* variaveis para percentual de reducao/aumento e resultado */
    double percentual, valor;

    scanf("%d %d", &media, &consumo);
    
    /* calcula o valor da conta original */
    if (consumo <= 10)
        valor = TARIFA1;
    else if ((consumo >= 11) && (consumo <= 20))
        valor = TARIFA1 + (consumo - 10)*TARIFA2;
    else if ((consumo >= 21) && (consumo <= 50))
        valor = TARIFA1 + 10*TARIFA2 + (consumo - 20)*TARIFA3;
    else
        valor = TARIFA1 + 10*TARIFA2 + 30*TARIFA3 + (consumo - 50)*TARIFA4;

    /* imprime o valor original */
    printf("Valor original = %.2f\n", valor);

    /* calcula o valor da conta final */
    if (consumo < media) {
        percentual = (double) (media - consumo)/media;
        
        if ((percentual >= 0.10) && (percentual < 0.15))
            valor = valor*0.9;
        else if ((percentual >= 0.15) && (percentual < 0.20))
            valor = valor*0.8;
        else if (percentual >= 0.20)
            valor = valor*0.7;
    } else if (consumo > media) {
        percentual = (double) (consumo - media)/media;
        
        if (percentual < 0.2)
            valor = valor*1.4;
        else
            valor = valor*2;
    }

    /* imprime o valor final */
    printf("Valor final = %.2f\n", valor);

    return 0;
}
