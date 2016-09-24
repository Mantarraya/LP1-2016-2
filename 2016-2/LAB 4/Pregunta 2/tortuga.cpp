#include <iostream>
using namespace std;

void imprimir_tablero(int tablero[], int n){
	
	cout << endl;
	
	for (int i = 0; i < n*n; i++){
		
		cout << tablero[i] << " ";

		if ( i%n == n-1)
			cout << endl;
		
	}
	
}

void limpiar_tablero(int tablero[], int n){
	
	for (int i = 0; i < n*n; i++)
		tablero[i] = 0;
	
}

int tortuga_x(int *tortuga, int tablero[], int n){
	
	int posAvanzadas = tortuga - tablero;
	
	int posX = posAvanzadas % n;
	
	return posX;
	
}

int tortuga_y(int *tortuga, int tablero[], int n){
	
	int posAvanzadas = tortuga - tablero;
	
	int posY = posAvanzadas/n;
	
	return posY;
	
}

int girar_tortuga(int orientacion, int sentido_giro){
	
	if (sentido_giro == 3){
		
		if (orientacion == 0)
			return 2;
		
		if (orientacion == 1)
			return 3;
		
		if (orientacion == 2)
			return 1;
		
		if (orientacion == 3)
			return 0;
		
	}
	else if (sentido_giro == 4){
		
		if (orientacion == 0)
			return 3;
		
		if (orientacion == 1)
			return 2;
		
		if (orientacion == 2)
			return 0;
		
		if (orientacion == 3)
			return 1;		
		
	}
	
}

void dibujar(int *&tortuga, int pluma){
	
	if (pluma == 1)
		*tortuga = 1;
		
}

int validar_movimiento(int *tortuga, int tablero[], int n, int orientacion, int distancia){
	
	/* Calculamos la posicion actual de la tortuga (posX, posY) */
	
	int posX = tortuga_x(tortuga, tablero, n);
	int posY = tortuga_y(tortuga, tablero, n);
	
	/* Verificamos que no salga de la "matriz" */
	
	if (orientacion == 0)
		
		return (posX + distancia >= n)? 0 : 1; 
		
	else if (orientacion == 1)
		
		return (posX - distancia >= 0)? 1 : 0;
		
	else if (orientacion == 2)
		
		return (posY + distancia >= n)? 0 : 1;
		
	else if (orientacion == 3)
		
		return (posY - distancia >= 0)? 1 : 0;
	
}

void mover(int *&tortuga, int n, int pluma, int orientacion, int distancia){
	
	/* Movemos tortuga, en caso la pluma este abajo(1) dibujamos */

	if (orientacion == 0){
		
		for (int i = 0; i < distancia; i++){
			
			if (pluma == 1)
				dibujar(tortuga, pluma); 
				
			tortuga++;
			
		}
		
	}
	else if (orientacion == 1){
		
		for (int i = 0; i < distancia; i++){
			
			if (pluma == 1)
				dibujar(tortuga, pluma); 
				
			tortuga--;
			
		}
		
		
	}
	else if (orientacion == 2){
		
		for (int i = 0; i < distancia; i++){
			
			if (pluma == 1)
				dibujar(tortuga, pluma); 
			
			tortuga += n;	
			
		}

		
	}
	else if (orientacion == 3){
		
		for (int i = 0; i < distancia; i++){
			
			if (pluma == 1)
			
				dibujar(tortuga, pluma); 
				
			tortuga -= n;
			
		}
		
	}
	
}

void reset_tortuga(int *&tortuga, int tablero[]){
	
	/* Colocamos a la tortuga en la posicion inicial del tablero */
	tortuga = &tablero[0];
	
}