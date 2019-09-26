#include <stdio.h>
#include <math.h>

int main () {
  double ax, ay, az, bx, by, bz, e;
  

  printf ("Dê as coordenadas de A e B, em x, y e z");
  scanf ("%lf %lf %lf %lf %lf %lf", &ax, &ay, &az, &bx, &by, &bz);

  e = sqrt(pow(ax-bx,2) + pow(ay-by,2) + pow(az-bz,2));

  printf ("A medida euclidiana entre A e B é %.2f\n", e);

  return 0;

}
