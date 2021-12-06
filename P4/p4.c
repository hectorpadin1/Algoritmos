/*
 * Práctica 4
 * Héctor Padín Torrente,Luis Cascón Padrón
 * hector.padin@udc.es, luis.cascon@udc.es
 * Grupo: 1.4
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

#include "grafos.h"
#include "time.h"


/* aqui se testean los resultados de la figura uno y dos */
void testMatriz() {
	matriz m1,m2,d1,d2;
	int n = 4, m= 5;

	m1 = crearMatriz(m);
	m2 = crearMatriz(n);
	d1 = crearMatriz(m);
	d2 = crearMatriz(n);

	m1[0][1]=1;	m1[0][2]=8;	m1[0][3]=4;m1[0][4]=7;
	m1[1][2]=2; m1[1][3]=6; m1[1][4]=5;
	m1[2][3]=9; m1[2][4]=5;
	m1[3][4]=3;

	m2[0][1]=1;	m2[0][2]=4;	m2[0][3]=7;
	m2[1][2]=2; m2[1][3]=8; 
	m2[2][3]=3; 
	
	iniMatrizZ(m1,m);
	printf("Matriz de adyacencia para m1:\n\n");
	printMatriz(m1,m);
	printf("Matriz de distancias minimas para m1:\n\n");
	dijkstra(m1,d1,m);			printMatriz(d1,m);
	liberarMatriz(m1,m);		liberarMatriz(d1,m);
	
	iniMatrizZ(m2,n);
	printf("Matriz de adyacencia para m2:\n\n");
	printMatriz(m2,n);
	printf("Matriz de distancias minimas para m2:\n\n");
	dijkstra(m2,d2,n); 			printMatriz(d2,n);
	liberarMatriz(m2,m); 		liberarMatriz(d2,m);
}


int main(int argc, char const *argv[]) {	

	inicializar_semilla();
	testMatriz();
	timeTable();
	return 0;
}