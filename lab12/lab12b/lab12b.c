/* Nome: Ana Carolina R. Barbosa
 * RA: 163755
 * Laboratorio 12b - Bola de Ouro */ 

#include <stdio.h>
#include <string.h>

/* Tamanho maximo do nome do jogador */
#define MAXNOME 26
/* Tamanho maximo do nome dos arquivos de entrada/saida */
#define MAXNOMEARQ 101
/* Numero maximo de jogadores */
#define MAXJOGADORES 40

/* Jogador:
 * nome = nome do jogador
 * C1 = numero de gols
 * C2 = numero de assistencias
 * C3 = numero de dribles feitos
 * C4 = numero de gols contra
 * C5 = numero de cartoes vermelhos
 * C6 = numero de cartoes amarelos
 */
struct Jogador {
    char nome[MAXNOME];
    int C1;
    int C2;
    int C3;
    int C4;
    int C5;
    int C6;
};

typedef struct Jogador Jogador;

int main(int argc, char **argv) {
    /* Nome do arquivo binario com as estatisticas */
    char nomeArqEstat[MAXNOMEARQ];
    /* Nome do arquivo binario de saida */
    char nomeArqSaida[MAXNOMEARQ];
    /* Cria dois arquivos, um de entrada (arqin) e um de saida (arqout) */
    FILE *arqin, *arqout;
    int num, rodadas, numj, i, j, n;
    int w1, w2, w3, w4, w5, w6, c1, c2, c3, c4, c5, c6;
    char nome[MAXNOME];
    Jogador jogador[MAXJOGADORES];
    
    /* Lendo os nomes dos arquivos binarios */
    strcpy(nomeArqEstat, argv[1]);
    strcpy(nomeArqSaida, argv[2]);
    
    /* Abre o arquivo de entrada e cria um de saida */
    arqin = fopen(nomeArqEstat, "rb");
    arqout = fopen(nomeArqSaida, "wb");
    
    /* Le o numero de jogadores presentes no arqin e
     * le os dados dos jogadores presentes no arqin */
    fread(&num, sizeof(int), 1, arqin);
    fread(jogador, sizeof(Jogador), num, arqin);
    
    /* Le os pesos fornecidos na primeira linha */
    scanf("%d %d %d %d %d %d", &w1, &w2, &w3, &w4, &w5, &w6);
    /* Le o numero de rodadas */
    scanf("%d", &rodadas);
    
    for(i=0; i<rodadas; i++){
      /* Le o numero de jogadores a ser atualizado */
      scanf("%d", &numj);
      for (j=0; j<numj; j++){
	/* Le o nome do jogador */
	scanf("%s", nome);
	/* Le os seus dados */
	scanf("%d %d %d %d %d %d", &c1, &c2, &c3, &c4, &c5, &c6);
	/* Procura nos vetores o jogador apontado e atualiza seus dados */
	for(n=0; n<num; n++){
	  if(!(strcmp(nome, jogador[n].nome))){
	    jogador[n].C1 += c1;
	    jogador[n].C2 += c2;
	    jogador[n].C3 += c3;
	    jogador[n].C4 += c4;
	    jogador[n].C5 += c5;
	    jogador[n].C6 += c6;
	  }
	}
      }
    }
    
    for(i=0; i<num; i++){
      printf("%s ", jogador[i].nome);
      printf("%d %d %d %d %d %d", jogador[i].C1, jogador[i].C2, jogador[i].C3, jogador[i].C4, jogador[i].C5, jogador[i].C6);
      printf("\n");
    }
    
    
    fwrite(&num, sizeof(int), 1, arqout);
    fwrite(jogador, sizeof(Jogador), num, arqout);
    
    fclose(arqin);
    fclose(arqout);
    
    
    return 0;
}