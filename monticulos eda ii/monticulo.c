#include <stdlib.h>
#include <stdio.h>
#include "monticulo.h"


void iniciaMonticulo(Monticulo *m){
/*asigna el valor de monticulo vacío a la variable de tipo
monticulo que se le pasa como parametro.*/
    m->tamanno=0;
}
int vacioMonticulo(Monticulo m){
    if(!m.tamanno)
        return 1;
    else return 0;

}
int insertar(tipoElemento x,Monticulo *m){
    if(m->tamanno>MAXIMO)
        return -1;
    m->tamanno++;
    m->elemento[m->tamanno]=x;
    filtradoAscendente(m,m->tamanno);
    return 0;
}
int eliminarMinimo(Monticulo *m,tipoElemento *minimo){
    if(m->tamanno>MAXIMO)
        return -1;
    *minimo=m->elemento[1];
    m->elemento[1]=m->elemento[m->tamanno];
    m->tamanno--;
    filtradoDescendente(m,1);
    return 0;

}
void decrementarClave(int pos,tipoClave cantidad,Monticulo *m){
    if(pos<1 || pos>m->tamanno)
        return;
    m->elemento[pos].clave=m->elemento[pos].clave-cantidad;
//al decrementar la clave, el elemento debe ascender
    filtradoAscendente(m,pos);

}
void incrementarClave(int pos, tipoClave cantidad, Monticulo *m){
    if(pos < 1 || pos>m->tamanno)
        return;
    m->elemento[pos].clave+=cantidad;
//al incrementar el tamaño, el elemento debe de ir hacia abajo
    filtradoDescendente(m,pos);
}
int esMonticulo(Monticulo m){
    int i;
    for(i=m.tamanno;i<=1;i--)
        if(m.elemento[i/2].clave>m.elemento[i].clave)
            return 0;
    return 1;
}
//operaciones auxiliares
void filtradoAscendente(Monticulo *m, int i){
    tipoElemento e=m->elemento[i];
    while(i>1 && e.clave<m->elemento[i/2].clave ){
        m->elemento[i]=m->elemento[i/2];
        i/=2;
    }
    m->elemento[i]=e;
}
void filtradoDescendente(Monticulo *m, int i){
  	int hijo, finFiltrado;
  	tipoElemento e = m->elemento[i];


  	finFiltrado = 0;
  	while(2*i <= m->tamanno && !finFiltrado){
  		hijo = 2*i;
  		if(hijo+1 <=m->tamanno && m->elemento[hijo+1].clave<m->elemento[hijo].clave)
  			hijo++;

  		if(e.clave > m->elemento[hijo].clave){
  			m->elemento[i] = m->elemento[hijo];
  			i = hijo;
  		}else
  			finFiltrado = 1;
  	}

  	m->elemento[i] = e;
  }
void crearMonticulo(Monticulo *m){
    int i;
    for(i=m->tamanno/2;i>=1;i--)
        filtradoDescendente(m,i);
}
 void heapsort(Monticulo *m){
  	int tam, i;
  	tipoElemento e;

  	tam = m->tamanno;

  	crearMonticulo(m);

  	for(i=1; i<=tam; i++){
  		if(eliminarMinimo(m, &e)) fprintf(stderr,"ERROR eliminarMinimo");
  		m->elemento[m->tamanno+1] = e;
  	}

  	m->tamanno = tam;
 }
