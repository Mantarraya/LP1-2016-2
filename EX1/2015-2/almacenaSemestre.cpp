#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define MAX_CAR_LIN 1000
#define MAX_PAL 1500
#define MAX_CURSOS 1500
#define INCREMENTO 5

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


void inicializarSemestre(void **&semestre){
	
	char **arrCodCursos = new char*[INCREMENTO+1];
	double *arrCredCursos = new double[INCREMENTO+1];
	int *arrNotas = new int[INCREMENTO+1];
	
	for (int i = 0; i <= INCREMENTO; i++){
		arrCodCursos[i] = NULL;
		arrCredCursos[i] = -1;
		arrNotas[i] = -1;		
	}
	
	semestre[0] = arrCodCursos;
	semestre[1] = arrCredCursos;
	semestre[2] = arrNotas;	
	
}

int calcularNumCursos(void **semestre){
	
	char **arrCodCursos = (char **) semestre[0];
	double *arrCredCursos = (double *) semestre[1];
	int *arrNotas = (int *) semestre[2];
	
	int cant = 0;
	while (arrNotas[cant] != -1)
		cant++;
	
	return cant;	
	
}



void aumentarTamanio(void **&semestre, int numCursos){
	
	
	char **arrCodCursos = (char **) semestre[0];
	double *arrCredCursos = (double *) semestre[1];
	int *arrNotas = (int *) semestre[2];
	
	char **auxArrCodCursos = new char*[numCursos+INCREMENTO+1];
	double *auxArrCredCursos = new double[numCursos+INCREMENTO+1];
	int *auxArrNotas = new int[numCursos+INCREMENTO+1];
	
	for (int i = 0; i < numCursos; i++){
		auxArrCodCursos[i] = arrCodCursos[i];
		auxArrCredCursos[i] = arrCredCursos[i];
		auxArrNotas[i] = arrNotas[i];		
	}
	
	for (int i = 0; i <= INCREMENTO; i++){
		auxArrCodCursos[numCursos+i] = NULL;
		auxArrCredCursos[numCursos+i] = -1;
		auxArrNotas[numCursos+i] = -1;
		
	}
	
	delete [] arrCodCursos;
	delete [] arrCredCursos;
	delete [] arrNotas;
	
	semestre[0] = auxArrCodCursos;
	semestre[1] = auxArrCredCursos;
	semestre[2] = auxArrNotas;
	
}

void insertarDatos(void **&semestre, int numCursos, char *codCurso, double credCurso, int notaCurso){
	
	char **arrCodCursos = (char **) semestre[0];
	double *arrCredCursos = (double *) semestre[1];
	int *arrNotas = (int *) semestre[2];
	
	arrCodCursos[numCursos] = codCurso;
	arrCredCursos[numCursos] = credCurso;
	arrNotas[numCursos] = notaCurso;
	
	semestre[0] = arrCodCursos;
	semestre[1] = arrCredCursos;
	semestre[2] = arrNotas;
	
}


void colocarDatosSemestre(void **&semestre, char *codCurso, double credCurso, int notaCurso){
	int numCursos;
	
	if (semestre[0] == NULL)
		inicializarSemestre(semestre);
		
	numCursos = calcularNumCursos(semestre);
	
	if (numCursos % 5 == 0 and numCursos != 0){
		aumentarTamanio(semestre, numCursos);
	}
	
	char *auxCodCurso = new char[strlen(codCurso) + 1];
	strcpy(auxCodCurso, codCurso);
	insertarDatos(semestre, numCursos, auxCodCurso, credCurso, notaCurso);
	
}
	


void *leerCursos(){
	
	char linea[MAX_CAR_LIN];
	char *palabras[MAX_PAL];
	int nPal;
	
	cin.getline(linea, MAX_CAR_LIN, '\n');
	
	separarPalabras(linea, palabras, nPal);

	void **semestre = new void*[3];
	for (int i = 0; i < 3; i++) semestre[i] = NULL;
	
	for (int i = 0; i < nPal; i++){
		
		colocarDatosSemestre(semestre ,palabras[i], atof(palabras[i+1]), atoi(palabras[i+2]));
		
		i++;
		i++;
		
	}	
	
	return semestre;
	
}

double promedio(void *semestreCurso){
	
	void **semestre = (void **) semestreCurso;
	
	double *arrCredCursos = (double *) semestre[1];
	int *arrNotas = (int *) semestre[2];

	int numCursos =  calcularNumCursos(semestre);
	
	double sumaCred = 0;
	double sumaCredXNota = 0;
	
	for (int i = 0; i < numCursos; i++){
		
		sumaCredXNota += arrCredCursos[i]*arrNotas[i]*1.0;
		sumaCred += arrCredCursos[i];
		
	}
	
	return sumaCredXNota*1.0/sumaCred;
	
	
}

