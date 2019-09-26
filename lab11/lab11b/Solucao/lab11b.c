/* Laboratorio 11b - Brasil, o Pais do Volei
 * Autor: Gustavo Rodrigues Galvao
 * E-mail: ggalvao@ic.unicamp.br
 */

#include <stdio.h>
#include <string.h>

struct time {
   char nome[21];
   int indice, pontos, vitorias;
   int pontosGanhos, pontosPerdidos, setsGanhos, setsPerdidos; 
};
typedef struct time time_t;

/* Recupera o time no vetor de times pelo nome, criando um novo caso seja 
   a primeira vez que estejamos acessando-o */
time_t* obtemTime(time_t times[], int *n, char nome[]) {
   int i;
 
   /* tenta encontrar time ja inicializado */
   for (i = 0; i < *n; i++)
      if (strcmp(times[i].nome, nome) == 0)
         return &times[i];
   
   /* se nao encontrou, inicializa um novo time */
   strcpy(times[*n].nome, nome);
   times[*n].indice = *n;
   times[*n].pontos = 0;
   times[*n].vitorias = 0;
   times[*n].pontosGanhos = 0;
   times[*n].pontosPerdidos = 0;
   times[*n].setsGanhos = 0;
   times[*n].setsPerdidos = 0;

   (*n)++;

   return &times[*n-1];
}

/* Atualiza os atributos relativos aos sets e aos pontos */
void atualizaSetsPontos(time_t *time, int setsGanhos, int setsPerdidos, 
                        int pontosGanhos, int pontosPerdidos) {
   time->setsGanhos += setsGanhos;
   time->setsPerdidos += setsPerdidos;
   time->pontosGanhos += pontosGanhos;
   time->pontosPerdidos += pontosPerdidos;
}

/* Atualiza os atributos relativos as partidas */
void atualizaPartida(time_t *timeGanhador, time_t *timePerdedor, int difSets, 
                     int confrontoDireto[][6]) {
   timeGanhador->vitorias++;

   if (difSets > 1)
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
   char X[21], Y[21];
   time_t *timeX, *timeY;
   int i, n, pontosX, pontosY, totalPontosX, totalPontosY, setsX, setsY;
   
   n = 0;

   for (i = 0; i < 15; i++) {
      scanf("%s %s", X, Y);
      
      setsX = 0;
      setsY = 0;
      totalPontosX = 0;
      totalPontosY = 0;

      do {
        scanf("%d-%d", &pontosX, &pontosY);
        
        if (pontosX > pontosY)
           setsX++;
        else
           setsY++;

        totalPontosX += pontosX;
        totalPontosY += pontosY;
      } while ((setsX <= 2) && (setsY <= 2));

      timeX = obtemTime(timesChave, &n, X);
      timeY = obtemTime(timesChave, &n, Y);

      atualizaSetsPontos(timeX, setsX, setsY, totalPontosX, totalPontosY);
      atualizaSetsPontos(timeY, setsY, setsX, totalPontosY, totalPontosX);

      if (setsX > setsY) 
         atualizaPartida(timeX, timeY, setsX-setsY, confrontoDireto);
      else
         atualizaPartida(timeY, timeX, setsY-setsX, confrontoDireto);
   }
}

/* Compara um time A com um time B. Retorna 1 se o time A eh melhor
   que o time B e retorna -1 caso contrario. Supoe que o timeA e o
   timeB sao diferentes */
int comparaTimes(time_t timeA, time_t timeB, int confrontoDireto[][6]) {
   int razaoSetA, razaoSetB, razaoPontosA, razaoPontosB;

   if (timeA.pontos > timeB.pontos)
      return 1;
   else if (timeA.pontos == timeB.pontos) {
      if (timeA.vitorias > timeB.vitorias)
         return 1;
      else if (timeA.vitorias == timeB.vitorias) {
         razaoSetA = timeA.setsGanhos*(timeB.setsGanhos + timeB.setsPerdidos);
         razaoSetB = timeB.setsGanhos*(timeA.setsGanhos + timeA.setsPerdidos);

         if (razaoSetA > razaoSetB)
            return 1;
         else if (razaoSetA == razaoSetB) {
            razaoPontosA = timeA.pontosGanhos*(timeB.pontosGanhos 
                                               + timeB.pontosPerdidos);
            razaoPontosB = timeB.pontosGanhos*(timeA.pontosGanhos 
                                               + timeA.pontosPerdidos);

            if (razaoPontosA > razaoPontosB)
               return 1;
            else if (razaoPontosA == razaoPontosB)
               return confrontoDireto[timeA.indice][timeB.indice];
         }
      }
   }

   return -1;
}

/* Ordena o vetor de times com insertion sort */
void ordenaTimes(time_t times[], int n, int confrontoDireto[][6]) {
    int i, j;
    time_t aux;

    for (i = 1; i < n; i++) {
        aux = times[i];

        for (j = i-1; j >= 0 && 
                      comparaTimes(times[j], aux, confrontoDireto) < 0; j--)
            times[j+1] = times[j];

        times[j+1] = aux;
    }
}

int main() {
   /* variaveis de entrada */
   time_t timesChaveA[6], timesChaveB[6];
   /* variaveis auxiliares */
   int i, confrontosChaveA[6][6], confrontosChaveB[6][6];

   /* le entrada */
   leResultadosChave(timesChaveA, confrontosChaveA);
   leResultadosChave(timesChaveB, confrontosChaveB);
  
   /* ordena os vetores de times na ordem de classificacao */
   ordenaTimes(timesChaveA, 6, confrontosChaveA);
   ordenaTimes(timesChaveB, 6, confrontosChaveB);

   /* imprime a saida */
   for (i = 0; i < 4; i++) {
      printf("%s x %s\n", timesChaveA[i].nome, timesChaveB[3-i].nome);
   }

   return 0;
}
