#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#define MAX_CAR_LIN 500
#define MAX_LIST_CAR 7
#define MAX_ALFABETO 28
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


void separarPalabras(char *linea, char **palabras, int &nPal){

	nPal = 0;

    if (strlen(linea) > 0){
    
    	if (!isblank(linea[0])){
    		palabras[0] = linea;
    		nPal++;
    	}
    
    	for (int i = 1; linea[i]; i++){
    
    		if (!isblank(linea[i]) and (isblank(linea[i-1]) or linea[i-1] == 0)){
    			palabras[nPal] = &linea[i];
    			nPal++;
    		}
    
    		if (!isblank(linea[i]) and isblank(linea[i+1])){
    			linea[i+1] = 0;
    			i++;
    		}
    	}

    }

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



void leerTexto(char *&letras, char ***&palabras, int *&valoresEnteros, double *&valoresDePuntoFlotante){
    
    char *palabrasLinea[MAX_CAR_LIN];
    char linea[MAX_CAR_LIN];
	
	char pal[MAX_CAR_LIN];
	
	int tipoCadena;
	int nValEnteros = 0, nValFlotantes = 0;
	
	int palabrasXLetra[MAX_ALFABETO] = {};

	while (scanf("%s", pal) == 1){

		convertirMayuscula(pal);

		tipoCadena = verificarTipo(pal);
		
		if (tipoCadena == 3){
			valoresDePuntoFlotante[nValFlotantes] = atof(pal);
			nValFlotantes++;			
		}
		else if (tipoCadena == 2){
			valoresEnteros[nValEnteros] = atoi(pal);
			nValEnteros++;
		}
		else if (tipoCadena == 1){
			
			char car = pal[0];
			//palabras[car-'A'][palabrasXLetra[car-'A']] = pal;
			strcpy(palabras[car-'A'][palabrasXLetra[car-'A']] , pal);
			palabrasXLetra[car-'A'] += 1;
			
		}
		
	}
	
	
	sort(valoresEnteros, valoresEnteros + nValEnteros);
	unique(valoresEnteros, valoresEnteros + nValEnteros);
	
	sort(valoresDePuntoFlotante, valoresDePuntoFlotante + nValFlotantes);
	unique(valoresDePuntoFlotante, valoresDePuntoFlotante + nValFlotantes);
	
	/*
	
	for (int i = 0; i < 28; i++){
		
		cout << char('A' + i) << ".-";
	
		sort(palabras[i], palabras[i] + palabrasXLetra[i]);
	
		for (int j = 0; j < palabrasXLetra[i]; j++){
			
			cout << palabras[i][j] << " ";
		}
		cout << endl;
		
	}
	
    */
	
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

void reporte(char *letras, char ***palabras, int *valoresEnteros, double *valoresDePuntoFlotante){
	
	int cont;
	
	printf("%50s\n", "DICCIONARIO");
 
	for (int i = 'A'; i < 'Z'; i++){
		
		if (strcmp(palabras[i-'A'][0], "null") != 0){
			
			printf("    %c\n", i);
			
			cont = 0;
			
			while (strcmp(palabras[i-'A'][cont], "null") != 0){
				
				printf("    %-20s", palabras[i-'A'][cont]);
				cont++;
				
				if (cont % 3 == 0)
					cout << endl;
					
				
				
				
			}
			
			if (cont % 3 != 0)
					cout << endl;
			
			
		}
		
	}
	
	printf("%19s\n", "VALORES ENTEROS");
	cont = 0;
	while (valoresEnteros[cont] != -1){
		
		printf("    %10d", valoresEnteros[cont]);
		cont++;
		
		if (cont % 3 == 0)
					cout << endl;
		
	}
	
	if (cont % 3 != 0)
					cout << endl;
				
	printf("%19s\n", "VALORES DE PUNTO FLOTANTE");
	cont = 0;
	while (valoresDePuntoFlotante[cont] != -1){
		
		printf("    %10.3lf", valoresDePuntoFlotante[cont]);
		cont++;
		
		if (cont % 3 == 0)
					cout << endl;
		
	}
	
	if (cont % 3 != 0)
					cout << endl;
    
}