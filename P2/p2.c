/*
 * Práctica 2
 * Héctor Padín Torrente,L uis Cascón Padrón
 * hector.padin@udc.es, luis.cascon@udc.es
 * Grupo: 1.4
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

#include "time.h"
#include "func.h"


/* test para ordenación por inserción */
void test_ins() {
	int v[17];

	printf("Ordenacion por insercion:\n");
	printf("Inicializacion aleatoria\n");
	aleatorio(v, 17);		// genera un vector aleatorio
	listar_vector(v, 17);	// saca el vector por pantalla
	printf("ordenado? %d\n", ordenado(v, 17));
	printf("Ordenacion por Insercion\n");
	ord_ins(v, 17);			// ordena el vector
	listar_vector(v, 17);	// saca el vector por pantalla
	printf("ordenado? %d\n", ordenado(v, 17));
	printf("Inicializacion ascendente\n");
	ascendente(v, 10);		// genera un vector ascedente
	listar_vector(v, 10);	// saca el vector por pantalla
	printf("ordenado? %d\n", ordenado(v, 10));
	printf("Ordenacion por Insercion\n");
	ord_ins(v, 10);			// ordena el vector
	listar_vector(v, 10);	// saca el vector por pantalla
	printf("ordenado? %d\n", ordenado(v, 10));
	printf("Inicializacion descendiente\n");
	descendente(v, 10);		// genera un vector descente
	listar_vector(v, 10);	// saca el vector por pantalla
	printf("ordenado? %d\n", ordenado(v, 10));
	printf("Ordenacion por Insercion\n");
	ord_ins(v, 10);			// ordena el vector
	listar_vector(v, 10);	// saca el vector por pantalla
	printf("ordenado? %d\n\n", ordenado(v, 10));
}


/* test para ordenación shell */
void test_shell() {
	int v[17];

	printf("Ordenacion Shell:\n");
	printf("Inicializacion aleatoria\n");
	aleatorio(v, 17);		// genera un vector aleatorio
	listar_vector(v, 17);	// saca el vector por pantalla
	printf("ordenado? %d\n", ordenado(v, 17));
	printf("Ordenacion Shell\n");
	ord_shell(v, 17);		// ordena el vector
	listar_vector(v, 17);	// saca el vector por pantalla
	printf("ordenado? %d\n", ordenado(v, 17));
	printf("Inicializacion ascendente\n");
	ascendente(v, 10);		// genera un vector ascendente
	listar_vector(v, 10);	// saca el vector por pantalla
	printf("ordenado? %d\n", ordenado(v, 10));
	printf("Ordenacion Shell\n");
	ord_shell(v, 10);		// ordena el vector
	listar_vector(v, 10);	// saca el vector por pantalla
	printf("ordenado? %d\n", ordenado(v, 10));
	printf("Inicializacion descendiente\n");
	descendente(v, 10);		// genera un vector descendente
	listar_vector(v, 10);	// saca el vector por pantalla
	printf("ordenado? %d\n", ordenado(v, 10));
	printf("Ordenacion Shell\n");
	ord_shell(v, 10);		// ordena el vector
	listar_vector(v, 10);	// saca el vector por pantalla
	printf("ordenado? %d\n\n", ordenado(v, 10));
}


int main(int argc, char const *argv[]) {
	
	inicializar_semilla();
	test_ins();
	test_shell();
	timeTable();
	return 0;
}