/* Nome: Ana Carolina R. Barbosa
 * RA: 163755
 * Laboratório 11a - Transferências Bancárias */

#include <stdio.h>
#include <stdlib.h>

/* define um registro para cada cliente */
typedef struct {
  double saldo;
  int conta, agencia;
  char nome[20], sobrenome[20];
} banco;

typedef struct {
  int conta_origem, agencia_origem, conta_destino, agencia_destino;
  double dinheiro;
} transferir;


int main () {
  banco *cliente;
  transferir *transferencia;
  int c, t, i, j, origem, destino; 
  
  /* le o numero de clientes e o numero de transferencias feitas no dia */
  scanf ("%d %d", &c, &t);
  
  cliente = malloc(c * sizeof(banco));
  transferencia = malloc(t * sizeof(transferir));
  
  /* le as contas bancarias fornecidas */
  for (i=0; i<c; i++){
    scanf ("%d@%d", &cliente[i].conta, &cliente[i].agencia);
    scanf ("%s %s", cliente[i].nome, cliente[i].sobrenome);
    scanf ("%lf", &cliente[i].saldo);
  }
  

  for (i=0; i<t; i++){  
    /* le os dados das transferencias */
    scanf ("%d@%d", &transferencia[i].conta_origem, &transferencia[i].agencia_origem);
    scanf (" >> ");
    scanf ("%lf", &transferencia[i].dinheiro);
    scanf (" >> ");
    scanf ("%d@%d", &transferencia[i].conta_destino, &transferencia[i].agencia_destino);
    
    /* verifica se há um cliente correspondente a conta de origem fornecida */
    origem = -1;
    for (j=0; j<c; j++){
      if ((transferencia[i].conta_origem == cliente[j].conta) && (transferencia[i].agencia_origem == cliente[j].agencia))
	origem = j;
    }
    /* verifica se há um cliente correspondente a conta de destino fornecida */
    destino = -1;
    for (j=0; j<c; j++){
      if ((transferencia[i].conta_destino == cliente[j].conta) && (transferencia[i].agencia_destino == cliente[j].agencia))
	destino = j; 
    }
    
    /* se ambas as contas de origem e de destino forem válidas, executa a transferencia */
    if ((origem >= 0) && (destino >= 0)){
      /* se o novo saldo do cliente de origem for menor que zero, invalida a transferencia */ 
      if (cliente[origem].saldo - transferencia[i].dinheiro >= 0){
	cliente[origem].saldo -= transferencia[i].dinheiro;
	cliente[destino].saldo += transferencia[i].dinheiro;
      }
    }
  }
  
  /* imprime o estado final das contas bancarias */
  for (i=0; i<c; i++){
    printf ("%d@%d ", cliente[i].conta, cliente[i].agencia);
    printf ("%s %s ", cliente[i].nome, cliente[i].sobrenome);
    printf ("%.2f\n", cliente[i].saldo); 
  }
  
  free(cliente);
  free(transferencia);
  
  return 0;
  
}
  
  
  