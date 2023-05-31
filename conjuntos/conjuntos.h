#ifndef __CONJUNTOS_A_H
#define __CONJUNTOS_A_H

#define MAXIMO 16

typedef int particion[MAXIMO];
typedef int tipoConjunto;
typedef int tipoElemento;

// Funciones a implementar

void crea(particion P);
tipoConjunto buscar(tipoElemento x, particion P);
void unir(tipoConjunto x, tipoConjunto y, particion P);

// Función proporcionada
void verParticion(particion P);
#endif

