#include <iostream>
#include <cstdio>
#include "tortuga.h"
#define N 7
using namespace std;

int main(){
	
	int tablero[N*N] = {};
	
	int *tortuga;
	int pluma = 1; /* abajo */
	int orientacion = 0; /* abajo */
	
	/* Inicializamos el puntero */
	tortuga = tablero;
	
	/* Tablero inicial */
	cout << "Tablero Inicial: " << endl; 
	imprimir_tablero(tablero, N);
	
	/* Posicion Inicial */
	cout << "Posicion Inicial (x, y): " << tortuga_x(tortuga, tablero, N) << " " << tortuga_y(tortuga, tablero, N)<< endl;

	if (validar_movimiento(tortuga, tablero, N, orientacion, 5) == 1){
		mover(tortuga, N, pluma, orientacion, 5);
		imprimir_tablero(tablero, N);
	}
	
	cout << "Posicion (x, y): " << tortuga_x(tortuga, tablero, N) << " " << tortuga_y(tortuga, tablero, N)<< endl;
	
	orientacion = girar_tortuga(orientacion, 3); /* derecha */
	
	if (validar_movimiento(tortuga, tablero, N, orientacion, 4) == 1){
		mover(tortuga, N, pluma, orientacion, 4);
		imprimir_tablero(tablero, N);
	}
	
	cout << "Posicion (x, y): " << tortuga_x(tortuga, tablero, N) << " " << tortuga_y(tortuga, tablero, N)<< endl;

	orientacion = girar_tortuga(orientacion, 3); /* derecha */

	if (validar_movimiento(tortuga, tablero, N, orientacion, 3) == 1){
		mover(tortuga, N, pluma, orientacion, 3);
		imprimir_tablero(tablero, N);
	}
	
	cout << "Posicion (x, y): " << tortuga_x(tortuga, tablero, N) << " " << tortuga_y(tortuga, tablero, N)<< endl;

	return 0;
}