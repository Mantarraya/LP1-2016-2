#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;

#define MAX_CAR_LINEA 1000
#define MAX_CURSOS 1500
#define MAX_PAL 1000
#define MAX_ALUMNOS 1500
#define INCREMENTO 5

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


void obtenerDatosCurso(char linea[], char *&codCurso, char *&nombCurso, double &credCurso){
	
	
	char *palabras[MAX_PAL];
	int nPal;
	
	/* Guardamos todas las palabras de la linea en un arreglo de cadenas palabras */
	separarPalabras(linea, palabras, nPal);
	
	/* Extraemos cada palabra del arreglo de cadenas y separamos memoria */
	
	/* Codigo del curso */
	codCurso = new char[strlen(palabras[0]) + 1];
	strcpy(codCurso, palabras[0]);
	
	
	/* Credito del curso */
	credCurso = atof(palabras[nPal-1]);
	
	
	/* Nombre del curso */
	char auxNomb[500];
	strcpy(auxNomb, palabras[1]);
	for (int i = 2; i < nPal-1; i++){
		strcat(auxNomb, " ");
		strcat(auxNomb, palabras[i]);
	}	
	nombCurso = new char[strlen(auxNomb) + 1];
	strcpy(nombCurso, auxNomb);
	
}

void *colocarDatosCurso(char *codCurso, char *nombCurso, double credCurso){
	
	void **regCurso = new void*[3];
	
	/* Casteamos el credito del curso */
	double *ptrCredCurso = new double;
	*ptrCredCurso = credCurso;	
	
	/* Asignamos los valores al registro del curso */
	regCurso[0] = codCurso;
	regCurso[1] = nombCurso;
	regCurso[2] = ptrCredCurso;
	
	return regCurso;
	
}

void *memoriaExacta(void *auxCursos[], int numCursos){
	
	void **cursos = new void*[numCursos + 1];
	
	for (int i = 0; i < numCursos; i++)
		cursos[i] = auxCursos[i];
	
	cursos[numCursos] = NULL;
	
	return cursos;	
	
}
	

	
	
	
	
	
	
	
	
	
	


void obtenerDatosAlumno(char linea[], char *&nombAlumno, int &codEspecialidad){
	
	
	char *palabras[MAX_PAL];
	int nPal;
	
	/* Guardamos todas las palabras de la linea en un arreglo de cadenas palabras */
	separarPalabras(linea, palabras, nPal);
	
	/* Extraemos cada palabra del arreglo de cadenas y separamos memoria */
	
	/* Codigo de especialidad */
	codEspecialidad = atoi(palabras[nPal-1]);
	
	/* Nombre del curso */
	char auxNomb[500];
	strcpy(auxNomb, palabras[0]);
	for (int i = 1; i < nPal-1; i++){
		strcat(auxNomb, " ");
		strcat(auxNomb, palabras[i]);
	}	
	nombAlumno = new char[strlen(auxNomb) + 1];
	strcpy(nombAlumno, auxNomb);
	
}	
	
	
	
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
int leerCursos(void *&cursos){
	
	
	char linea[MAX_CAR_LINEA];
	
	/* Almacenaremos el primer codigo del alumno leido */
	int codAlumno; 
	
	/* Declaramos un puntero void auxiliar para almacenar los datos temporalmente */
	void *auxCursos[MAX_CURSOS];
	
	/* Datos del curso leido en cada linea */
	char *codCurso, *nombCurso;
	double credCurso;
	
	int numCursos = 0;
	
	while (scanf("%d", &codAlumno) == 0){
		
		cin.getline(linea, MAX_CAR_LINEA, '\n');
	
		obtenerDatosCurso(linea, codCurso, nombCurso, credCurso);
	
		auxCursos[numCursos] = colocarDatosCurso(codCurso, nombCurso, credCurso);
	
		numCursos++;		
	
	}
	
	/* Reservamos espacio de memoria para el puntero a void cursos */
	cursos = memoriaExacta(auxCursos, numCursos);

	return codAlumno;
	
}

void imprimirCursos(void *cursos){
	
	void **arrCursos = (void **) cursos;
	
	int cont = 0;
	
	printf("CURSOS: \n");
	printf("%-15s %-60s %-10s\n", "CODIGO CURSO", "NOMBRE CURSO", "CREDITOS CURSO");
	
	while (arrCursos[cont] != NULL){
		
		void **regCurso = (void **)arrCursos[cont];
		
		printf("%-15s %-60s %-10.1lf\n", (char *)regCurso[0], (char *)regCurso[1], *(double *)regCurso[2]);		
	
		cont++;
	
	}
		
}


void imprimirAlumnos(void *cursos){
	
	void **arrCursos = (void **) cursos;
	
	int cont = 0;
	
	printf("ALUMNOS: \n");
	printf("%-15s %-60s %-10s\n", "CODIGO ALUMNO", "NOMBRE ALUMNO", "COD ESPECILIDAD");
	
	while (arrCursos[cont] != NULL){
		
		void **regCurso = (void **)arrCursos[cont];
		
		printf("%-15d %-60s %-10d\n", *(int *)regCurso[0], (char *)regCurso[1], *(int *)regCurso[2]);		
	
		cont++;
	
	}
		
}



void *colocarDatosAlumno(int codAlumno, char *nombAlumno, int codEspecialidad){
	
	void **regAlumno = new void*[4];
	
	/* Casteamos el codigo del alumno */
	int *ptrCodAlumno = new int;
	*ptrCodAlumno = codAlumno;	
	
	/* Casteamos el codigo de la especialidad */
	int *ptrCodEspecialidad = new int;
	*ptrCodEspecialidad = codEspecialidad;
	
	/* Asignamos los valores al registro del curso */
	regAlumno[0] = ptrCodAlumno;
	regAlumno[1] = nombAlumno;
	regAlumno[2] = ptrCodEspecialidad;
	regAlumno[3] = NULL;
	
	return regAlumno;
	
}

void leerAlumnos(void *&alumnos, int codAlumno){
	
	char linea[MAX_CAR_LINEA];
	
	/* Declaramos un puntero void auxiliar para almacenar los datos temporalmente */
	void *auxAlumnos[MAX_ALUMNOS];
	
	/* Datos del curso leido en cada linea */
	char *nombAlumno;
	int codEspecialidad;
	
	int numAlumnos = 0;
	
	
	
	do{
		
		cin.getline(linea, MAX_CAR_LINEA, '\n');
	
		obtenerDatosAlumno(linea, nombAlumno, codEspecialidad);
	
		auxAlumnos[numAlumnos] = colocarDatosAlumno(codAlumno, nombAlumno, codEspecialidad);
	
		numAlumnos++;		
	
	}while (scanf("%d", &codAlumno) == 1);
	
	/* Reservamos espacio de memoria para el puntero a void cursos */
	alumnos = memoriaExacta(auxAlumnos, numAlumnos);	
	
}


void leerDatos(void *&cursos, void *&alumnos){
	
	
	/* Leeremos los datos de los cursos y lo almacenaremos en el puntero void *cursos */
	/* Devolvemos el primer codigo de alumnos del 2do bloque */
	int codAlumno = leerCursos(cursos);
	
	leerAlumnos(alumnos, codAlumno);
	

}


int leerNotas(){
	
	char c = cin.peek();
	
	if (c >= 'A' and c <= 'Z')
		return 1;
	
	return 0;
	
}

void obtenerDatosNotas(char linea[], char *&codCurso, int &codAlumno, int &nota){
	
	char *palabras[MAX_PAL];
	int nPal;
	
	separarPalabras(linea, palabras, nPal);
	
	/* Codico del curso */
	codCurso = new char[strlen(palabras[0]) + 1];
	strcpy(codCurso, palabras[0]);
	
	/* Codigo del alumno */
	codAlumno = atoi(palabras[1]);
	
	/* Nota */
	nota = atoi(palabras[nPal-1]);
	
	
}

int buscarPosAlumno(void **arrAlumnos, int codAlumnoBusc){
	
	int cont = 0;
	
	while (arrAlumnos[cont] != NULL){
		
		void **regAlumno = (void **) arrAlumnos[cont];
		
		if ( *(int *) regAlumno[0] == codAlumnoBusc )
			return cont;
		
		cont++;
	
	}
	
	return -1;
	
}

void insertarPrimeraNota(void *&alumno, char *codCurso, int nota){
	
	void **regAlumno = new void*[6];
	
	void **auxReg = (void **) alumno;
	
	for (int i = 0; i < 3; i++)
		regAlumno[i] = auxReg[i];
	
	
	char **arrCodCursos = new char*[5];
	int *arrNotas = new int[5];
	int *cantidades = new int[2];
	
	arrCodCursos[0] = codCurso;
	arrNotas[0] = nota;
	cantidades[0] = INCREMENTO;
	cantidades[1] = 1;
	
	regAlumno[3] = arrCodCursos;
	regAlumno[4] = arrNotas;
	regAlumno[5] = cantidades;
	
	alumno = regAlumno;
	
}

int buscarPosCurso(char **arrCodCursos, int n, char *codCursoBusc){
	
	for (int pos = 0; pos < n; pos++){
		
		if (strcmp(arrCodCursos[pos], codCursoBusc) == 0)
			return pos;
		
	}	
	
	return -1;	
	
}

void insertarNotaYCurso(void *&alumno, char *codCurso, int nota){
	
	void **regAlumno = (void **) alumno;
	
	char **arrCodCursos = (char **) regAlumno[3];
	int *arrNotas = (int *) regAlumno[4];
	int *cantidades = (int *) regAlumno[5];
		
	arrCodCursos[cantidades[1]] = codCurso;
	arrNotas[cantidades[1]] = nota;
	cantidades[1] += 1;
					
	regAlumno[3] = arrCodCursos;
	regAlumno[4] = arrNotas;
	regAlumno[5] = cantidades;
	
	
	alumno = regAlumno;
	
}

void incrementarTamanio(void *&alumno, char *codCurso, int nota){
	
	void **regAlumno = (void **) alumno;
	
	int *cantidades = (int *) regAlumno[5];
	
	
	char **auxCodCursos = new char*[cantidades[0]+INCREMENTO+1];
	int *auxNotas = new int[cantidades[0]+INCREMENTO+1];
	
	char **arrCodCursos = (char **) regAlumno[3];
	int *arrNotas = (int *) regAlumno[4];
	
	for (int i = 0; i < cantidades[0]; i++){
		auxCodCursos[i] = arrCodCursos[i];
		auxNotas[i] = arrNotas[i];
	}
	
	cantidades[0] += INCREMENTO;
	
	delete [] arrCodCursos;
	delete [] arrNotas;
	
	regAlumno[3] = auxCodCursos;
	regAlumno[4] = auxNotas;
	regAlumno[5] = cantidades;
	
	alumno = regAlumno;
	
}


void insertarNotaYCursoAlAlumno(void *&alumno, char *codCurso, int nota){
	
	void **regAlumno = (void **) alumno;
	
	if (regAlumno[3] == NULL)
		insertarPrimeraNota(alumno, codCurso, nota);
	else{
		
		char **arrCodCursos = (char **) regAlumno[3];
		int *arrNotas = (int *) regAlumno[4];
		int *cantidades = (int *) regAlumno[5];
		
		if (cantidades[1] < cantidades[0])			
			insertarNotaYCurso(alumno, codCurso, nota);
		else {
			incrementarTamanio(alumno, codCurso, nota);
			insertarNotaYCurso(alumno, codCurso, nota);
		}
		
	}
	
	
	
}

void insertarNota(void *&alumnos, char *codCurso, int codAlumno, int nota){
	
	void **arrAlumnos = (void **) alumnos;
	
	/* Buscamos el codigo del alumno */
	int posAlumno;
	posAlumno = buscarPosAlumno(arrAlumnos, codAlumno);
	
	if (posAlumno == -1)
		return;
	
	insertarNotaYCursoAlAlumno(arrAlumnos[posAlumno], codCurso, nota);
	
}

void agregarNotas(void *&alumnos){
	
	char linea[MAX_CAR_LINEA];
	
	char *codCurso;
	int codAlumno, nota;	
	
	while (leerNotas() == 1){
		
		cin.getline(linea, MAX_CAR_LINEA, '\n');
		
		obtenerDatosNotas(linea, codCurso, codAlumno, nota);
		
		insertarNota(alumnos, codCurso, codAlumno, nota);
		
	}
	
	

}

void imprimirAlumnosNotas(void *alumnos){
	
	void **arrAlumnos = (void **) alumnos;
	
	int cont = 0;
	
	printf("ALUMNOS: \n");
	printf("%-15s %-60s %-10s\n", "CODIGO ALUMNO", "NOMBRE ALUMNO", "COD ESPECILIDAD");
	
	while (arrAlumnos[cont] != NULL){
		
		void **regAlumno = (void **)arrAlumnos[cont];
		
		printf("%-15d %-60s %-10d\n", *(int *)regAlumno[0], (char *)regAlumno[1], *(int *)regAlumno[2]);		
	
		if (regAlumno[3] != NULL){
			
	
			char **arrCodCursos = (char **)regAlumno[3];
			int *arrNotas = (int *)regAlumno[4];
			int *cantidades = (int *)regAlumno[5];
			
			printf("%30d %10d\n", cantidades[0], cantidades[1]);
			for (int i = 0; i < cantidades[1]; i++)
				printf("%30s %10d\n", arrCodCursos[i], arrNotas[i]);
		
		}
	
		cont++;
	
	}
	
	
}

void separacionDeEgresados(void *cursos, void *alumnos, void *&egresados){
	
}


