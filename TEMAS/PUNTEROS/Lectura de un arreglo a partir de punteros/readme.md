### LECTURA DE UN ARREGLO A PARTIR DE UN PUNTERO
La lectura de datos se almacenara en un espacio de memoria dinámica.
```cpp
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
```
Entrada:
```console 
0.0023
0.0241
0.2239
0.9024
0.7812
0.8701
0.8912
0.9911
0.1032
```
Salida:
```console 
Numero de datos: 9
0.0023 0.0241 0.2239 0.9024 0.7812 0.8701 0.8912 0.9911 0.1032 
```