/*
 * Práctica 1
 * Héctor Padín Torrente, Luis Cascón Padrón
 * hector.padin@udc.es, luis.cascon@udc.es
 * Grupo: 1.4
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

#define MAX_N 64000


int sumaSubMax1(int v[], int n){
	int sumMax = 0;
	int estaSuma;

	for (int i = 0; i < n; ++i){
		estaSuma=0;
		for (int j=i; j<n; ++j){
			estaSuma+=v[j];
			if (estaSuma > sumMax) sumMax = estaSuma;
		}	
	}
	return sumMax;
}


int sumaSubMax2(int v[], int n){
	int estaSuma=0; 
	int sumaMax=0;

	for (int i = 0; i < n; ++i){
		estaSuma=estaSuma+v[i];
		if (estaSuma>sumaMax) 
			sumaMax= estaSuma;
		else if (estaSuma<0) estaSuma=0;
	}
	return sumaMax;
}


void inicializar_semilla() {
	
	srand(time(NULL));		
	/* se establece la semilla de una nueva serie de enteros pseudo-aleatorios */
}


void aleatorio(int v [], int n) {
	int i, m=2*n+1;
	
	for (i=0; i < n; i++)
		v[i] = (rand() % m) - n;
		/* se generan números pseudoaleatorio entre -n y +n */
}


void listar_vector(int v [], int n){
	
	printf("{ ");
	for (int i = 0; i < n; ++i){
		printf("%2i ", v[i]);
	}
	printf(" }");
}


double microsegundos() { 
	struct timeval t;

	if (gettimeofday(&t, NULL) < 0 )
		return 0.0;
	return (t.tv_usec + t.tv_sec * 1000000.0);
	/* obtiene la hora del sistema en microsegundos */
}


void test1(){
	int a, b;
	int v[6][5]={{-9, 2, -5, -4, 6}, {4, 0, 9, 2, 5 }, {-2, -1, -9, -7, -1},
			 	 {9, -2, 1, -7, -8}, {15, -2, -5, -4, 16 }, {7, -5, 6, 7, -7}};

	printf("Test 1:\n");
	printf("%33s%15s%15s\n", "", "sumaSubMax1", "sumaSubMax2");
	for (int i = 0; i < 6; ++i){
		listar_vector(v[i],5);
		a = sumaSubMax1(v[i],5);
		b = sumaSubMax2(v[i],5);
		printf("%27d%15d\n", a, b);
	}


}


void test2() {
	int i, a, b;
	int v[9];

	printf("\nTest 2:\n");
	printf("%33s%15s%15s\n", "", "sumaSubMax1", "sumaSubMax2");
	for (i=0; i<10; i++) {
		aleatorio(v, 9);
		listar_vector(v, 9);
		a = sumaSubMax1(v, 9);
		b = sumaSubMax2(v, 9);
		printf("%15d%15d\n", a, b);
	}
}


double time1(int n) {
	int v[n];
	double ta = 0, tb = 0, t1 = 0, t2 = 0, t;

	inicializar_semilla();
	aleatorio(v, n);
	ta = microsegundos();
	sumaSubMax1(v, n);
	tb = microsegundos();
	t = tb - ta;
	if (t < 500) {
		ta = microsegundos();
		for (int k = 0; k < 1000; k++) {
			aleatorio(v, n);
			sumaSubMax1(v, n);
		}
		tb = microsegundos();
		t1 = tb - ta;
		ta = microsegundos();
		for (int k = 0; k < 1000; k++) {
			aleatorio(v,n);
		}
		tb = microsegundos();
		t2 = tb - ta;
		t = (t1 - t2)/1000;
	}

	return t;
}


double time2(int n) {
	int v[n];
	double ta, tb, t1 = 0, t2 = 0, t;

	aleatorio(v, n);
	ta = microsegundos();
	sumaSubMax2(v, n);
	tb = microsegundos();
	t = tb - ta;
	if (t < 500) {
		ta = microsegundos();
		for (int k = 0; k < 1000; k++) {
			aleatorio(v, n);
			sumaSubMax2(v, n);
		}
		tb = microsegundos();
		t1 = tb - ta;
		ta = microsegundos();
		for (int k = 0; k < 1000; k++) {
			aleatorio(v,n);
		}
		tb = microsegundos();
		t2 = tb - ta;
		t = (t1 - t2)/1000;
	}

	return t;
}


void timeTable() {
	int n = 500;

	printf("\n\nSuma SubMax 1\n");
	printf("%8s%16s%16s%16s%16s\n",
		 "n","t(n)", "t(n)/n^(1,8)", "t(n)/n^(2)", "t(n)/n^(2,2)");
	do {
		if (time1(n) < 500) {
			printf("%s%7d%16.3f%16.6f%16.6f%16.6f\n", "*",
				n, time1(n), time1(n)/pow(n,1.8), time1(n)/pow(n,2), time1(n)/pow(n,2.2));
		} else {
			printf("%8d%16.3f%16.6f%16.6f%16.6f\n",
				n, time1(n), time1(n)/pow(n,1.8), time1(n)/pow(n,2), time1(n)/pow(n,2.2));
		}
		n += n;
	} while (n <= MAX_N);
	printf("%40s%16s%16s\n","subestimada", "ajustada", "sobrestimada");
	n = 500;
	printf("\n\nSuma SubMax 2\n");
	printf("%8s%16s%16s%16s%16s\n",
		 "n","t(n)", "t(n)/n^(0.7)", "t(n)/n^(0.9)", "t(n)/n^(1.1)");
	do {
		if (time2(n) < 500) {
			printf("%s%7d%16.3f%16.6f%16.6f%16.6f\n", "*",
				n, time2(n), time2(n)/pow(n,0.7), time2(n)/pow(n,0.9), time2(n)/pow(n,1.1));
		} else {
			printf("%8d%16.3f%16.6f%16.6f%16.6f\n",
				n, time2(n), time2(n)/pow(n,0.7), time2(n)/pow(n,0.9), time2(n)/pow(n,1.1));
		}

		n += n;
	} while (n <= MAX_N);
	printf("%40s%16s%16s\n","subestimada", "ajustada", "sobrestimada");
}


int main() {

	inicializar_semilla();
	test1();
	test2();
	timeTable();
	return 0;
}

