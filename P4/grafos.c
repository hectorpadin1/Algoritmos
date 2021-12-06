/*
 * Práctica 4
 * Héctor Padín Torrente, Luis Cascón Padrón
 * hector.padin@udc.es, luis.cascon@udc.es
 * Grupo: 1.4
 */

 #include "grafos.h"


matriz crearMatriz(int n) {
    int i;
    matriz aux;

    if ((aux = malloc(n*sizeof(int *))) == NULL)
        return NULL;
    for (i=0; i<n; i++)
        if ((aux[i] = malloc(n*sizeof(int))) == NULL)
            return NULL;
    return aux;
}


void iniMatriz(matriz m, int n) {
    int i, j;

    for (i=0; i<n; i++)
        for (j=i+1; j<n; j++)
            m[i][j] = rand() % MAX_N + 1;
    for (i=0; i<n; i++)
        for (j=0; j<=i; j++)
        if (i==j)
            m[i][j] = 0;
        else
            m[i][j] = m[j][i];
}


void iniMatrizZ(matriz m, int n) {
    int i, j;
    for (i=0; i<n; i++)
        for (j=0; j<=i; j++)
        if (i==j)
            m[i][j] = 0;
        else
            m[i][j] = m[j][i];
}


void printMatriz(matriz m, int n) {
    int i, j;

    for (i=0; i<n; i++) {
        printf("\t|");
        for (j=0; j<n; j++)
            printf("%2d ", m[i][j]);
        printf("|\n");
    }
    printf("\n\n");
}


void liberarMatriz(matriz m, int n) {
    int i;
    
    for (i=0; i<n ;i++)
        free(m[i]);
    free(m);
}


void dijkstra(matriz grafo, matriz distancias, int tam) {
    int n, i, j, k, x, min, v = 0;
    int *noVisitados = malloc(tam*sizeof(int));    
    for (n = 0; n < tam; n++) {                                                                                         //|
        for (i = 0; i < tam; i++) {                                     //|                                             //|
            noVisitados[i] = 1;                                         //| O(n)                                        //|
            distancias[n][i] = grafo[n][i];                             //|                                             //|
        }                                                               //|                                             //|
        noVisitados[n] = 0;	                                            //|                                             //|
        for(j = 0; j < tam-1; j++){                                                             //|                     //|
        	min=CONST_K;                                                                        //|                     //|
	        for(x = 0; x < tam; x++){                                                           //|                     //|
	       		if(noVisitados[x] && distancias[n][x]<=min){                                    //|                     //|
	       			min=distancias[n][x];                                                       //|                     //|O(n^(3))
	       			v=x;                                                                        //|                     //|
	       		}                                                                               //| O(n^(2))            //|
	       	}                                                                                   //|                     //|
	       	noVisitados[v]=0;                                                                   //|                     //|
		    for(k = 0; k < tam; k++){                                            //|            //|                     //|
	         	if(distancias[n][k] > distancias[n][v] + grafo[v][k])            //|O(n)        //|                     //|
	    	        distancias[n][k] = distancias[n][v] + grafo[v][k];			 //|            //|                     //|
	     	}                                                                    //|            //|                     //|
 		}                                                                                       //|                     //|
	}	                                                                                                                //|
	free(noVisitados);
}