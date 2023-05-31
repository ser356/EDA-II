#include "funciones.h"
#include <stdio.h>
int main(){
tipoArbolBB arbol=NULL;
printf("El numero de apellidos diferentes es:...%d\n",genABB("alumnos.dat",&arbol));
recorreArbol(arbol);
return 0;
}


