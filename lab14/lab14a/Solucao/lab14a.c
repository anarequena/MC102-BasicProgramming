/* Laboratorio 14a - Cargo-Bot - Part III
   Autor: Andre Rodrigues Oliveira
   Email: andre.oliveira@students.ic.unicamp.br
*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

/* funcao que executa as operacoes do programa curr_prog recursivamente  */
void execute_program(char **boxes, char **programs, char *holding, 
                     int *accident, int *current_position, int *num_execs,
                     int curr_prog, int max_height, int total_positions) {
    int j, k, cond;
    
    j = 0;

    /* decrementa o num_execs antes de executar o programa */
    (*num_execs)--;

    /* executa curr_prog enquanto nao alcancar o '*' ou ocorrer um
       acidente com as caixas */
    while ((programs[curr_prog][j] != '*') && (!(*accident))) {
        cond = TRUE;

        /* verifica se o caractere eh um condicional e, se for, o valida */
        switch(programs[curr_prog][j]) {
            case 'A':
                j++;
                if (!*holding)
                    cond = FALSE;
                break;
            case 'N':
                j++;
                if (*holding)
                    cond = FALSE;
                break;
            case 'B':
                j++;
                if (*holding != 'B')
                    cond = FALSE;
                break;
            case 'G':
                j++;
                if (*holding != 'G')
                    cond = FALSE;
                break;
            case 'Y':
                j++;
                if (*holding != 'Y')
                    cond = FALSE;
                break;
        }

        /* verifica se deve executar o comando basico ou a chamada a
           um programa */
        if (cond) {
            /* se o comando eh mover a esquerda e ele nao esta na
               posicao mais a esquerda */
            if ((programs[curr_prog][j] == 'L') && (*current_position > 0)) {
                /* move o braco a esquerda */
                (*current_position)--;
                         
                /* verifica se causou um acidente */
                if ((boxes[0][*current_position] != '.') && (*holding))
                    *accident = TRUE;

                /* se o comando eh mover a direita e ele nao esta na
                   posicao mais a direita */
            } else if ((programs[curr_prog][j] == 'R') && 
                       (*current_position < total_positions - 1)) {

                /* move o braco a direita */
                (*current_position)++;
                         
                /* verifica se causou um acidente */
                if ((boxes[0][*current_position] != '.') && (*holding))
                    *accident = TRUE;
                    
                /* se o comando eh descer o braco */
            } else if (programs[curr_prog][j] == 'D') {

                /* se ele esta segurando uma caixa, deixa a caixa naquela
                   posicao */
                if (*holding) {
                    /* deixa a caixa no nivel correto da pilha */
                    k = 0;
                    while ((k < max_height - 1) && 
                           (boxes[k+1][*current_position] == '.'))
                        k++;
                    boxes[k][*current_position] = *holding;
                    *holding = FALSE;

                  /* se ele nao esta segurando uma caixa, mas existe
                     uma caixa naquela posicao, desce e pega a caixa */
                } else if (boxes[max_height-1][*current_position] != '.') {
                    k = 0;
                    while ((boxes[k][*current_position] == '.') && 
                           (k < max_height-1))
                        k++;
                    
                    *holding = boxes[k][*current_position];
                    boxes[k][*current_position] = '.';
                }
                /* se o comando eh chamar outro programa */
            } else if ((programs[curr_prog][j] >= '1') && 
                       (programs[curr_prog][j] <= '9')) {
                /* se ainda nao atingiu o numero maximo de execucoes */
                if (*num_execs > 0) {
                    /* chama recursivamente para executar o programa armazenado
                       na posicao j do programa atual */
                    execute_program(boxes, programs, holding,
                                    accident, current_position, num_execs, 
                                    (int)programs[curr_prog][j] - 49, 
                                    max_height, total_positions);
                }
            }
        }
        
        /* vai para o proximo comando do programa */
        j++;
    
    }
}


int main() {
    /* variaveis da posicao atual do braco mecanico e se existe uma caixa */
    int current_position = 0;
     
    /* variaveis do numero de posicoes, maximo de caixas por posicao,
       numero de programas, numero de comandos e numero de execucoes */
    int total_positions, max_height, num_progs, max_commands, num_execs;
    
    /* variaveis que armazenam a situacao das caixas, sequencia de execucao, 
       os comandos dos programas e a cor da caixa que o braco esta segurando */
    char **boxes, **programs, holding = FALSE;
     
    /* variaveis auxiliares */
    int i, accident = FALSE;

    /* leitura do numero de posicoes, tamanho maximo e numero de programas,
       numero de comandos e numero de execucoes */
    scanf("%d %d %d %d %d\n", &total_positions, &max_height, &num_progs, 
          &max_commands, &num_execs);

    /* alocacao das matrizes da configuracao das caixas e dos programas*/
    boxes = malloc(sizeof(char*)*max_height);
    for (i = 0; i < max_height; i++)
        boxes[i] = malloc(sizeof(char)*total_positions+1);
    
    programs = malloc(sizeof(char*)*num_progs);
    for (i = 0; i < num_progs; i++)
        programs[i] = malloc(sizeof(char)*max_commands+1);

    /* leitura da situacao inicial das caixas em cada posicao */
    for (i = 0; i < max_height; i++)
        scanf("%s\n", boxes[i]);

    /* leitura dos programas */
    for (i = 0; i < num_progs; i++)
        /* pega o \n anterior e o primeiro comando do programa atual */
        scanf("%s\n", programs[i]);
        
    /* roda o programa 1 (posicao 0 na matriz de programas), que pode ou nao
       chamar outros durante sua execucao */
    execute_program(boxes, programs, &holding, &accident, &current_position,
                    &num_execs, 0, max_height, total_positions);

    /* se durante a execucao de comandos ocorreu um acidente, imprime */
    if (accident) {
        printf("Um acidente ocorreu\n");
    } else {
        /* caso contrario, imprime a quantidade de caixas em cada posicao */
        for (i = 0; i < max_height; i++)
            printf("%s\n", boxes[i]);
    }

    /* desaloca as matrizes que armazenavam as caixas e programas */
    for (i = 0; i < max_height; i++)
        free(boxes[i]);
    free(boxes);
    
    for (i = 0; i < num_progs; i++)
        free(programs[i]);
    free(programs);
     
    return 0;
}
