#include <iostream>
#include <cstdio>
#define N 20

using namespace std;

/* Funciones y Procedimientos de la libreria estatica tortuga.a */

void imprimir_tablero(int[], int);

void limpiar_tablero(int[], int);

int tortuga_y(int*, int[], int);

int tortuga_x(int*, int[], int);

int girar_tortuga(int, int);

void dibujar(int*&, int );

int validar_movimiento(int*, int[], int, int, int);

void mover(int*&, int, int, int, int);

void reset_tortuga(int*&, int[]);


/* Programa Principal */

int main(){
	
	int comando, distancia;
	
	int tablero[N*N] = {}; /* Inicializamos el arreglo con ceros */
	
	int *tortuga;
	int pluma = 1; /* abajo */
	int orientacion = 0; /* abajo */
	
	tortuga = tablero; /* Inicializamos el puntero */
	
	while (scanf("%d ", &comando) == 1){
		
		if (comando == 1)
			
			pluma = 0;		
			
		else if (comando == 2)
			
			pluma = 1;	
			
		else if (comando == 3)
			
			orientacion = girar_tortuga(orientacion, 3);
			
		else if (comando == 4)
			
			orientacion = girar_tortuga(orientacion, 4);
			
		else if (comando == 5){
			
			scanf("%d ", &distancia);
			
			if (validar_movimiento(tortuga, tablero, N, orientacion, distancia) == 1)
				mover(tortuga, N, pluma, orientacion, distancia);
			
		}
		else if (comando == 6)
			
			imprimir_tablero(tablero, N);
		
	}
	
	return 0;
	
}