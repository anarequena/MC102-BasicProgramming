#include <stdio.h>
int main() {
int total = 0, parcela;
do {
printf("Entre com o valor da parcela: ");
scanf("%d", &parcela);
total += parcela;
} while (parcela);
printf("Valor total = %d\n", total);
return 0;
}