/* Laboratorio 12a - Tweet Extractor
   Autor: Andre Rodrigues Oliveira
   Email: ra095584@students.ic.unicamp.br
*/

#include <stdio.h>
#include <string.h>

#define MAX_FILENAME 25
#define MAX_TAG 46
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

/* A partir da posicao atual do buffer de leitura, extrai o tweet do
   usuario até encontrar a tag </p> */
void extrai_tweet(FILE *arqin, FILE *arqout) {
    char c;
    int terminou = 0;

    /* enquanto nao encontrar o </p> */
    while (!terminou) {
        c = fgetc(arqin);
        /* se foi lido um '<', verifica se chegou ao </p> e, neste caso, 
           seta terminou como 1. Caso contrario, eh uma tag intermediaria 
           que pode ser ignorada ate encontrar o proximo caractere '>' */
        if (c == '<') {
            c = fgetc(arqin);
            if (c == '/') {
                c = fgetc(arqin);
                if (c == 'p')
                    terminou = 1;
            }
            
            while (c != '>')
                c = fgetc(arqin);
        }
        
        /* se foi lido um '&', chama a funcao que converte
           uma entidade em caractere */
        else if (c == '&') {
            converte_entidade(arqin, arqout);
        }
        
        /* caso contrario, eh um caractere normal do tweet, e deve entao
           ser impresso no arquivo de saida */
        else {
            fprintf(arqout, "%c", c);
        }
    }
}

/* Procura pela tag de inicio de um tweet */
int procura_inicio_tweet(FILE *arqin) {
    char tag_atual[MAX_TAG], c;
    int i, encontrou = 0;
    
    /* enquanto nao chegar ao final do arquivo e nao encontrar a tag p
       de um tweet, pega um caractere do arquivo */
    while (!encontrou && c != EOF) {
        c = fgetc(arqin);
        
        /* se foi lido um '<' seguido de um 'p', salva, enquanto nao
           encontrar o caractere '>' os caracteres em 'tag_atual'. 
           Depois de 25 digitos, verifica se realmente trata-se de uma 
           tag de tweet e, se sim, seta encontrou como 1 */
        if (c == '<') {
            c = fgetc(arqin);
            if (c == 'p') {
                i = 0;
                while (c != '>' && i < MAX_TAG - 1) {
                    c = fgetc(arqin);
                    tag_atual[i++] = c;
                }
                tag_atual[i] = '\0';

                if (!strcmp(tag_atual, 
                            " class=\"ProfileTweet-text js-tweet-text u-dir"))
                    encontrou = 1;
            }
        }
    }
    
    /* Se encontrou, posiciona o buffer de leitura na posicao anterior
       ao inicio do texto do tweet */
    if (encontrou) {
        while (c != '>')
            c = fgetc(arqin);
    }

    return encontrou;
}


/* Funcao que extrai os tweets e imprime no arquivo.out */
void extrai_tweets(char nomearqin[], char nomearqout[]) {
    FILE *arqin, *arqout;
    int encontrou;

    /* abre o arquivo html para leitura e o arquivo
       de saida para imprimir os tweets extraidos */
    arqin = fopen(nomearqin, "r");
    arqout = fopen(nomearqout, "w");

    /* enquanto encontrar tags de tweets chama a funcao que procura a
       tag de inicio do proximo tweet a partir da posicao atual do
       buffer de leitura */
    do {
        encontrou = procura_inicio_tweet(arqin);
        
        /* se encontrou a tag, entao a partir da proxima posicao do
           buffer de leitura extrai o tweet do usuario, e ao termino,
           imprime um \n */
        if (encontrou) {
            extrai_tweet(arqin, arqout);
            fprintf(arqout, "\n");
        }
    } while (encontrou);

    fclose(arqin);
    fclose(arqout);
}

int main(int argc, char *argv[]) {  
    char nomearqin[MAX_FILENAME], nomearqout[MAX_FILENAME];

    strcpy(nomearqin, argv[1]);
    strcpy(nomearqout, argv[2]);
 
    extrai_tweets(nomearqin, nomearqout);

    return 0;
}
