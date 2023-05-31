#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"
#include <string.h>

int numApellidosnoRep=0;

tipoNodo *creaNodo(tipoClave clave, tipoInfo info)
{
    tipoNodo *nuevo;
    if((nuevo=malloc(sizeof(tipoNodo)))==NULL)
        return NULL;
    else{
        nuevo->info = info;
        strcpy(nuevo->clave,clave);

        nuevo->izq=NULL;
        nuevo->der=NULL;
        return nuevo;
    }
}

int insertar(tipoArbolBB *raiz,tipoClave clave){
//NO SE PERMITEN CLAVES DUPLICADAS, SOLO SE INSERTAN APELLIDOS NUEVOS, EN CASO CONTRARIO,
//EL CAMPO INFO INCREMENTA EN UNA UNIDAD.



    if(NULL == (*raiz)){
        *raiz = creaNodo(clave,1);
        return 0;
    }

    else if(!strcmp(clave,(*raiz)->clave)){
        (*raiz)->info += 1;
        return 0;
    }
    else if(0 > strcmp(clave,(*raiz)->clave)){
        return insertar(&(*raiz)->izq,clave);
    }
    else{
        return insertar(&(*raiz)->der,clave);
    }}


int genABB(char *ficheroDatos,tipoArbolBB *arbol){

    tipoArbolBB *arbolito=NULL;
    arbolito=arbol;
    FILE *archivo;
    tipoAlumno Alumno;
    if(NULL==(archivo=fopen(ficheroDatos,"rb")))
        return -1;
    else{

        fread(&Alumno,sizeof(tipoAlumno),1,archivo);
        while(!feof(archivo)){
            insertar(arbolito,Alumno.ape1);
            insertar(arbolito,Alumno.ape2);
            fread(&Alumno,sizeof(tipoAlumno),1,archivo);
        }
    puts("Arbol generado correctamente....");

    fclose(archivo);
    }

    return recorreArbolpreOrden(*arbolito);
}
//recorrido del arbol binario para ejercicio 1
int recorreArbolpreOrden(tipoArbolBB raiz){

    if(raiz){

            numApellidosnoRep++;
        recorreArbolpreOrden(raiz->izq);
        recorreArbolpreOrden(raiz->der);
    }
    return numApellidosnoRep;
}

void recorreArbol(tipoArbolBB raiz){

    if(raiz){
        if(raiz->info>1)
            printf("%s aparece %d veces\n",raiz->clave,raiz->info);
        recorreArbol(raiz->izq);
        recorreArbol(raiz->der);
    }
}

void creaVacio(char *fichHash){
  FILE *hash;
  tipoCubo c;
  int j;
  int numCubos =CUBOS+DESBORDE;

  memset(&c,0,sizeof(c));

  hash = fopen(fichHash,"wb");
  for (j=0;j<numCubos;j++)
    fwrite(&c,sizeof(c),1,hash);
  fclose(hash);
}

int creaHash(char *archivoi,char *archivoo){

    FILE *archivo_i,*archivo_o;
    int numDes=0;
    int i;
    tipoCubo c;
    tipoAlumno a;

    creaVacio(archivoo);

    if(NULL==(archivo_i=fopen(archivoi,"rb"))){
        return -1;

    }

    if(NULL==(archivo_o=fopen(archivoo,"r+b"))){
        fclose(archivo_i);
        return -1;
    }

    while(0 < fread(&a,sizeof(a),1,archivo_i)){
        fseek(archivo_o,(h(atoi(a.dni))*sizeof(c)),SEEK_SET);
        fread(&c,sizeof(c),1,archivo_o);

        if(c.numRegAsignados<REG){
            c.registro[c.numRegAsignados]=a;
        }
        c.numRegAsignados=c.numRegAsignados+1;
        fseek(archivo_o,-sizeof(c),SEEK_CUR);
        fwrite(&c,1,sizeof(c),archivo_o);

        if(c.numRegAsignados>REG){
            fseek(archivo_o,CUBOS*sizeof(c),SEEK_SET);
            i=0;
            while(i<DESBORDE && c.numRegAsignados>=REG){
                i++;
                fread(&c,sizeof(c),1,archivo_o);
            }
            c.registro[c.numRegAsignados]=a;
            c.numRegAsignados=c.numRegAsignados+1;
            fseek(archivo_o,-sizeof(c),SEEK_CUR);
            fwrite(&c,1,sizeof(c),archivo_o);

            numDes++;

        }
    }
    fclose(archivo_i);
    fclose(archivo_o);


return numDes;

}

int modificarReg(char *fichero,char *dni,char *provincia){

    FILE *archivo;
    tipoCubo c;
    int i;
    int cubos;
    if(NULL==(archivo=fopen(fichero,"r+b")))
        return -1;
// ubicamos el cubo correspondiente al registro buscado en el fichero hash
    fseek(archivo,(h(atoi(dni))*sizeof(c)),SEEK_SET);
    fread(&c,sizeof(c),1,archivo); // lee el bloque apuntado por fseek;

//recorre el cubo en busca del registro
    for(i=0;i<c.numRegAsignados && i<REG;i++){
        if(!strcmp(c.registro[i].dni,dni)){
            sprintf(c.registro[i].provincia,"%s",provincia);
            fseek(archivo,(h(atoi(dni))*sizeof(c)),SEEK_SET);
            fwrite(&c,1,sizeof(c),archivo);
            fseek(archivo,(h(atoi(dni))*sizeof(c)),SEEK_SET);
            return h(atoi(dni));
        }
    }

    if(c.numRegAsignados <REG || c.numRegAsignados == 0)
        return -1;

//nos ubicamos en la posición de inicio de los cubos de desborde (cubo 20)...
    fseek(archivo,CUBOS*sizeof(c),SEEK_SET);

    fread(&c,sizeof(c),1,archivo);

    for(cubos=20; cubos<=CUBOS+DESBORDE; cubos++){
        fseek(archivo, cubos*sizeof(c), SEEK_SET);

        fread(&c, sizeof(c), 1, archivo);
    //leemos el bloque y recorremos el cubo en busca del registro.
        for(i=0; i< REG; i++){
            if(i<c.numRegAsignados && !(strcmp(c.registro[i].dni, dni))){
                fseek(archivo,cubos*sizeof(c),SEEK_SET);
                sprintf(c.registro[i].provincia,"%s",provincia);
                fwrite(&c, sizeof(c), 1, archivo);
                fclose(archivo);
                return cubos; // al estar anidado en el bucle, devuelve el cubo de desborde en el que se encuentra el registro.
            }
        }
    }

return -1;


}

int leeHash(char *fichHash){
  FILE *f;
  tipoCubo cubo;
  int j,i=0;
  //size_t numLee;

   f = fopen(fichHash,"rb");
   rewind(f);
   fread(&cubo,sizeof(cubo),1,f);
   while (!feof(f)){
	for (j=0;j<REG;j++) {
        if (j==0)    	printf("Cubo %2d (%2d reg. ASIGNADOS)",i,cubo.numRegAsignados);
        else  	printf("\t\t\t");
	if (j < cubo.numRegAsignados)
		    printf("\t%s %s %s %s %s\n",
	    		cubo.registro[j].dni,
			cubo.registro[j].nombre,
			cubo.registro[j].ape1,
		  	cubo.registro[j].ape2,
  	                cubo.registro[j].provincia);
	else printf ("\n");
        }
       i++;
       fread(&cubo,sizeof(cubo),1,f);
   }
   fclose(f);
   return i;
}




