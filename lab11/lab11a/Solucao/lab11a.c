/* Laboratorio 11a - Transferencias Bancarias
   Autor: Thierry Pinheiro Moreira
   Email: thierrypin@ic.unicamp.br
 */
 
#include <stdio.h>

typedef struct {
    int numero;
    int agencia;
    double saldo;
    char nome[21];
    char sobrenome[21];
} Conta;

typedef struct {
    int conta_origem;
    int agencia_origem;
    int conta_destino;
    int agencia_destino;
    double valor_transferido;    
} Transferencia;

/*
 * Funcao que encontra o indice da conta dada no vetor de contas
 */
int encontra_conta(Conta contas[], int c, int numero, int agencia) {    
    int i, idx = -1;
    
    for (i = 0; i < c && idx == -1; i++)
        if ((contas[i].numero == numero) && 
            (contas[i].agencia == agencia))
            idx = i;
    
    return idx;
}

/*
 * Funcao que valida a transferencia e move o dinheiro da conta origem
 * para a conta destino
 */
void efetuar_transferencia(Conta contas[], int c, Transferencia transf) {
    int idx_origem, idx_destino;
    
    idx_origem = encontra_conta(contas, c, transf.conta_origem,
            transf.agencia_origem);
    idx_destino = encontra_conta(contas, c, transf.conta_destino,
            transf.agencia_destino);
            
    if ((idx_origem != -1) && (idx_destino != -1) &&
        (transf.valor_transferido <= contas[idx_origem].saldo)) {

        contas[idx_origem].saldo -= transf.valor_transferido;
        contas[idx_destino].saldo += transf.valor_transferido;
    }
}

int main() {
    int c, t, i;
    Conta contas[10];
    Transferencia transferencia;

    scanf("%d %d", &c, &t);

    /* Leitura das contas */
    for (i = 0; i < c; i++)
        scanf("%d@%d %s %s %lf\n", &contas[i].numero, &contas[i].agencia,
                contas[i].nome, contas[i].sobrenome, &contas[i].saldo);
    
    /* Leitura e realizacao das transferencias */
    for (i = 0; i < t; i++) {
        scanf("%d@%d >> %lf >> %d@%d\n", 
              &transferencia.conta_origem,
              &transferencia.agencia_origem, 
              &transferencia.valor_transferido,
              &transferencia.conta_destino, 
              &transferencia.agencia_destino);
        efetuar_transferencia(contas, c, transferencia);
    }
    
    /* Saida */
    for (i = 0; i < c; i++)
        printf("%d@%d %s %s %.2f\n", contas[i].numero, contas[i].agencia,
                contas[i].nome, contas[i].sobrenome, contas[i].saldo);
    
    return 0;
}
