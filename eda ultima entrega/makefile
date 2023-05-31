
prueba1: prueba1.c funciones.h funciones.o
	gcc -g prueba1.c funciones.o -o prueba1
prueba2: prueba2.c funciones.h funciones.o
	gcc -g prueba2.c funciones.o -o prueba2

funciones.o: funciones.c funciones.h
	gcc -g -c funciones.c 

clean: 
	rm *.o