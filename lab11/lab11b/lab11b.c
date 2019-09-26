/* Laboratorio 11b - Brasil, o Pais do Volei
 * Nome: Ana Carolina Requena Barbosa
 * RA: 163755 */

#include <stdio.h>
#include <string.h>

struct time {
   char nome[21];
   int indice,
   pontos, 
   vitorias;
   int pontosGanhos, 
   pontosPerdidos, 
   setsGanhos, 
   setsPerdidos; 
};
typedef struct time time_t;

/* Atualiza os atributos relativos aos sets e aos pontos */
void atualizaSetsPontos(time_t *time, int setsGanhos, int setsPerdidos, 
                        int pontosGanhos, int pontosPerdidos) {
   time->setsGanhos += setsGanhos;
   time->setsPerdidos += setsPerdidos;
   time->pontosGanhos += pontosGanhos;
   time->pontosPerdidos += pontosPerdidos;
}

/* Atualiza os atributos relativos as partidas */
void atualizaPartida(time_t *timeGanhador, time_t *timePerdedor, 
                     int diferencaSets, int confrontoDireto[][6]) {
   timeGanhador->vitorias++;

   if (diferencaSets > 1)
      timeGanhador->pontos += 3;
   else {
      timeGanhador->pontos += 2;
      timePerdedor->pontos += 1;
   }

   confrontoDireto[timeGanhador->indice][timePerdedor->indice] = 1;
   confrontoDireto[timePerdedor->indice][timeGanhador->indice] = -1;
}

/* Le os resultados das partidas entre todos os times de uma chave */
void leResultadosChave(time_t timesChave[], int confrontoDireto[][6]) {
  int i, j, k, pontos1, pontos2, totalpontos1, totalpontos2; 
  int jogoEncerrado, setGanho1, setGanho2;
  char nome1[21], nome2[21];
  
  for (i=0; i<15; i++){
    totalpontos1=0;
    totalpontos2=0;
    setGanho1=0;
    setGanho2=0;
    scanf ("%s %s", nome1, nome2);
    jogoEncerrado=1;
    /* enquanto o jogo não terminar, le cada set */
    for (j=0; jogoEncerrado && j<5; j++){
      /* le os pontos do time1 e do time2 */
      scanf ("%d-%d", &pontos1, &pontos2);
      /* soma os pontos ao total de pontos de cada time */
      totalpontos1 += pontos1; 
      totalpontos2 += pontos2;
      
      /* se um time tiver pontuacao maior que 25 e a vantagem for de 2 pontos ou mais,
       * esse time ganha o set */
      if (pontos2 > pontos1)
	setGanho2++;
      else if (pontos1 > pontos2 )
	setGanho1++;
        
      /* se algum dos times alcancar tres sets ganhos, o jogo é encerrado */
      if (setGanho1==3){
	jogoEncerrado = 0;
      } else if(setGanho2==3){
	jogoEncerrado = 0;
      }
    }
    
    /* soma o indice j até achar o nome do time ou o nome '0' */
    for (j=0; strcmp(nome1, timesChave[j].nome) != 0 && timesChave[j].nome[0] != '\0'; j++);
    /* se o nome não for achado na chave,
     * armazena o nome lido em um registro da chave */
    if (timesChave[j].nome[0] == '\0'){
	strcpy(timesChave[j].nome, nome1);
	timesChave[j].indice = j;
    }      
    
    /* atualiza as informacoes no registro */
    atualizaSetsPontos(&timesChave[j], setGanho1, setGanho2, totalpontos1, totalpontos2);
    
    
    /* soma o indice k até achar o nome do time ou o nome '0' */
    for (k=0;strcmp(nome2, timesChave[k].nome) != 0 && timesChave[k].nome[0] != '\0'; k++);
    /* se o nome não for achado na chave,
     armazena o nome lido em um registro da chave */
    if (timesChave[k].nome[0] == '\0'){
	strcpy(timesChave[k].nome, nome2);
	timesChave[k].indice = k;
    }      
    /* atualiza as informacoes no registro */
    atualizaSetsPontos(&timesChave[k], setGanho2, setGanho1, totalpontos2, totalpontos1);  
  }
 
  for (j=0; j<6; j++){
    printf ("\n");
    printf ("%s ", timesChave[j].nome);
    printf ("%d ", timesChave[j].pontosGanhos);
    printf ("%d ", timesChave[j].pontosPerdidos);
    printf ("%d ", timesChave[j].setsGanhos);
    printf ("%d ", timesChave[j].setsPerdidos);
    printf ("\n");
  }
  
}

/* Ordena o vetor de times 
void ordenaTimes(time_t times[], int n, int confrontoDireto[][6]) {

}*/

int main() {
   /* variaveis de entrada */
   time_t timesChaveA[6], timesChaveB[6];
   /* variaveis auxiliares */
   int i, confrontosChaveA[6][6], confrontosChaveB[6][6];
   
   /* inicializa os registros */
   for (i=0; i<6; i++){
     timesChaveA[i].nome[0] = '\0';
     timesChaveA[i].indice = i;
     timesChaveA[i].pontos = 0; 
     timesChaveA[i].vitorias = 0;
     timesChaveA[i].pontosGanhos = 0;
     timesChaveA[i].pontosPerdidos = 0;
     timesChaveA[i].setsGanhos = 0;
     timesChaveA[i].setsPerdidos = 0;
     
     timesChaveB[i].nome[0] = '\0';
     timesChaveB[i].indice = i;
     timesChaveB[i].pontos = 0; 
     timesChaveB[i].vitorias = 0;
     timesChaveB[i].pontosGanhos = 0;
     timesChaveB[i].pontosPerdidos = 0;
     timesChaveB[i].setsGanhos = 0;
     timesChaveB[i].setsPerdidos = 0;
   }

   /* le entrada */
   leResultadosChave(timesChaveA, confrontosChaveA);
   leResultadosChave(timesChaveB, confrontosChaveB);
  
   /* ordena os vetores de times na ordem de classificacao 
   ordenaTimes(timesChaveA, 6, confrontosChaveA);
   ordenaTimes(timesChaveB, 6, confrontosChaveB);
   */
   
   /* imprime a saida *
   for (i = 0; i < 4; i++) {
      printf("%s x %s\n", timesChaveA[i].nome, timesChaveB[3-i].nome);
   } */

   return 0;
}