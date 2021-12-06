/*
 * Práctica 2
 * Héctor Padín Torrente, Luis Cascón Padrón
 * hector.padin@udc.es, luis.cascon@udc.es
 * Grupo: 1.4
 */

#include "time.h"


/* procedimiento para calentar la máquina */
void calentar(int n) {

	do {		// ejecuta los procedimientos más pesados para calentar la máquina lo antes posible
		time2(n);
		time5(n);
		n += n;
	} while (n <= MAX_N);
}


/* muestra por pantalla el tiempo de ejecución para un algoritmo ordenación por inserción para un vector ascendente */
void ins1(int n) {

	do {
		if (time1(n) < (double)500)			// si el tiempo es menor que 500 microsegundos saca por pantalla un '*'
			printf("*");
		else printf(" ");
			printf("%7d%16.3f%16.6f%16.6f%16.6f\n", n,
				time1(n), time1(n)/pow(n,0.8), time1(n)/pow(n,1.0), time1(n)/pow(n,1.2));	// saca una línea con los tiempos por cada iteración
		n += n;
	} while (n <= MAX_N);	
}


/* muestra por pantalla el tiempo de ejecución para un algoritmo ordenación por inserción para un vector descendente */
void ins2(int n) {
	
	do {
		if (time2(n) < (double)500)			// si el tiempo es menor que 500 microsegundos saca por pantalla un '*'
			printf("*");
		else printf(" ");
			printf("%7d%16.3f%16.6f%16.6f%16.6f\n", n,
				time2(n), time2(n)/pow(n,1.8), time2(n)/pow(n,2), time2(n)/pow(n,2.2));	// saca una línea con los tiempos por cada iteración
		n += n;
	} while (n <= MAX_N);
}


/* muestra por pantalla el tiempo de ejecución para un algoritmo ordenación por inserción para un vector aleatorio */
void ins3(int n) {

	do {
		if (time3(n) < (double)500)			// si el tiempo es menor que 500 microsegundos saca por pantalla un '*'
			printf("*");
		else printf(" ");
			printf("%7d%16.3f%16.6f%16.6f%16.6f\n", n,
				time3(n), time3(n)/pow(n,1.8), time3(n)/pow(n,2), time3(n)/pow(n,2.2));	// saca una línea con los tiempos por cada iteración
		n += n;
	} while (n <= MAX_N);
}


/* muestra por pantalla el tiempo de ejecución para un algoritmo ordenación por shell para un vector ascendente */
void shell1(int n) {
	
	do {
		if (time4(n) < (double)500)			// si el tiempo es menor que 500 microsegundos saca por pantalla un '*'
			printf("*");
		else printf(" ");
			printf("%7d%16.3f%16.6f%16.6f%16.6f\n", n,
				time4(n), time4(n)/n, time4(n)/pow(n,1.15), time4(n)/pow(n,1.3));		// saca una línea con los tiempos por cada iteración
		n += n;
	} while (n <= MAX_N);
}


/* muestra por pantalla el tiempo de ejecución para un algoritmo ordenación por shell para un vector descendente */
void shell2(int n) {
	
	do {
		if (time5(n) < (double)500)			// si el tiempo es menor que 500 microsegundos saca por pantalla un '*'
			printf("*");
		else printf(" ");
			printf("%7d%16.3f%16.6f%16.6f%16.6f\n", n,
				time5(n), time5(n)/n, time5(n)/pow(n,1.15), time5(n)/pow(n,1.3));		// saca una línea con los tiempos por cada iteración
		n += n;
	} while (n <= MAX_N);
}


/* muestra por pantalla el tiempo de ejecución para un algoritmo ordenación por inserción para un vector aleatorio */
void shell3(int n) {
	
	do {
		if (time6(n) < (double)500)			// si el tiempo es menor que 500 microsegundos saca por pantalla un '*'
			printf("*");
		else printf(" ");
			printf("%7d%16.3f%16.6f%16.6f%16.6f\n", n,
				time6(n), time6(n)/n, time6(n)/pow(n,1.15), time6(n)/pow(n,1.4));	// saca una línea con los tiempos por cada iteración
		n += n;
	} while (n <= MAX_N);	
}


void timeTable() {
	int n = 500;

	printf("Preparando máquina, por favor espere.\n");	// calentamos la máquina
	calentar(n);
	printf("\nTabla de tiempos:");				// sacamos por pantalla todas las tablas
	printf("\nOrdenacion por insercion con inicializacion ascendente\n");
	printf("%8s%16s%16s%16s%16s\n",
		 "n","t(n)", "t(n)/n^(0,8)", "t(n)/n", "t(n)/n^(1,2)");
	ins1(n);
	printf("\n\nOrdenacion por insercion con inicializacion descendente\n");
	printf("%8s%16s%16s%16s%16s\n",
		 "n","t(n)", "t(n)/n^(1,8)", "t(n)/n^(2)", "t(n)/n^(2,2)");
	ins2(n);
	printf("\n\nOrdenacion por insercion con inicializacion aleatoria\n");
	printf("%8s%16s%16s%16s%16s\n",
		 "n","t(n)", "t(n)/n^(1,8)", "t(n)/n^(2)", "t(n)/n^(2,2)");
	ins3(n);
	printf("\n\nOrdenacion por shell con inicializacion ascendente\n");
	printf("%8s%16s%16s%16s%16s\n",
		 "n","t(n)", "t(n)/n", "t(n)/n^(1,15)", "t(n)/n^(1,3)");
	shell1(n);
	printf("\n\nOrdenacion por shell con inicializacion descendente\n");
	printf("%8s%16s%16s%16s%16s\n",
		 "n","t(n)", "t(n)/n", "t(n)/n^(1,15)", "t(n)/n^(1,3)");
	shell2(n);
	printf("\n\nOrdenacion por shell con inicializacion aleatoria\n");
	printf("%8s%16s%16s%16s%16s\n",
		 "n","t(n)", "t(n)/n", "t(n)/n^(1,2)", "t(n)/n^(1,4)");
	shell3(n);
}