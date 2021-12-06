#ifndef _FUNC
#define _FUNC

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

#define MAX_N 64000
#define CONST_K 10000


/* PROTOTIPOS DE FUNCIONES */

/* ordena un vector mediante inserción */
void ord_ins(int v[], int n);

/* ordena un vector mediante ordenación shell */
void ord_shell(int v[], int n);

/* inicialización de la semilla */
void inicializar_semilla();

/* creación de un vector aleatorio */
void aleatorio(int v [], int n);

/* creación de un vector ascendente */
void ascendente(int v [], int n);

/* creación de un vector descendente */
void descendente(int v [], int n);

/* función que comprueba si un vector está ordenado */
int ordenado(int v [], int n);

/* lista un vector */
void listar_vector(int v [], int n);

/* devuelve el tiempo en microsegundos */
double microsegundos();



#endif