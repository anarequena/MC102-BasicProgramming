#include <stdio.h>
#include <math.h>
int main() {
double a, b, c;
printf("Entre com os valores dos catetos: ");
scanf("%lf %lf", &a, &b);
c = sqrt(pow(a,2) + pow(b,2));
printf("Hipotenusa: %.2f\n", c);
return 0;
}