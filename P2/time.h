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


/* PROTOTIPOS DE FUNCIONES */

/* tiempo de ejecución de un algoritmo ordenación por inserción para un vector ascendente */
double time1(int n);

/* tiempo de ejecución de un algoritmo ordenación por inserción para un vector descendente */
double time2(int n);

/* tiempo de ejecución de un algoritmo ordenación por inserción para un vector aleatorio */
double time3(int n);

/* tiempo de ejecución de un algoritmo ordenación por shell para un vector ascendente */
double time4(int n);

/* tiempo de ejecución de un algoritmo ordenación por shell para un vector descendente */
double time5(int n);

/* tiempo de ejecución de un algoritmo ordenación por shell para un vector aleatorio */
double time6(int n);

/* procedimiento que muestra las tablas de tiempos */
void timeTable();


#endif