#ifndef __FUNCIONES_H
#define __FUNCIONES_H
#define REG 5
#define CUBOS 20
#define DESBORDE  4
#define h(x) x%CUBOS
#include <stdio.h>
//declaracion de la estructura abb
typedef char tipoClave[20];
typedef int tipoInfo;
typedef struct tipoNodo{
    tipoClave clave;
    tipoInfo info;
    struct tipoNodo *izq,*der;

}tipoNodo;

typedef tipoNodo *tipoArbolBB;
typedef struct {
char dni[9];
char nombre[19];
char ape1[19];
char ape2[19];
char provincia[11];

}tipoAlumno;

typedef struct{
    tipoAlumno registro[REG];
    int numRegAsignados;
}tipoCubo;

tipoNodo *creaNodo(tipoClave clave, tipoInfo info);
int insertar(tipoArbolBB *raiz,tipoClave clave);
int genABB(char *ficheroDatos,tipoArbolBB *arbol);
void recorreArbol(tipoArbolBB raiz);
int recorreArbolpreOrden(tipoArbolBB raiz);
void creaVacio(char *fichHash);
int creaHash(char *,char *);
int modificarReg(char *fichero,char *dni,char *provincia);
int leeHash(char *fichHash);






#endif
