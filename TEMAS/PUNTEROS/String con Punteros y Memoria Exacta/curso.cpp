#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX_CAR_LIN 500
#define MAX_CUR 600
using namespace std;

/* Procedimiento que se encarga de crear un arreglo de palabras (**palabras)
   contenidos en una cadena (*linea) */
void separarPalabras(char *linea, char **palabras, int &nPal){

	nPal = 0;

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

/* Procedimiento que se encargará de obtener el codigo, credito y nombre con memoria exacta (*char) 
   a partir de una cadena linea */
void separarDatos(char linea[], char *&codigo, double &credito, char *&nombre){

	char *palabras[MAX_CAR_LIN];
	int nPal;

	separarPalabras(linea, palabras, nPal);

	codigo = new char[7];
	strcpy(codigo, palabras[0]);
	
	credito = atof(palabras[1]);

	char nombreAux[MAX_CAR_LIN];
	strcpy(nombreAux, palabras[2]);

	for (int i = 3; i < nPal; i++){
		strcat(nombreAux, " ");
		strcat(nombreAux, palabras[i]);
	}

	nombre = new char[strlen(nombreAux) + 1];
	strcpy(nombre, nombreAux);

}

/* Obtenemos la memoria exacta para un arreglo dinamico de numeros reales (*double) */
double *memoriaExacta(double* credCursoAux, int numCursos){
    
    double *credCurso = new double[numCursos + 1];
    
    for (int i = 0; i < numCursos; i++){
        credCurso[i] = credCursoAux[i];
    }
    
    credCurso[numCursos] = -1; /* NULL */
    
    return credCurso;
    
}


/* Obtenemos la memoria exacta para un arreglo dinamico de cadenas (**char) */
char **memoriaExacta(char** arrCarAux, int numCursos){
    
    char **arrCar = new char*[numCursos+1];
    
    for (int i = 0; i < numCursos; i++){
        arrCar[i] = arrCarAux[i];
    }
    
    arrCar[numCursos] = 0;
    
    return arrCar;
    
}


void leerCursos(char **&codCurso, double *&credCurso, char **&nombCurso){

	char linea[MAX_CAR_LIN];

	char *codigo;
	double credito;
	char *nombre;

	char *codCursoAux[MAX_CUR];
	double credCursoAux[MAX_CUR];
	char *nombCursoAux[MAX_CUR];

	int numCursos = 0;

    /* Leemos cada linea del archivo de texto */
	while (cin.getline(linea, MAX_CAR_LIN,'\n')){

        /* Obtenemos el codigo, credito y nombre con memoria exacta */
		separarDatos(linea, codigo, credito, nombre);

        /* Guardamos los valores en un arreglo estatico auxiliar */
		codCursoAux[numCursos] = codigo;
		credCursoAux[numCursos] = credito;
		nombCursoAux[numCursos] = nombre;

		numCursos++;

	}

    /* Asignamos a cada campo leido del arreglo estatico a un arreglo dinamico */ 
    credCurso = memoriaExacta(credCursoAux, numCursos);
    codCurso = memoriaExacta(codCursoAux, numCursos);
    nombCurso = memoriaExacta(nombCursoAux, numCursos);

}

void imprimeCursos(char **codCurso, double *credCurso, char **nombCurso){
    
    while (*credCurso != -1){
    
        cout << "Codigo: " << *codCurso << " Creditos: " << *credCurso << " Nombre del Curso: " << *nombCurso << endl;
    
        codCurso++;
        credCurso++;
        nombCurso++;
        
    }
    
}
