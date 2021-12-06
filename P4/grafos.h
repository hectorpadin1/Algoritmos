#ifndef _GRAF
#define _GRAF

/*
 * Práctica 4
 * Héctor Padín Torrente, Luis Cascón Padrón
 * hector.padin@udc.es, luis.cascon@udc.es
 * Grupo: 1.4
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

#define MAX_N 640
#define CONST_K 1000


/* definición del tipo matriz */
typedef int ** matriz;


/* PROTOTIPOS DE FUNCIONES */

/* crea una matriz */
matriz crearMatriz(int n);

/* inicializa la matriz con números aleatorios */
void iniMatriz(matriz m, int n);

/* inicializa la matriz llena por encima de la diagonal*/
void iniMatrizZ(matriz m, int n);

/* saca una matriz por pantalla */
void printMatriz(matriz m, int n);

/* libera la matriz */
void liberarMatriz(matriz m, int n);

/* Tabla de distancias minimas */
void dijkstra(matriz grafo, matriz distancias, int tam);

#endif