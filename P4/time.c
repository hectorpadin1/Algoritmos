/*
 * Práctica 4
 * Héctor Padín Torrente,Luis Cascón Padrón
 * hector.padin@udc.es, luis.cascon@udc.es
 * Grupo: 1.4
 */

#include "time.h"

void inicializar_semilla() {
	
	srand(time(NULL));
}


double microsegundos() { 
	struct timeval t;

	if (gettimeofday(&t, NULL) < 0 )
		return 0.0;
	return (t.tv_usec + t.tv_sec * 1000000.0);
	/* obtiene la hora del sistema en microsegundos */
}


void calentar(int n) {
	matriz m, d;
	int count=0;
	
	m=crearMatriz(n);
	iniMatriz(m,n);
	d=crearMatriz(n);

	do {
		dijkstra(m,d,n);
		count++;
	} while (count<MAX_N);
	
	liberarMatriz(m,n);
	liberarMatriz(d,n); 
}


double time_Dijkstra(int n) {
	matriz m,d;
	double ta = 0, tb = 0, t1 = 0, t2 = 0, t;
	int k;
	
	m = crearMatriz(n);						// crea una matriz de adyacencia del grafo
	d = crearMatriz(n);						// crea una matriz de distancias
	iniMatriz(m,n);							// inicializa una matriz
	ta = microsegundos();					// primera medición
	dijkstra(m,d,n);						// cáclulo de distancias mínimas
	tb = microsegundos();					// segunda medición
	t = tb - ta;							// tiempo entre mediciones
	if (t < 500) {							// si el tiempo es menor a 500 microsegundos el margen de error es demasiado grande
		ta = microsegundos();				// primera medicion
		for (k = 0; k < CONST_K; k++) {			// hacemos k veces la inicialización de la matriz y el cálculo
			iniMatriz(m,n);
			dijkstra(m,d,n);
		}
		tb = microsegundos();			// segunda medición
		t1 = tb - ta;					// tiempo entre mediciones
		ta = microsegundos();			// primera medición
		for (k = 0; k < CONST_K; k++) 	// inicializa k veces la matriz
			iniMatriz(m,n);

		tb = microsegundos();			// segunda medición
		t2 = tb - ta;					// tiempo entre mediciones
		t = (t1 - t2)/CONST_K;			// tiempo medio de ejecución
	}
	liberarMatriz(m,n);				// liberamos la matriz de adyacencia del grafo
	liberarMatriz(d,n);				// liberamos la matriz de distancias
	return t;					// devolvemos el resultado
}


void printTimeDijkstra(int n) {
	double d;

	do {
		d = time_Dijkstra(n);		
		if (d < 500) {
			printf("*");
		} else printf(" ");
		printf("%7d%16.3f%16.6f%16.6f%16.6f\n",
			n, d, d/pow(n,2.6), d/pow(n,2.8), d/pow(n,3));
		n = n*2 ;
	} while (n <= MAX_N);	
}


void timeTable() {
	int n = 10;

	printf("\nPor favor espere, estamos calentando la maquina...\n\n");
	calentar(n);
	printf("Cálculo de las distancias mínimas para un grafo aleatorio\n");
	printf("%8s%16s%16s%16s%16s\n",
		 "n","t(n)", "t(n^2,6)", "t(n^2,8)", "t(n^3)");
	printTimeDijkstra(n);
	printf("\n\n");
}