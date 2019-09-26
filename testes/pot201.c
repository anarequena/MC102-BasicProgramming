#include <stdio.h>
int main() {
int i = 1, pot = 2, n;
scanf("%d", &n);
while (i <= n) {
printf("2^%d = %d\n", i, pot);
i++;
pot *= 2;
}
return 0;
}