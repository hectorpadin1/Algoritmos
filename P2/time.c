/*
 * Práctica 2
 * Héctor Padín Torrente, Luis Cascón Padrón
 * hector.padin@udc.es, luis.cascon@udc.es
 * Grupo: 1.4
 */

#include "time.h"


double time1(int n) {
	int v[n];
	double ta = 0, tb = 0, t1 = 0, t2 = 0, t;
	int k;

	ascendente(v, n);					// genera un vector ascendente
	ta = microsegundos();				// primera medición
	ord_ins(v, n);						// ordenación del vector
	tb = microsegundos();				// segunda medición
	t = tb - ta;						// tiempo entre mediciones
	if (t < 500) {						// si el tiempo es menor a 500 microsegundos el margen de error es demasiado grande
		ta = microsegundos();			// primera medicion
		for (k = 0; k < CONST_K; k++) {		// hacemos k veces la inicialización del vector y la ordenación
			ascendente(v, n);
			ord_ins(v, n);
		}
		tb = microsegundos();			// segunda medición
		t1 = tb - ta;					// tiempo entre mediciones
		ta = microsegundos();			// primera medición
		for (k = 0; k < CONST_K; k++) {		// inicializa k veces el vector
			ascendente(v,n);
		}
		tb = microsegundos();			// segunda medición
		t2 = tb - ta;					// tiempo entre mediciones
		t = (t1 - t2)/CONST_K;			// tiempo medio de ejecución
	}

	return t;					// devolvemos el resultado
}


double time2(int n) {
	int v[n];
	double ta = 0, tb = 0, t1 = 0, t2 = 0, t;
	int k;

	descendente(v, n);					// genera un vector ascendente
	ta = microsegundos();				// primera medición
	ord_ins(v, n);						// ordenación del vector
	tb = microsegundos();				// segunda medición
	t = tb - ta;						// tiempo entre mediciones
	if (t < 500) {						// si el tiempo es menor a 500 microsegundos el margen de error es demasiado grande
		ta = microsegundos();			// primera medicion
		for (k = 0; k < CONST_K; k++) {		// hacemos k veces la inicialización del vector y la ordenación
			descendente(v, n);
			ord_ins(v, n);
		}
		tb = microsegundos();			// segunda medición
		t1 = tb - ta;					// tiempo entre mediciones
		ta = microsegundos();			// primera medición
		for (k = 0; k < CONST_K; k++) {		// inicializa k veces el vector
			descendente(v,n);
		}
		tb = microsegundos();			// segunda medición
		t2 = tb - ta;					// tiempo entre mediciones
		t = (t1 - t2)/CONST_K;			// tiempo medio de ejecución
	}

	return t;					// devolvemos el resultado
}


double time3(int n) {
	int v[n];
	double ta = 0, tb = 0, t1 = 0, t2 = 0, t;
	int k;

	aleatorio(v, n);					// genera un vector ascendente
	ta = microsegundos();				// primera medición
	ord_ins(v, n);						// ordenación del vector
	tb = microsegundos();				// segunda medición
	t = tb - ta;						// tiempo entre mediciones
	if (t < 500) {						// si el tiempo es menor a 500 microsegundos el margen de error es demasiado grande
		ta = microsegundos();			// primera medicion
		for (k = 0; k < CONST_K; k++) {		// hacemos k veces la inicialización del vector y la ordenación
			aleatorio(v, n);
			ord_ins(v, n);
		}
		tb = microsegundos();			// segunda medición
		t1 = tb - ta;					// tiempo entre mediciones
		ta = microsegundos();			// primera medición
		for (k = 0; k < CONST_K; k++) {		// inicializa k veces el vector
			aleatorio(v,n);
		}
		tb = microsegundos();			// segunda medición
		t2 = tb - ta;					// tiempo entre mediciones
		t = (t1 - t2)/CONST_K;			// tiempo medio de ejecución
	}

	return t;					// devolvemos el resultado
}


double time4(int n) {
	int v[n];
	double ta = 0, tb = 0, t1 = 0, t2 = 0, t;
	int k;

	ascendente(v, n);					// genera un vector ascendente
	ta = microsegundos();				// primera medición
	ord_shell(v, n);					// ordenación del vector
	tb = microsegundos();				// segunda medición
	t = tb - ta;						// tiempo entre mediciones
	if (t < 500) {						// si el tiempo es menor a 500 microsegundos el margen de error es demasiado grande
		ta = microsegundos();			// primera medicion
		for ( k = 0; k < CONST_K; k++) {		// hacemos k veces la inicialización del vector y la ordenación
			ascendente(v, n);
			ord_shell(v, n);
		}
		tb = microsegundos();			// segunda medición
		t1 = tb - ta;					// tiempo entre mediciones
		ta = microsegundos();			// primera medición
		for (k = 0; k < CONST_K; k++) {		// inicializa k veces el vector
			ascendente(v,n);
		}
		tb = microsegundos();			// segunda medición
		t2 = tb - ta;					// tiempo entre mediciones
		t = (t1 - t2)/CONST_K;			// tiempo medio de ejecución
	}

	return t;					// devolvemos el resultado
}


double time5(int n) {
	int v[n];
	double ta = 0, tb = 0, t1 = 0, t2 = 0, t;
	int k;

	descendente(v, n);					// genera un vector ascendente
	ta = microsegundos();				// primera medición
	ord_shell(v, n);						// ordenación del vector
	tb = microsegundos();				// segunda medición
	t = tb - ta;						// tiempo entre mediciones
	if (t < 500) {						// si el tiempo es menor a 500 microsegundos el margen de error es demasiado grande
		ta = microsegundos();			// primera medicion
		for (k = 0; k < CONST_K; k++) {		// hacemos k veces la inicialización del vector y la ordenación
			descendente(v, n);
			ord_shell(v, n);
		}
		tb = microsegundos();			// segunda medición
		t1 = tb - ta;					// tiempo entre mediciones
		ta = microsegundos();			// primera medición
		for (k = 0; k < CONST_K; k++) {		// inicializa k veces el vector
			descendente(v,n);
		}
		tb = microsegundos();			// segunda medición
		t2 = tb - ta;					// tiempo entre mediciones
		t = (t1 - t2)/CONST_K;			// tiempo medio de ejecución
	}

	return t;					// devolvemos el resultado
}


double time6(int n) {
	int v[n];
	double ta = 0, tb = 0, t1 = 0, t2 = 0, t;
	int k;

	aleatorio(v, n);					// genera un vector ascendente
	ta = microsegundos();				// primera medición
	ord_shell(v, n);						// ordenación del vector
	tb = microsegundos();				// segunda medición
	t = tb - ta;						// tiempo entre mediciones
	if (t < 500) {						// si el tiempo es menor a 500 microsegundos el margen de error es demasiado grande
		ta = microsegundos();			// primera medicion
		for (k = 0; k < CONST_K; k++) {		// hacemos k veces la inicialización del vector y la ordenación
			aleatorio(v, n);
			ord_shell(v, n);
		}
		tb = microsegundos();			// segunda medición
		t1 = tb - ta;					// tiempo entre mediciones
		ta = microsegundos();			// primera medición
		for (k = 0; k < CONST_K; k++) {		// inicializa k veces el vector
			aleatorio(v,n);
		}
		tb = microsegundos();			// segunda medición
		t2 = tb - ta;					// tiempo entre mediciones
		t = (t1 - t2)/CONST_K;			// tiempo medio de ejecución
	}

	return t;					// devolvemos el resultado
}