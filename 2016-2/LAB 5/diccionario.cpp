#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "funcionesAux.h"

#define MAX_CAR_LIN 500
#define MAX_LIST_CAR 7
#define MAX_ALFABETO 26
#define MAX_PAL 1000

using namespace std;

void leerListaCar(char listaCarMayus[], char listaCarMinus[], int &nListaCar){
    
    nListaCar = 0;
    
    char linea[MAX_CAR_LIN];
    while (cin.getline(linea, MAX_CAR_LIN, '\n')){
       
		if (strlen(linea) != 4) break;
		
        listaCarMayus[nListaCar] = linea[0];
        listaCarMinus[nListaCar] = linea[3];
        
        nListaCar++;
    }
    
}

void leerTexto(char *&letras, char ***&palabras, int *&valoresEnteros, double *&valoresDePuntoFlotante){
    
    char *palabrasLinea[MAX_CAR_LIN];
    char linea[MAX_CAR_LIN];
	char pal[MAX_CAR_LIN];
	
	int tipoCadena;
	int nValEnteros = 0, nValFlotantes = 0;
	int palabrasXLetra[MAX_ALFABETO] = {};

	/* Leemos cada palabra del texto y lo asignamos al respectivo campo que pertenece (palabras, enteros, reales) */
	while (scanf("%s", pal) == 1){

		convertirMayuscula(pal);

		/* 1: palabra, 2: entero, 3: real */
		tipoCadena = verificarTipo(pal);
		
		/* Insertamos ordenado y eliminamos los items repetidos */
		if (tipoCadena == 3)			
			insertarOrdenado(valoresDePuntoFlotante, nValFlotantes, atof(pal));

		else if (tipoCadena == 2)			
			insertarOrdenado(valoresEnteros, nValEnteros, atoi(pal));

		else if (tipoCadena == 1){
			
			char car = pal[0];
			insertarOrdenadoPalabra(palabras[car-'A'], palabrasXLetra[car-'A'], pal);

		}
		
	}
	
}

void reporte(char *letras, char ***palabras, int *valoresEnteros, double *valoresDePuntoFlotante){
	
	printf("%50s\n", "DICCIONARIO");	
	imprimirPalabras(palabras);
 
	printf("%19s\n", "VALORES ENTEROS");
	imprimirEnteros(valoresEnteros);
		
	printf("%29s\n", "VALORES DE PUNTO FLOTANTE");
	imprimirFlotantes(valoresDePuntoFlotante);
    
}

void crearDiccionario(char *&letras, char ***&palabras, int *&valoresEnteros, double *&valoresDePuntoFlotante){
    
    char listaCarMayus[MAX_LIST_CAR], listaCarMinus[MAX_LIST_CAR];
    int nListaCar;
    
    inicializarLetras(letras);
    inicializarPalabras(palabras);
    inicializarEnteros(valoresEnteros);
    inicializarFlotantes(valoresDePuntoFlotante);
    
    leerListaCar(listaCarMayus, listaCarMinus, nListaCar);
	
    leerTexto(letras, palabras, valoresEnteros, valoresDePuntoFlotante);
    
}
