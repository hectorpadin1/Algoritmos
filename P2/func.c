/*
 * Práctica 2
 * Héctor Padín Torrente, Luis Cascón Padrón
 * hector.padin@udc.es, luis.cascon@udc.es
 * Grupo: 1.4
 */


#include "func.h"


void ord_ins(int v[], int n) {
	int i, j, x;

	for (i = 1; i < n; i++) {
		x = v[i];
		j = i - 1;
		while ((j >= 0) && (v[j] > x)) {
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1]=x;
	}
}


void ord_shell(int v[], int n) {
	int i, j, incremento, tmp, seguir;

	incremento = n;
	do {
		incremento = incremento/2;
		for (i = incremento; i < n; i++) {
			tmp = v[i];
			j = i;
			seguir = 1;
			while (((j - incremento) >= 0) && (seguir == 1)) {
				if (tmp < v[j - incremento]) {
					v[j] = v[j - incremento];
					j = j - incremento;
				} else seguir = 0;
			} 
		v[j] = tmp;
		}
	} while (incremento != 0);
}


void inicializar_semilla() {
	
	srand(time(NULL));
}


void aleatorio(int v [], int n) {
	int i, m = 2 * n + 1;

	for (i = 0; i < n; i++)
		v[i] = (rand() % m) - n;
}


void ascendente(int v [], int n) {
	int i;

	for (i=0; i < n; i++)
		v[i] = i;
}


void descendente(int v [], int n) {
	int i;

	for (i = 0; i < n; i++)
		v[i] = n - i;
}


int ordenado(int v[], int n) {
	int i = 1, seguir = 1;

	do {
		if (v[i-1] > v[i]) {
			seguir = 0;
		}
		i++;
	} while ((i < n) && (seguir == 1));
	return seguir;
}


void listar_vector(int v[], int n) {
	int i;

	for (i = 0; i < n; i++){
		printf("%d", v[i]);
		if ((i+1) != n)
			printf(", ");
	}
	printf("\n");
}


double microsegundos() { 
	struct timeval t;

	if (gettimeofday(&t, NULL) < 0 )
		return 0.0;
	return (t.tv_usec + t.tv_sec * 1000000.0);
	/* obtiene la hora del sistema en microsegundos */
}