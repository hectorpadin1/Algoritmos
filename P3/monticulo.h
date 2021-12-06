#ifndef _MONT
#define _MONT

/*
 * Práctica 3
 * Héctor Padín Torrente, Luis Cascón Padrón
 * hector.padin@udc.es, luis.cascon@udc.es
 * Grupo: 1.4
 */

#include <stdio.h>

#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

#define TAM 256000


typedef struct monticulo {
	int vector[TAM];
	int ultimo;
} tMonticulo;


/* comprueba si un montículo esta vacío */
int monticulo_vacio(tMonticulo *m);

/* inicializa el montículo */
void inicializarMonticulo(tMonticulo *m);

/* Crea un montículo de mínimos a partir de un vector */
void crearMonticulo(int v[], int n, tMonticulo *m);

/* lista un montículo */
void listar_monticulo(tMonticulo *m, int n);

/* Devuelve el valor más pequeño del montículo */
int consultarMenor(tMonticulo *m);

/* Elimina el elemento menor */
void quitarMenor(tMonticulo *m);

/* ordena el vector v */
void ordenacion_por_monticulos(int v[], int n);

#endif