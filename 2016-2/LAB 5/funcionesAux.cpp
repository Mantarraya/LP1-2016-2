#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

#define MAX_CAR_LIN 500
#define MAX_LIST_CAR 7
#define MAX_ALFABETO 26
#define MAX_PAL 1000

using namespace std;

void inicializarLetras(char *&letras){
    
    letras = new char[MAX_ALFABETO];
    
    for (int i = 'A'; i <= 'Z'; i++)
        letras[i-'A'] = i;
    
}

void inicializarPalabras(char ***&palabras){
    
    palabras = new char**[MAX_ALFABETO];
    
    for (int i = 0; i < MAX_ALFABETO; i++)
        palabras[i] = new char*[MAX_PAL];
        
    for (int i = 0; i < MAX_ALFABETO; i++)
        for (int j = 0; j < MAX_PAL; j++)
            palabras[i][j] = new char [MAX_CAR_LIN];
            
    for (int i = 0; i < MAX_ALFABETO; i++)
        for (int j = 0; j < MAX_PAL; j++)
            strcpy(palabras[i][j], "null");
        
}

void inicializarEnteros(int *&valoresEnteros){
    
    valoresEnteros = new int[MAX_PAL];
    
    for (int i = 0; i < MAX_PAL; i++)
        valoresEnteros[i] = -1;
    
}


void inicializarFlotantes(double *&valoresDePuntoFlotante){
    
    valoresDePuntoFlotante = new double[MAX_PAL];
    
    for (int i = 0; i < MAX_PAL; i++)
        valoresDePuntoFlotante[i] = -1;
    
}

void convertirMayuscula(char pal[]){
	
	for (int i = 0; i < strlen(pal); i++)
		pal[i] = toupper(pal[i]);		
		
}

int verificarTipo(char pal[]){
	
	/* Palabra */
	if (pal[0] >= 'A' and pal[0] <= 'Z')
		return 1;
	
	/* Numero Real */
	for (int i = 0; i < strlen(pal); i++){
		if (pal[i] == '.')
			return 3;
	}
	
	/* Numero Entero */
	return 2;
	
	
}

template <typename T>
void insertarOrdenado(T A[], int &cont, T num){

	int pos = cont;
	
	for (int i = 0; i < cont; i++)
		if (A[i] == num)
			return;
			
	while (pos > 0 and A[pos-1] >= num){
		
		A[pos] = A[pos-1];
		pos--;
	}
	
	A[pos] = num;
	cont++;
}
template void insertarOrdenado(double[], int&, double);
template void insertarOrdenado(int[], int&, int);

void insertarOrdenadoPalabra(char **ArrPal, int &contPal, char *pal){
	
	int pos = contPal;
	
	for (int i = 0; i < contPal; i++)
		if (strcmp(ArrPal[i], pal) == 0)
			return;
			
	while (pos > 0 and strcmp(ArrPal[pos-1], pal) > 0){
		
		strcpy(ArrPal[pos], ArrPal[pos-1]);

		pos--;
	}
	
	strcpy(ArrPal[pos], pal);

	contPal++;
	
}

void imprimirPalabras(char ***palabras){
	
	int cont;
	
	for (int i = 'A'; i < 'Z'; i++){
		
		if (strcmp(palabras[i-'A'][0], "null") != 0){
			
			printf("    %c\n", i);
			
			cont = 0;
			
			while (strcmp(palabras[i-'A'][cont], "null") != 0){
				
				printf("    %-20s", palabras[i-'A'][cont]);
				cont++;
				
				if (cont % 3 == 0)
					printf("\n");
				
			}
			
			if (cont % 3 != 0)
				printf("\n");
			
			
		}
		
	}
	
}

void imprimirEnteros(int *valoresEnteros){
	
	int cont = 0;
	while (valoresEnteros[cont] != -1){
		
		printf("    %10d", valoresEnteros[cont]);
		cont++;
		
		if (cont % 3 == 0)
			printf("\n");
		
	}
	
	if (cont % 3 != 0)
		printf("\n");
	
}

void imprimirFlotantes(double *valoresDePuntoFlotante){
	
	int cont = 0;
	while (valoresDePuntoFlotante[cont] != -1){
		
		printf("    %10.3lf", valoresDePuntoFlotante[cont]);
		cont++;
		
		if (cont % 3 == 0)
			printf("\n");
		
	}
	
	if (cont % 3 != 0)
		printf("\n");
	
}
