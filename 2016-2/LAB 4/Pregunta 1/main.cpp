/* Tomairo Huamanraime Juan Junior
    20125870 */

#include <iostream>
#include <cstdio>
#include "tortuga.h"
#define N 5
using namespace std;
/* Programa Principal */

int main(){
	
	int tablero[N*N] = {};
	
	int *tortuga;
	int pluma = 1; /* abajo */
	int orientacion = 0; /* abajo */

	
	
	/* Inicializamos el puntero */
	tortuga = tablero;
	
	/* Tablero inicial */
	imprimir_tablero(tablero, N);
	
	
	/* Pos Inicial */
	cout << tortuga_x(tortuga, tablero, N) << " " << tortuga_y(tortuga, tablero, N)<< endl;

	dibujar(tortuga, pluma);
	
	imprimir_tablero(tablero, N);
	
	mover(tortuga, N, pluma, orientacion, 3);
	dibujar(tortuga, pluma);
	
	imprimir_tablero(tablero, N);
	
	
	
	return 0;
}