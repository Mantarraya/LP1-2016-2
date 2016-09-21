#include <iostream>
#include <cstdio>
#define MAX 100
using namespace std;

int main(){

	/*Inicializamos el puntero con un espacio de memoria dinamico */
	double *ptr = new double[MAX];


	/* Guardamos la posicion inicial del puntero */
	double *posPtr;
	posPtr = ptr; 

	int nDatos = 0;

	while (scanf("%lf ", ptr) == 1){
		ptr++;
		nDatos++;
	}

	printf("Numero de datos: %d\n", nDatos);

	/* Imprimos los valores almacenados */
	for (int i = 0; i < nDatos; i++)
		printf("%5.4lf ", *(posPtr+i));
	printf("\n");

	return 0;
}
