/* Nome: Ana Carolina Requena Barbosa
 * RA: 163755
 * Laboratorio 12a - Tweet Extractor */

#include <stdio.h>
#include <string.h>

#define MAX_FILENAME 25
#define MAX_ENTITY 10

/* Funcao que converte uma entidade no caractere correspondente,
   supondo que o caractere '&' foi previamente lido no arquivo de
   entrada (arqin). Se a entidade eh diferente de aspas simples ou
   aspas dupla, a funcao simplesmente o ignora, caso contrario ela
   imprime o caractere correspondente no arquivo de saida (arqout). */
void converte_entidade(FILE *arqin, FILE *arqout) {
    char c, entidade[MAX_ENTITY];
    int i = 0;
    
    /* armazena o codigo da entidade ate encontrar o caractere ';' */
    c = fgetc(arqin);
    while (c != ';') {
        entidade[i++] = c;
        c = fgetc(arqin);
    }
    entidade[i] = '\0';
    
    /* se a entidade corresponde ao caractere aspas simples ou aspas duplas,
       imprime o caractere no arquivo de saida */
    if (!strcmp(entidade, "#39"))
        fprintf(arqout, "\'");
    else if(!strcmp(entidade, "quot"))
        fprintf(arqout, "\"");
}

void extrai_tweets(char nomearqin[], char nomearqout[]) {
  FILE *arqin, *arqout;
  int flag;
  char aux;
  char valor[81], search[] = "p class=\"ProfileTweet-text js-tweet-text u-dir\""; 
  
  arqin = fopen(nomearqin, "r");
  arqout = fopen(nomearqout, "w"); 
  
  /* le o arqin até o final */
  while (fscanf(arqin, "%c", &aux) != EOF){
    /* se o caractere lido for '<' */
    if (aux == '<'){
      /* executa o loop até */
      while ((aux != '>')&&(aux != '\n')){
	/* le o que esta escrito apos o '<' */  
	fgets(valor, 48, arqin);
	aux = '>';
	
	/* verifica se o valor lido é igual ao search,
	 * a fim de iniciar a leitura do tweet */ 
	if (!(strcmp(valor, search))){
	  flag = 1;
	  /* imprime o que esta dentro do tweet até o final do mesmo */
	  while (flag){
	    fscanf(arqin, "%c", &aux);
	    /* descarta o que vier antes do '>' */
	    while(aux != '>')
	      fscanf(arqin, "%c", &aux);
	    /* le o tweet entre os '>' e '<' */
	    while(aux != '<'){
	      fscanf(arqin, "%c", &aux);
	      /* se aux for diferente de '<', imprime o tweet */ 
	      if (aux != '<'){
		/* se aux for igual a '&', converte o codigo por ' ou " */
		if(aux == '&')
		  converte_entidade(arqin, arqout);
		else
		  fprintf(arqout, "%c", aux); 
	      }
	    }
	    
	    /* le depois de '<' */
	    fscanf(arqin, "%c", &aux);
	    /* se o que for lido for igual a '\p',
	     * termina a leitura e impressao do tweet */
	    if (aux == '/'){
	      fscanf(arqin, "%c", &aux);
	      if (aux == 'p'){
		fscanf(arqin, "%c", &aux);
		if(aux == '>'){
		  flag = 0;
		  fprintf(arqout, "\n");
		}
	      }
	    }
	  }
	}
      }
    }
  }
  
  fclose(arqin);
  fclose(arqout);  
}


int main(int argc, char *argv[]) {  
    char nomearqin[MAX_FILENAME], nomearqout[MAX_FILENAME];
    
    /* Copia os nomes do arquivo de entrada e de saida nas variaveis */
    strcpy(nomearqin, argv[1]);
    strcpy(nomearqout, argv[2]);
 
    extrai_tweets(nomearqin, nomearqout);

    return 0;
}
