#include <stdlib.h>
#include "monticulo.h"
int main(void)
{
    srand(time(NULL));
    Monticulo m;
  int i,n=10;
  tipoElemento elemento;

 iniciaMonticulo(&m);

 m.tamanno=n;
 for (i=1;i<=n;i++) m.elemento[i].clave=rand()%100;
 for (i=1;i<=m.tamanno;i++)
   printf("%d ",m.elemento[i].clave);
 printf("\n");
(esMonticulo(m))?printf("Es monticulo\n"):printf("No es monticulo\n");
 heapsort(&m);
 puts("HEAPSORT MONTICULOS");
 for (i=1;i<=m.tamanno;i++)
   printf("%d ",m.elemento[i].clave);
 printf("\n");

}




