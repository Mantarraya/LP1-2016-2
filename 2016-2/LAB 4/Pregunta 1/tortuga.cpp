/* Tomairo Huamanraime Juan Junior
    20125870 */

#include <iostream>
#include <cstdio>
using namespace std;

void imprimir_tablero(int tablero[], int n){
	
	for (int i = 0; i < n*n; i++){
		
		if ( (i%n) == 0)
			cout << endl;
		
		cout << tablero[i] << " ";
		
	}
	
	cout << endl;
	
}

void limpiar_tablero(int tablero[], int n){
	
	for (int i = 0; i < n*n; i++)
		tablero[i] = 0;
	
}

int tortuga_y(int *tortuga, int tablero[], int n){
	
	int pos;
	
	pos = tortuga - tablero;
	
	
	pos = pos%n;
	
	return pos;
	
}

int tortuga_x(int *tortuga, int tablero[], int n){
	
	int pos;
	
	pos = tortuga - tablero;
	
	return (pos)/n;
	
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
	
	/* No dibujamos */
	if (pluma == 0)
		return;
	
	*tortuga = 1;	
	
}
int validar_movimiento(int *tortuga, int tablero[], int n, int orientacion, int distancia){
	
	int posX = tortuga_x(tortuga, tablero, n);
	
	int posY = tortuga_y(tortuga, tablero, n);
	
	if (orientacion == 0){
		
		if ((posY + distancia)  >= n)
			return 0;
		else
			return 1;	
		
	}
	else if (orientacion == 1){
		
		if ((posY - distancia)  >= 0)
			return 1;
		else
			return 0;	
		
	}
	else if (orientacion == 2){
		
		if ((posX + distancia)  >= n)
			return 0;
		else
			return 1;	
		
		
	}
	else if (orientacion == 3){
		
		if ((posX - distancia)  >= 0)
			return 1;
		else
			return 0;	
		
	}
	
	
}

void mover(int *&tortuga, int n, int pluma, int orientacion, int distancia){
	

	
	/* Validamos Movimiento 
	if (validar_movimiento(tortuga, tablero[], n, orientacion, distancia) == 0)
		return;
	
	*/
	
	/* Movemos tortuga */
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
	
	tortuga = &tablero[0];
	
}