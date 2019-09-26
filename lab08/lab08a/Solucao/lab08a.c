/* Laboratorio 08a - BigCalc
 * Autor: Andre Rodrigues Oliveira
 * E-mail: ra095584@students.ic.unicamp.br
 */

#include <stdio.h>
#include <stdlib.h>

/* faz uma alocacao do tamanho desejado e zera todas as posicoes */
int* allocate_number(int tamanho) {
    int i, *v;

    v = malloc(sizeof(int)*tamanho);

    for (i = 0; i < tamanho; i++)
        v[i] = 0;

    return v;
}

/* imprime o resultado que esta armazenado ao contrario no vetor */
void print_result(int *result, int tam) {
    int i = tam - 1;

    while (result[i] == 0 && i >= 0)
        i--;

    if (i < 0)
        printf("0");
    else
        while (i >= 0)
            printf("%d", result[i--]);

    printf("\n");
}

/* pega o numero na entrada, digito a digito, armazenando-o ao
   contrario no vetor n */
void get_number(int *n, int tamanho) {
    char auxc;
    int auxi;

    for (auxi = tamanho - 1; auxi >= 0; auxi--) {
        scanf("%c", &auxc);
        /* armazena a conversao do digito de aux para int */
        n[auxi] = auxc - '0';
    }
}

/* realiza a adicao n1*n2, armazendo o resultado em result */
void add(int *n1, int tam_n1, int *n2, int tam_n2, int *result) {
    int i, aux = 0;

    for (i = 0; i < tam_n1; i++) {
        /* se ainda existem digitos em n2, soma n1[i] com n2[i] com aux */
        if (i < tam_n2)
            result[i] = n1[i] + n2[i] + aux;
        /* senao, faz apenas n1[i] + aux */
        else
            result[i] = n1[i] + aux;
        /* se o resultado ficou maior que 9, tira 10 e sinaliza aux
           para somar ao proximo digito */
        if (result[i] > 9) {
            aux = 1;
            result[i] = result[i] - 10;
        /* senao, apenas zera aux */
        } else
            aux = 0;
    }
    
    if (aux > 0)
        result[tam_n1] = aux;
}

/* realiza a subtracao n1-n2, com n1>=n2, armazenando o resultado em
   result */
void substract(int *n1, int tam_n1, int *n2, int tam_n2, int *result) {
    int i, aux = 0;

    for (i = 0; i < tam_n1; i++) {
        /* se ainda existem digitos em n2, subtrai de n1[i] aux e n2[i] */
        if (i < tam_n2)
            result[i] = n1[i] - n2[i] - aux;
        /* senao, faz apenas n1[i] - aux */
        else
            result[i] = n1[i] - aux;

        /* se result[i] e negativo, soma 10 e sinaliza aux
            para tirar uma unidade do proximo digito */
        if (result[i] < 0) {
            aux = 1;
            result[i] = result[i] + 10;
        } else
            /* senao, apenas zera aux */
            aux = 0;
    }
}

/* realiza a multiplicacao n1*n2, armazendo o resultado em result */
void multiply(int *n1, int tam_n1, int *n2, int tam_n2, int *result) {
    int i, j, aux=0, *vet;

    for (i = 0; i < tam_n2; i++) {
        /* aloca um vetor auxiliar para guardar o resultado de n2[i] * n1 */
        vet = allocate_number(tam_n1 + tam_n2);

        for (j = 0; j < tam_n1; j++) {
            vet[i+j] = n2[i] * n1[j] + aux;
            /* se o resultado ficou maior que 9, pega o modulo 10 e atualiza
               aux para somar ao proximo digito, senao apenas zera aux */
            if (vet[i+j] > 9) {
                aux = vet[i+j]/10;
                vet[i+j] = vet[i+j] % 10;
            } else
                aux = 0;
        }

        if (aux > 0) {
            vet[i+j] = aux;
            aux = 0;
        }

        /* adiciona no vetor result a operacao n2[i]*n1 */
        add(result, tam_n1 + tam_n2, vet, tam_n1 + tam_n2, result);

        free(vet);
    }
}

int main() {
    /* armazena os dois numeros e o tamanho dos mesmos */
    int *n1, *n2, tam_n1, tam_n2, *result;
    /* armazena a operacao a ser feita */
    char op, auxc;
    
    /* pega o tamanho dos dois numeros e a operacao a ser realizada */
    scanf("%d %d %c\n", &tam_n1, &tam_n2, &op);
    
    /* aloca vetores para armazenar os dois numeros e o resultado */
    n1 = allocate_number(tam_n1);
    n2 = allocate_number(tam_n2);
    
    /* pega os dois numeros na entrada */
    get_number(n1, tam_n1);
    scanf("%c", &auxc);
    get_number(n2, tam_n2);
    
    /* Seleciona, realiza e imprime o resultado da operacao */
    switch (op) {
        case 'A':
            result = allocate_number(tam_n1 + 1);
            add(n1, tam_n1, n2, tam_n2, result);
            print_result(result, tam_n1 + 1);
            break;
        case 'S':
            result = allocate_number(tam_n1);
            substract(n1, tam_n1, n2, tam_n2, result);
            print_result(result, tam_n1);
            break;
        case 'M':
            result = allocate_number(tam_n1 + tam_n2);
            multiply(n1, tam_n1, n2, tam_n2, result);
            print_result(result, tam_n1 + tam_n2);
            break;
    }
    
    /* desaloca os vetores */
    free(n1);
    free(n2);
    free(result);
    
    return 0;
}
