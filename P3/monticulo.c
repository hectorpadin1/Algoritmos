/*
 * Práctica 3
 * Héctor Padín Torrente, Luis Cascón Padrón
 * hector.padin@udc.es, luis.cascon@udc.es
 * Grupo: 1.4
 */

#include "monticulo.h"


int monticulo_vacio(tMonticulo *m) {

	return (m->ultimo == -1);
}


void hundir(tMonticulo * m, int i) {
	int j, HIzq, HDch, tmp;
	if (m) {
		do {
			HIzq = 2*(i+1)-1;
			HDch = 2*(i+1);
			j = i;
			if ((HDch <= m->ultimo) && (m->vector[HDch] < m->vector[i]))
				i = HDch;
			if ((HIzq <= m->ultimo) && (m->vector[HIzq] < m->vector[i]))
				i = HIzq;
			tmp = m->vector[j];
			m->vector[j] = m->vector[i];
			m->vector[i] = tmp;
		} while (i != j);
	}
}


void inicializarMonticulo(tMonticulo *m) {
	m->ultimo = -1;
}


void crearMonticulo(int v[], int n, tMonticulo *m) {
	int i = 0, x;
	for (i = 0; i < n; i++) {
		m->vector[i] = v[i];
	}
	m->ultimo = n-1;
	x = (int)(m->ultimo-1)/2;
	for (i = x; i > -1; i--) {
		hundir(m,i);
	}
} 


void listar_monticulo(tMonticulo *m, int n) {
	int i, y = 0;
	for (i = 0; i < n; i++) {
		if (y == i) {		
			printf(" %d\n", m->vector[i]);	
			y = 2*(i+1);
		} else {
			printf(" %d", m->vector[i]);
		}
	}
	printf("\n");
}


int consultarMenor(tMonticulo *m) {

	if (!monticulo_vacio(m)) {
		return m->vector[0];
	} else {
		printf("monticulo vacío.\n");
		return 0;
	}
}


void quitarMenor(tMonticulo *m) {

	if (!monticulo_vacio(m)) {
		m->vector[0] = m->vector[m->ultimo];
		m->ultimo--;
		if (m->ultimo > 0) 
			hundir(m,0);
	} else
		printf("monticulo vacío.\n");
}


void ordenacion_por_monticulos(int v[], int n) {
	tMonticulo m;
	int i;

	crearMonticulo(v,n,&m);
	for (i = 0; i < n; i++) {
		v[i] = consultarMenor(&m);
		quitarMenor(&m);
	}
}