/* Laboratorio 04b - O Lobo de Wall Street
   Autor: Javier Alvaro Vargas Munoz
   Email: ra153620@students.ic.unicamp.br
*/

#include <stdio.h>

int main() {
    /* variaveis da entrada */
    int num_dias, capital;
    int valor[100];

    /* variaveis auxiliares */
    int i, j, k, compra_venda;

    /* variaveis para o calculo do maximo capital final */
    int maximo_capital, capital_cv1, capital_cv2, maximo_pico;

    /* leitura do numero de dias e o capital inicial */
    scanf("%d %d", &num_dias, &capital);

    /* leitura das predicoes para os proximos dias */
    for (i = 0; i < num_dias; i++)
        scanf("%d", &valor[i]);

    /* inicializa o maximo capital */
    maximo_capital = capital;

    /* procura as melhores operacoes de compra e venda nos intervalos
       [0,i] e [i+1,num_dias-1] */
    for (i = 0; i < num_dias; i++) {

        /* inicializa o valor do maximo capital obtido pela primeira
           compra-venda */
        capital_cv1 = capital;

        /* procura a melhor compra-venda no intervalo do [0,i] */
        for (j = 0; j <= i; j++) {
            /* procura o maximo pico no intervalo de [j,i] */
            maximo_pico = valor[j];
            for (k = j+1; k <= i; k++)
                if (valor[k] > maximo_pico)
                    maximo_pico = valor[k];
            
            /* calcula o capital obtido quando comprar no j-esimo dia 
                e vender no pico maior posterior a j */
            compra_venda = (capital / valor[j]) * maximo_pico + 
                (capital % valor[j]);

            /* compara o maximo capital atual da primeira compra-venda, 
                com o capital obtido acima */
            if (capital_cv1 < compra_venda)
                capital_cv1 = compra_venda;
        }

        /* inicializa o valor do maximo capital obtido pela segunda
           compra-venda */
        capital_cv2 = capital_cv1;

        /* procura a melhor compra-venda no intervalo do [i+1,num_dias-1] */
        for (j = i+1; j < num_dias; j++) {
            /* procura o maximo pico no intervalo de [j,num_dias-1] */
            maximo_pico = valor[j];
            for (k = j+1; k < num_dias; k++)
                if (valor[k] > maximo_pico)
                    maximo_pico = valor[k];
            
            /* calcula o capital obtido quando comprar no j-esimo dia 
                e vender no pico maior posterior a j */
            compra_venda = (capital_cv1 / valor[j]) * maximo_pico + 
                (capital_cv1 % valor[j]);

            /* compara o maximo capital atual da segunda compra-venda,
               com o capital obtido acima */
            if (capital_cv2 < compra_venda)
                capital_cv2 = compra_venda;
        }

        /* compara o maximo capital atual com o capital obtido apos
            das duas compras-vendas realizados nos intervalos [0,i] e
            [i+1,num_dias-1] */
        if (maximo_capital < capital_cv2)
            maximo_capital = capital_cv2;
    }

    /* se houver um lucro imprimir o maximo capital final */
    if (maximo_capital != capital)
        printf("Capital final = R$%d\n", maximo_capital);
    else
        printf("Melhor nao investir agora, cara!\n");

    return 0;
}
