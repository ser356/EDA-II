#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main(){

creaHash("alumnos.dat","alumnos.hash");
//leeHash("alumnos.hash");

if(modificarReg("alumnos.hash","6883822","SEVILLA")>=0)
    printf("Se ha encontrado en el CUBO %d\n",modificarReg("alumnos.hash","6883822","SEVILLA"));
else printf("Error, no se ha podido encontrar el registro.\n");

if(modificarReg("alumnos.hash","15838332","SEVILLA")>=0)
    printf("Se ha encontrado en el CUBO %d\n",modificarReg("alumnos.hash","15838332","SEVILLA"));
else printf("Error, no se ha podido encontrar el registro.\n");

if(modificarReg("alumnos.hash","7282323","SEVILLA")>=0)
    printf("Se ha encontrado en el CUBO %d\n",modificarReg("alumnos.hash","7282323","SEVILLA"));
else printf("Error, no se ha podido encontrar el registro.\n");


if(modificarReg("alumnos.hash","7219752","SEVILLA")>=0)
    printf("Se ha encontrado en el CUBO %d\n",modificarReg("alumnos.hash","7219752","SEVILLA"));
else printf("Error, no se ha podido encontrar el registro.\n");

if(modificarReg("alumnos.hash","9389298","SEVILLA")>=0)
    printf("Se ha encontrado en el CUBO %d\n",modificarReg("alumnos.hash","9389298","SEVILLA"));
else printf("Error, no se ha podido encontrar el registro.\n");

leeHash("alumnos.hash");
return 0;
}
