/* Tomairo Huamanraime Juan Junior
    20125870 */

#ifndef TORTUGA_H
#define TORTUGA_H

void imprimir_tablero(int[], int);

void limpiar_tablero(int[], int);

int tortuga_y(int*, int[], int);

int tortuga_x(int*, int[], int);

int girar_tortuga(int, int);

void dibujar(int*&, int );

int validar_movimiento(int*, int[], int, int, int);

void mover(int*&, int, int, int, int);

void reset_tortuga(int*&, int[]);


#endif