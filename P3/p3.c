/*
 * Práctica 3
 * Héctor Padín Torrente,L uis Cascón Padrón
 * hector.padin@udc.es, luis.cascon@udc.es
 * Grupo: 1.4
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

#include "func.h"
#include "monticulo.h"
#include "time.h"


/* test para la ordenación de montículos */
void testCrearMonticulo() {
	int v[15];
	
	tMonticulo m;

	printf("Test de la creación de montículos.\n");
	inicializarMonticulo(&m);
	printf("\nTest Para montículo 1(ascendiente):\n");
	printf("*************************************************\n");
	ascendente(v,15);
	crearMonticulo(v,15,&m);
	listar_monticulo(&m,15);
	printf("\nTest Para montículo 2(descendente):\n");
	printf("*************************************************\n");
	descendente(v,15);
	crearMonticulo(v,15,&m);
	listar_monticulo(&m,15);
	printf("\nTest Para montículo 3(aleatorio):\n");
	printf("*************************************************\n");
	aleatorio(v,15);
	listar_vector(v,15);
	crearMonticulo(v,15,&m);
	listar_monticulo(&m,15);
	printf("\n");
}

/* test para la ordenación de vectores mediante montículos */
void testMonticulo() {
	int v[15];

	printf("Test ordenacion por montículos:\n");
	printf("\nInicializacion aleatoria:\n");
	aleatorio(v, 15);							// genera un vector aleatorio
	listar_vector(v, 15);						// saca el vector por pantalla
	printf("ordenado? %d\n", ordenado(v, 15));
	printf("Creamos el montículo\n");
	ordenacion_por_monticulos(v, 15);			// ordena el vector
	listar_vector(v, 15);						// saca el vector por pantalla
	printf("ordenado? %d\n\n", ordenado(v, 15));
	printf("Inicializacion ascendente\n");
	ascendente(v, 15);							// genera un vector ascedente
	listar_vector(v, 15);						// saca el vector por pantalla
	printf("ordenado? %d\n", ordenado(v, 15));
	printf("Creamos el montículo\n");
	ordenacion_por_monticulos(v, 15);			// ordena el vector
	listar_vector(v, 15);						// saca el vector por pantalla
	printf("ordenado? %d\n\n", ordenado(v, 15));
	printf("Inicializacion descendiente\n");
	descendente(v, 15);							// genera un vector descente
	listar_vector(v, 15);						// saca el vector por pantalla
	printf("ordenado? %d\n", ordenado(v, 15));
	printf("Creamos el montículo\n");
	ordenacion_por_monticulos(v, 15);			// ordena el vector
	listar_vector(v, 15);						// saca el vector por pantalla
	printf("ordenado? %d\n\n\n", ordenado(v, 15));
}


int main(int argc, char const *argv[]) {	

	inicializar_semilla();
	testCrearMonticulo();
	testMonticulo();
	timeTable();
	return 0;
}