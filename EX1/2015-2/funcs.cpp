#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define MAX_CAR_LIN 1000
#define MAX_PAL 1500
#define MAX_CURSOS 1500
#define INCREMENTO 5
#define MAX_ALUMNOS 2000

void *leerCursos();
double promedio(void *);


int calcularCantCiclos(int anioI, int cicloI, int anioF, int cicloF){
	
	int cont = 0;
	while (1){
		
		cont++;
		
		
		if (anioI == anioF and cicloI == cicloF)
			break;
		
		if (cicloI == 2){
			
			anioI++;
			cicloI = 1;
			
		}
		else{
			
			cicloI++;
			
		}
		
		
	}
	
	return cont;
	
	
}

void separarPalabrasA(char *linea, char **palabras, int &nPal){
	
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



void obtenerAnioYCiclo(int &anio, int &ciclo){
	
	char linea[MAX_CAR_LIN];
	char *palabras[MAX_PAL];
	int nPal;
	
	cin.getline(linea, MAX_CAR_LIN, '\n');
	
	
	
	separarPalabrasA(linea, palabras, nPal);
	
	anio = atoi(palabras[0]);
	ciclo = atoi(palabras[1]);	
	
}

void *colocarDatosAlumnos(char *nombAlumno, int cantCiclos,int anioI, int cicloI, int anioF, int cicloF){
	
	void **alumno = new void*[cantCiclos+3];
	
	int *semestreI = new int[2];
	semestreI[0] = anioI;
	semestreI[1] = cicloI;
	
	int *semestreF = new int[2];
	semestreF[0] = anioF;
	semestreF[1] = cicloF;
	
	
	alumno[0] = nombAlumno;
	alumno[1] = semestreI;
	alumno[2] = semestreF;
	
	for (int i = 0; i < cantCiclos; i++)
		alumno[3+i] = NULL;
	
	return alumno;
	
}


void colocarCiclosAlumno(void *&alumno, int cantCiclos){
	
	void **regAlumnos = (void **) alumno;
	
	for (int i = 0; i < cantCiclos; i++){
		
		regAlumnos[3+i] = leerCursos();
		
		
	}
	
}

void *memoriaExacta(void *arrAlumno[], int numAlumnos){
	
	void **alumnos = new void*[numAlumnos+1];

	for (int i = 0; i < numAlumnos; i++)
			alumnos[i] = arrAlumno[i];
		
	alumnos[numAlumnos] = NULL;
	
	return alumnos;
	
}

void leerAlumnos(void *&alumnos, int &anio, int &ciclo){
	
	
	char linea[MAX_CAR_LIN];
	
	char *nombAlumno;
	
	int anioI, anioF, cicloI, cicloF, anioAux, cicloAux, cantCiclos;

	void *arrAlumno[MAX_ALUMNOS];
	
	int numAlumnos = 0;
	
	obtenerAnioYCiclo(anio, ciclo);
	
	while (cin.getline(linea, MAX_CAR_LIN, '\n')){

		nombAlumno = new char[strlen(linea) + 1];
		strcpy(nombAlumno, linea);
		
		scanf("%d %d %d %d", &anioI, &cicloI, &anioF, &cicloF);
		getchar();
		
		cantCiclos = calcularCantCiclos(anioI, cicloI, anioF, cicloF);
		
		arrAlumno[numAlumnos] = colocarDatosAlumnos(nombAlumno, cantCiclos, anioI, cicloI, anioF, cicloF);
		
		colocarCiclosAlumno(arrAlumno[numAlumnos], cantCiclos);	
		
		
		numAlumnos++;		
		
	}
	
	alumnos = memoriaExacta(arrAlumno, numAlumnos);
	
}




int buscarPosCiclo(int anio, int ciclo, int anioI, int cicloI, int anioF, int cicloF){
	
	int cont = 3;
	while (1){
		
		
		if (anio == anioI and ciclo == cicloI)
			return cont;
		
		
		cont++;
		
		if (anioI == anioF and cicloI == cicloF)
			break;
		
		if (cicloI == 2){
			
			anioI++;
			cicloI = 1;
			
		}
		else{
			
			cicloI++;
			
		}
		
		
	}
	
	return -1;

	
}


void reporte(void *alumnos, int &anio, int &ciclo){

	void **arrAlumnos = (void **) alumnos;
	double prom;
	
	printf("SEMESTRE %4d %1d\n", anio, ciclo);
	for (int i = 0; i < 100; i++) printf("="); printf("\n");
	printf("Promedios ponderados obtenidos por los alumnos que cursaron ese semestre\n");
	for (int i = 0; i < 100; i++) printf("-"); printf("\n");
	printf("Nombre                                                        Promedio\n");
	for (int i = 0; i < 100; i++) printf("-"); printf("\n");
	
	
	for (int i = 0; arrAlumnos[i]; i++){
		
		void **regAlumno = (void **)arrAlumnos[i];
		
		char *nombAlumno = (char *) regAlumno[0];
		int *semestreI = (int *) regAlumno[1];
		int *semestreF = (int *) regAlumno[2];
		
		int posCiclo = buscarPosCiclo(anio, ciclo, semestreI[0], semestreI[1], semestreF[0], semestreF[1]);
		
		if (posCiclo != -1){
			prom = promedio(regAlumno[posCiclo]);
		
			printf("%-60s %6.2lf\n", (char *)regAlumno[0] ,prom);
		
		}
		
		
	}
	
}












