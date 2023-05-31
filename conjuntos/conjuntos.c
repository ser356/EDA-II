#include "conjuntos.h"
#include <stdio.h>


/// Incluir aqui las funciones que implementan las tres operaciones básicas
/// en la representación de CONJUNTOS DISJUNTOS mediante ÁRBOLES
/// ......................................................................

void crea(particion P){
int i;
for(i=0;i<MAXIMO;i++)
    P[i]=-1;
}
tipoConjunto buscar(tipoElemento x, particion P){
if(P[x]<0)
    return x;
else{
    P[x]=buscar(P[x],P);
    return P[x];

}


}
void unir(tipoConjunto x,tipoConjunto y,particion P){
x = buscar(x,P);
y = buscar(y,P);
if(P[x] <= P[y]){
		P[x] += P[y];
		P[y] = x;
	}else{
		P[y] += P[x];
		P[x] = y;
	}


}



//
// Función auxiliar para ver contenido de Partición
//
void verParticion(particion P)
{ int i;
    printf("\n");
    for (i =0;i<MAXIMO;i++) printf("|%2d",P[i]);
    printf("| contenido  vector\n");
    for (i =0;i<MAXIMO;i++) printf("---");
    printf("\n");
    for (i =0;i<MAXIMO;i++) printf(" %2d",i);
    printf("  índices vector\n\n");
}
