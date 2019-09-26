#include <stdio.h>
#define XXX 3
int main() {
int a, b, c;
a = 7 + 9 + XXX;
b = a + 10;
c = b;
c = c - a;
printf("%d\n", c);
return 0;
}
