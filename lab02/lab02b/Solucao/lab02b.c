/* Laboratorio 02b - Dolares Elficos
   Autor: Javier Alvaro Vargas Munoz
   Email: ra153620@students.ic.unicamp.br
*/

#include <stdio.h>

int main() {
    /* variaveis da entrada */
    int num_casas, gramas, taxa, tipo_notas;

    /* variaveis auxiliares */
    int i, total;

    /* variaveis para o calculo do minimo */
    int min_global = 0, min_casa = 0;

    /* leitura do numero de casas de cambio, quantidade de gramas e
         taxa de conversao */
    scanf("%d %d %d", &num_casas, &gramas, &taxa);

    /* inicializa o minimo global com o maior valor que este pode ter */
    min_global = gramas * taxa;

    for (i = 0; i < num_casas; i++) {
        /* leitura do tipo de notas da i-esima casa */
        scanf("%d", &tipo_notas);

        /* inicializa o total de dolares elficos a serem trocados e o
             minimo numero de notas obtidas na i-esima casa */
        total = gramas * taxa;
        min_casa = 0;
		
        /* converte o valor total para a base 'tipo_notas', por meio
           de divisoes sucessivas, e soma os digitos em 'min_casa' */
        while (total != 0) {
            min_casa += (total % tipo_notas);
            total /= tipo_notas;
        }

        /* compara o minimo obtido na i-esima casa com o minimo global */
        if (min_global > min_casa)
            min_global = min_casa;
    }

    /* imprime o resultado */
    printf("Numero minimo de notas = %d\n", min_global);

    return 0;
}
