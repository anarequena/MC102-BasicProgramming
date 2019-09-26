/* Laboratorio 04a - Cargo-Bot - Part I
   Autor: Andre Rodrigues Oliveira
   Email: andre.oliveira@students.ic.unicamp.br
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main() {
    /* variaveis da posicao atual do braco mecanico e se existe uma caixa */
    int current_position = 0, holding_box = FALSE;
     
    /* variaveis do numero de posicoes, caixas por posicao e altura maximo */
    int boxes[10], total_positions, max_height;
     
    /* variaveis auxiliares */
    int i, accident = FALSE;
    char command;

    /* leitura do numero de posicoes e tamanho maximo */
    scanf("%d %d", &total_positions, &max_height);

    /* leitura do numero de caixas em cada posicao */
    for (i = 0; i < total_positions; i++)
        scanf("%d", &boxes[i]);

    /* leitura do primeiro comando a ser executado */
    scanf("\n%c", &command);
     
    /* enquanto existir comandos na entrada, e um acidente nao ocorrer */
    while ((command != '*') && !accident) {
             
        /* se o comando eh mover a esquerda e ele nao esta na posicao
             mais a esquerda */
        if ((command == 'L') && (current_position > 0)) {
            /* move o braco a esquerda */
            current_position--;
                     
            /* verifica se causou um acidente */
            if ((boxes[current_position] == max_height) && 
                    (holding_box == TRUE))
                accident = TRUE;

            /* se o comando eh mover a direita e ele nao esta na posicao
                 mais a direita */
        } else if ((command == 'R') && 
                             (current_position < total_positions - 1)) {

            /* move o braco a direita */
            current_position++;
                     
            /* verifica se causou um acidente */
            if ((boxes[current_position] == max_height) && 
                    (holding_box == TRUE))
                accident = TRUE;
                
            /* se o comando eh descer o braco */
        } else if (command == 'D') {

            /* se ele esta segurando uma caixa, deixa a caixa naquela
                 posicao */
            if (holding_box == TRUE) {
                boxes[current_position]++;
                holding_box = FALSE;

                /* se ele nao esta segurando uma caixa, e existe uma caixa na
                     posicao em que o braco se encontra, pega uma caixa */
            } else if (boxes[current_position] > 0) {
                boxes[current_position]--;
                holding_box = TRUE;
            }
        }
             
        scanf("%c", &command);
    }

    /* se durante a execucao de comandos ocorreu um acidente, imprime */
    if (accident) {
        printf("Um acidente ocorreu\n");
    } else {
        /* caso contrario, imprime a quantidade de caixas em cada posicao */
        for (i = 0; i < total_positions -1; i++)
            printf("%d ", boxes[i]);
        printf("%d\n", boxes[total_positions - 1]);
    }
     
    return 0;
}
