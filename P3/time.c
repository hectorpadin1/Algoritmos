/*
 * Práctica 3
 * Héctor Padín Torrente,L uis Cascón Padrón
 * hector.padin@udc.es, luis.cascon@udc.es
 * Grupo: 1.4
 */

#include "time.h"

//Devuelve el tiempo que tarda en crearse el monticulo
double time_creat(int n, void (*inicializacion)(int[], int)) {
	int v[n];
	double ta = 0, tb = 0, t1 = 0, t2 = 0, t;
	int k;
	tMonticulo m;

	inicializarMonticulo(&m);
	(*inicializacion)(v, n);			// genera un vector
	ta = microsegundos();				// primera medición
	crearMonticulo(v,n,&m);					// creación del montículo
	tb = microsegundos();				// segunda medición
	t = tb - ta;						// tiempo entre mediciones
	if (t < 500) {						// si el tiempo es menor a 500 microsegundos el margen de error es demasiado grande
		ta = microsegundos();			// primera medicion
		for (k = 0; k < CONST_K; k++) {		// hacemos k veces la inicialización del vector y la creación del montículo
			(*inicializacion)(v, n);
			crearMonticulo(v,n,&m);
		}
		tb = microsegundos();			// segunda medición
		t1 = tb - ta;					// tiempo entre mediciones
		ta = microsegundos();			// primera medición
		for (k = 0; k < CONST_K; k++) {		// inicializa k veces el vector
			(*inicializacion)(v, n);
		}
		tb = microsegundos();			// segunda medición
		t2 = tb - ta;					// tiempo entre mediciones
		t = (t1 - t2)/CONST_K;			// tiempo medio de ejecución
	}

	return t;					// devolvemos el resultado
}

//Devuelve el tiempo que tarda en ordenar un monticulo
double time_ord(int n, void (*inicializacion)(int[], int)) {
	int v[n];
	double ta = 0, tb = 0, t1 = 0, t2 = 0, t;
	int k;

	(*inicializacion)(v, n);				// genera un vector
	ta = microsegundos();					// primera medición
	ordenacion_por_monticulos(v,n);			// ordenación del vector
	tb = microsegundos();					// segunda medición
	t = tb - ta;							// tiempo entre mediciones
	if (t < 500) {							// si el tiempo es menor a 500 microsegundos el margen de error es demasiado grande
		ta = microsegundos();				// primera medicion
		for (k = 0; k < CONST_K; k++) {			// hacemos k veces la inicialización del vector y la ordenación
			(*inicializacion)(v, n);
			ordenacion_por_monticulos(v,n);
		}
		tb = microsegundos();			// segunda medición
		t1 = tb - ta;					// tiempo entre mediciones
		ta = microsegundos();			// primera medición
		for (k = 0; k < CONST_K; k++) {		// inicializa k veces el vector
			(*inicializacion)(v, n);
		}
		tb = microsegundos();			// segunda medición
		t2 = tb - ta;					// tiempo entre mediciones
		t = (t1 - t2)/CONST_K;			// tiempo medio de ejecución
	}

	return t;					// devolvemos el resultado
}


void calentar(int n) {

	do {
		time_creat(n,&descendente);
		time_ord(n,&descendente);
		n+=n;
	} while (n <= MAX_N); 
}


void printTimeCrearMonticulo(int n, int i) {
	double d;

	do {
		if (i == AS)
			d = time_creat(n,&ascendente);
		else if (i == DES)
			d = time_creat(n,&descendente);
		else if (i == AL)
			d = time_creat(n,&aleatorio);
		else break;
		if (d < 500) {
			printf("%s%7d%16.3f%16.6f%16.6f%16.6f\n", "*",
				n, d, d/pow(n,0.8), d/n, d/pow(n,1.2));
		} else {
			printf("%8d%16.3f%16.6f%16.6f%16.6f\n",
				n, d, d/pow(n,0.8), d/n, d/pow(n,1.2));
		}
		n += n;
	} while (n <= MAX_N);	
}


void printTimeOrdMonticulo(int n, int i) {
	double d;

	do {
		if (i == AS)
			d = time_ord(n,&ascendente);
		else if (i == DES)
			d = time_ord(n,&descendente);
		else if (i == AL)
			d = time_ord(n,&aleatorio);
		else break;
		if (d < 500) {
			printf("%s%7d%16.3f%16.6f%16.6f%16.6f\n", "*",
				n, d, d/n, d/(n*log(n)), d/pow(n,1.5));
		} else {
			printf("%8d%16.3f%16.6f%16.6f%16.6f\n",
				n, d, d/n, d/(n*log(n)), d/pow(n,1.5));
		}
		n += n;
	} while (n <= MAX_N);	
}


void timeTable() {
	int n = 500;

	printf("\nPorfavor espere, calentando la maquina...\n");
	calentar(n);

	printf("\n\nCrear monticulos con inicializacion ascendente\n");
	printf("%8s%16s%16s%16s%16s\n",
		 "n","t(n)", "t(n)/n^(0,8)", "t(n)/n", "t(n)/n^(1,2)");
	printTimeCrearMonticulo(n,AS);
	printf("\n\nCrear monticulos con inicializacion descendente\n");
	printf("%8s%16s%16s%16s%16s\n",
		 "n","t(n)", "t(n)/n^(0,8)", "t(n)/n", "t(n)/n^(1,2)");
	printTimeCrearMonticulo(n,DES);
	printf("\n\nCrear monticulos con inicializacion aleatoria\n");
	printf("%8s%16s%16s%16s%16s\n",
		 "n","t(n)", "t(n)/n^(0,8)", "t(n)/n", "t(n)/n^(1,2)");
	printTimeCrearMonticulo(n,AL);


	printf("\n\nOrdenacion por monticulos con inicializacion ascendente\n");
	printf("%8s%16s%16s%16s%16s\n",
		 "n","t(n)", "t(n)/n", "t(n)/(n*log(n))", "t(n)/n^(1,5)");
	printTimeOrdMonticulo(n,AS);
	printf("\n\nOrdenacion por monticulos con inicializacion descendente\n");
	printf("%8s%16s%16s%16s%16s\n",
		 "n","t(n)", "t(n)/n", "t(n)/(n*log(n))", "t(n)/n^(1,5)");
	printTimeOrdMonticulo(n,DES);
	printf("\n\nOrdenacion por monticulos con inicializacion aleatoria\n");
	printf("%8s%16s%16s%16s%16s\n",
		 "n","t(n)", "t(n)/n", "t(n)/(n*log(n))", "t(n)/n^(1,5)");
	printTimeOrdMonticulo(n,AL);
}