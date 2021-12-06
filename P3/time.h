#ifndef _TIME
#define _TIME

/*
 * Práctica 2
 * Héctor Padín Torrente, Luis Cascón Padrón
 * hector.padin@udc.es, luis.cascon@udc.es
 * Grupo: 1.4
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

#include "func.h"

#define MAX_N 64000
#define CONST_K 10000
#define AS 1
#define DES 2
#define AL 3


/* PROTOTIPOS DE FUNCIONES */

/* Devuelve el tiempo que tarda en crearse el monticulo */
double time_creat(int n, void (*inicializacion)(int[], int));

/* Devuelve el tiempo que tarda en ordenar un monticulo */
double time_ord(int n, void (*inicializacion)(int[], int));

/* Procedimiento que muestra las tablas de tiempos */
void timeTable();


#endif